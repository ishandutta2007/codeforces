#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int main() {
     char b[10011] = "127";
     char s[10011] = "32767";
     char i[10011] = "2147483647";
     char l[10011] = "9223372036854775807";
     char x[10011];
     cin >> x;
     if ( strlen(x)<strlen(b)||strlen(x)==strlen(b)&& strcmp(x,b)<=0)
     cout<<"byte"<<endl;
     else if(strlen(x)<strlen(s)||strlen(x)==strlen(s)&&strcmp(x,s)<=0)
     cout<<"short"<<endl;
     else if(strlen(x)<strlen(i)||strlen(x)==strlen(i)&&strcmp(x,i)<=0)
     cout<<"int"<<endl;
     else if(strlen(x)<strlen(l)||strlen(x)==strlen(l)&&strcmp(x,l)<=0)
     cout<<"long"<<endl;
     else cout<<"BigInteger"<<endl;   
     return 0;
}