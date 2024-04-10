#include <math.h>
#include <iostream>
#include <algorithm>
//#include <fstream>
#include <string>
#include <vector>
#define M_PI        3.14159265358979323846
using namespace std;
string st[100],stt;long q,i;
int main()
{//freopen("C://input.txt","r",stdin);freopen("C://output.txt","w",stdout);
st[1]="";
for (i=1;i<=97;i++)
st[1]+='0';
st[1]+="127";
st[2]="";
for (i=1;i<=95;i++)
st[2]+='0';
st[2]+="32767";
st[3]="";
for (i=1;i<=90;i++)
st[3]+='0';
st[3]+="2147483647";
st[4]="";
for (i=1;i<=81;i++)
st[4]+='0';
st[4]+="9223372036854775807";

cin>>stt;
while (stt.length()<100)stt="0"+stt;


q=1;
while (stt>st[q]&&q<5)q++;
if (q==1)cout<<"byte"<<endl;
if (q==2)cout<<"short"<<endl;
if (q==3)cout<<"int"<<endl;
if (q==4)cout<<"long"<<endl;
if (q==5)cout<<"BigInteger"<<endl;

cin.get();cin.get();
return 0;}