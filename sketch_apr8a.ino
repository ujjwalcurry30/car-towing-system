#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);
#define trigpin D7  
#define echopin D6


#define BUZZER D5 
  int duration, distance;
void setup() {
  Serial.begin(9600);
   WiFi.softAP("vigyanics", "123456789");
  Serial.println();
  Serial.println("vigyanics Started!");
  Serial.println(WiFi.softAPIP());
  server.begin();
  
  pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
 
  pinMode(BUZZER, OUTPUT);

 
  digitalWrite(BUZZER, LOW);

}
void loop() {
  digitalWrite(trigpin, LOW);
delayMicroseconds(5);
digitalWrite(trigpin, HIGH);
delayMicroseconds(15);
digitalWrite(trigpin, LOW);
pinMode(echopin, INPUT);
duration = pulseIn(echopin,HIGH);

distance = ( duration / 2) / 29.1;
Serial.println("cm:"); 
Serial.println(distance);
 WiFiClient client = server.available();
  
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");  // the connection will be closed after completion of the response
  client.println("Refresh: 5");  // update the page after 10 sec
  client.println();
 
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<h1 align=center>IOT BASED CAR ANTI-THEFT SYSTEM</h1><br><br>");
  
client.print("</p>");
client.println("</html>");

//delay(500);


 delay(500);
if (distance >5)
{
  digitalWrite(BUZZER,HIGH);
  delay(200);
  client.print("</p>");
client.println("</html>");
client.print("<p style='text-align: center;'><span style='color: #FF0000;'><strong style='font-size: large;'>car theft ");
}
else 
{
  digitalWrite(BUZZER,LOW);
  client.print("</p>");
  client.println("</html>");
  client.print("<p style='text-align: center;'><span style='color: #0000ff;'><strong style='font-size: large;'>car normal");
}
  
   }
