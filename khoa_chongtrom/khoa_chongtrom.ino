
#define BLYNK_TEMPLATE_ID "TMPL6lRgxHNaO"
#define BLYNK_TEMPLATE_NAME "KHOACUA"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
// Thông tin mạng Wi-Fi
char ssid[] = "for($pass=1;$pass<10;$pass++)";
char password[] = "123456789";

// Mã thông báo (auth token) của dự án Blynk
char auth[] = "2IXmDWqLEydJ-c6tCFGs7VX9Ta3jyXBc";

// Chân GPIO mà đèn LED được kết nối
int led = 12;
Servo sv;
void setup() {
  // Kết nối với mạng Wi-Fi
  /* WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  } */

  // Kết nối với Blynk
  Serial.begin(115200);
  Blynk.begin(auth, ssid, password);
  Serial.println("Connected to Blynk");

  // Thiết lập chân GPIO là đầu ra
  pinMode(led, OUTPUT);
  sv.setPeriodHertz(50);
  sv.attach(2, 0, 180);
}

void loop() {
  // Chạy Blynk để duy trì kết nối
  Blynk.run();
}

// Hàm được gọi khi giá trị nút trượt trên ứng dụng Blynk thay đổi
BLYNK_WRITE(V0) {
  int value = param.asInt();
  Serial.println(value);
  digitalWrite(led, value);
}

BLYNK_WRITE(V1)
{
  sv.write(90);
}