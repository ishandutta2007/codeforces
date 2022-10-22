#include <iostream>

using namespace std;
int sd(char x,char y)
{return  (int(x)-int ('0'))*10+int(y)-int ('0');

}
int main()
{
    ios::sync_with_stdio(0);
 string s;
 cin>>s;
 if(s.size()==4){s+='0';}
 int h=sd(s[1],s[0]);
 int m= sd(s[3],s[4]);
   if(h>=m&&h<60){cout<<h-m;return 0;}
   int h2= sd(s[0],s[1]);
   if(h2<5||(h2>9&&h2!=23&&(h2<15||h2>19))){cout<<60-m+h+10;return 0;}
if(h2==23){cout<<60-m;return  0;}
if(h2>=15){cout<<(19-h2)*60+(62-m);return 0;}
cout<<(9-h2)*60+(61-m);
    return 0;
}