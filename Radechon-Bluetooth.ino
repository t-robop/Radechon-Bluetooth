#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11);

void setup(){
    BT.begin(9600);
    Serial.begin(38400);
  //右タイヤ
  pinMode(6,OUTPUT); //信号用ピン 5番ピン
  pinMode(7,OUTPUT); //信号用ピン 6番ピン
  //左タイヤ
  pinMode(8,OUTPUT); //信号用ピン 7番ピン
  pinMode(9,OUTPUT); //信号用ピン 8番ピン

}
String btString;
int MAX_BLUETOOTH_SIZE = 4;

void loop(){
  int n = BT.available();
  if ( n >= MAX_BLUETOOTH_SIZE ) {
    char ch[MAX_BLUETOOTH_SIZE];
    int i;
    // 4バイトずつ読み込む
    for ( i=0; i<MAX_BLUETOOTH_SIZE; i++) {
      ch[i] = BT.read();
    }
//    digitalWrite(6,HIGH);
//    digitalWrite(7,LOW);
//    //左タイヤ
//    digitalWrite(8,HIGH);
//    digitalWrite(9,LOW);
//    analogWrite(3,100);
//    analogWrite(5,100);
  moterControl(ch);
  //}
}
int RgihtVal = 140; //0~255の値にする
int LeftVal = 180; //0~255の値にする

void moterControl(String select){
  //Serial.print(select);
  //モーターの強さ指定
  
  // 前進
  if (select.equals("0001")){
    //Serial.print(val);
    //BT.println(val+"2 is comming.");
    //右タイヤ
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    //左タイヤ
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    analogWrite(3,LeftVal);
    analogWrite(5,RgihtVal);
    }
  
  else if (select.equals("0002")){
    //後退
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);  
    analogWrite(3,LeftVal);
    analogWrite(5,RgihtVal);

  }
  
  else if (select.equals("0003")){
      //左回転
    //右タイヤ
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    //左タイヤ
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    analogWrite(3,LeftVal);
    analogWrite(5,RgihtVal);
  }
  
  else if (select.equals("0004")){
    //右回転
    //右タイヤ
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    //左タイヤ
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    analogWrite(3,LeftVal);
    analogWrite(5,RgihtVal);
  }
  
  else if (select.equals("0005")){
      //ストップ
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    analogWrite(3,LeftVal);
    analogWrite(5,RgihtVal);
  }
}
