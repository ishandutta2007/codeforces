#include <math.h>
#include <string>
#include <iostream>
#include<algorithm>
//#include <stdio.h>
//#include <fstream>
#define M_PI		3.14159265358979323846
using namespace std;
string st1,st2,st3;
long i,n,anss,ans,e,arp[1000],r,ars,
ar[100][100],j,q,p1,p2,w,r1,r2,r3,a1,a2,a3,pn1,pn,answ,f;
int convert(string st)
{if (st[0]=='C')if (st[1]=='h')return 1;
else return 2;
if (st[0]=='A')return 3;
if (st[0]=='T')return 4;
if (st[0]=='D')return 5;
if (st[0]=='S')return 6;
if (st[0]=='H')return 7;
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;

for (i=1;i<=n;i++)
{cin>>st1>>st2>>st3;
 pn=convert(st1);pn1=convert(st3);
 ar[pn][pn1]=1;}
 
cin>>a1>>a2>>a3;
answ=2000000000;

for (i=1;i<=7;i++)
for (j=1;j<=7;j++)
for (q=1;q<=7;q++)
{r1=a1/i;r2=a2/j;r3=a3/q;
 f=0;
 f=max(f,abs(r1-r2));f=max(f,abs(r1-r3));
 f=max(f,abs(r2-r3));
 if (f<answ&&i+j+q==7)answ=f;
}


long ara[1000];
for (i=0;i<7;i++){ara[i]=i+1;}

while ( next_permutation(ara,ara+7))
{
      for (int i=1;i<=7;i++)
      for (int j=1;j<7-i;j++)
      {
          q=7-i-j;
      r1=a1/i;r2=a2/j;r3=a3/q;
       f=0;
 f=max(f,abs(r1-r2));f=max(f,abs(r1-r3));
 f=max(f,abs(r2-r3));
      if (f==answ){
                   ars=0;
       for(e=0;e<i;e++)arp[ara[e]]=1;
       for (e=i;e<i+j;e++)arp[ara[e]]=2;
       for (e=i+j;e<i+j+q;e++)arp[ara[e]]=3;
       
       for (e=1;e<=7;e++)for (r=1;r<=7;r++)
       if (arp[e]==arp[r]&&ar[e][r])ars++;
       
       }
       if (ars>anss)anss=ars;
      }
      
      
 }
      

cout<<answ<<" "<<anss<<endl;
cin.get();cin.get();
return 0;}