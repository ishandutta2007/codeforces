#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main()
{
    scanf("%d:%d\n%d:%d",&a,&b,&c,&d);
    int x=a*60+b,y=c*60+d;
    x=x+(y-x)/2;
    int xx=x/60,yy=x%60;
    string xxx=to_string(xx),yyy=to_string(yy);
    while(xxx.size()<2) xxx='0'+xxx;
    while(yyy.size()<2) yyy='0'+yyy;
    xxx=xxx+":"+yyy;
    cout<<xxx<<endl;
}