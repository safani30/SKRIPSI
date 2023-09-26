#include "CTBot.h"
CTBot myBot;

String ssid = "V";     // Sesuikan dengan nama wifi anda
String pass = "fanifani"; // sesuaikan password wifi
String token = "6330266189:AAGy7lFBY7sILaUp93bnETO5-g_YTBwovpw"; // token bot telegram yang telah dibuat

#define buzzer 12 //GPIO12 (D6)
#define Gas 14 //GPIO14 (D5)

void setup() {
  pinMode(Gas, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  myBot.wifiConnect(ssid, pass);

  myBot.setTelegramToken(token);

  // check if all things are ok
  if (myBot.testConnection())
    Serial.println("\n Terhubung");
  else
    Serial.println("\n Tidak Terhubung");
}
  
void loop() {
  int bacasensorgas = digitalRead(Gas);
  Serial.print("   Gas : ");
  Serial.println(bacasensorgas);
  if(bacasensorgas==0) //terdeteksi gas
  {
    String kirim;
    kirim ="Lapor Bos.! Ada Kebocoran Gas";
    myBot.sendMessage(1634912696, kirim); 
    digitalWrite(buzzer, HIGH);
    delay(1000); 
  }
  else
  {
    digitalWrite(buzzer, LOW);
    delay(1000);
  }
  delay(1000);
}