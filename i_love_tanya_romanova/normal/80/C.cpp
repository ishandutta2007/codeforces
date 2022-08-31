/*
So fucking what!

Well, I've been to Hastings and I've been to Brighton,
I've been to Eastbourne too.
So what, so what.
And I've been here, I've been there,
I've been every fucking where.
So what, so what.
So what, so what, you boring little cunt.

Well, who cares, who cares what you do.
Yeah, who cares, who cares about you, you, you, you, you.

Well, I fucked a queen, I fucked fuck,
I've even sucked an old man's cock.
So what, so what.
And I fucked a sheep, I fucked a goat,
I rammed my cock right down its throat.
So what, so what.
So what, so what, you boring little fuck.

Well, who cares, who cares what you do.
And, who cares, who cares about you, you, you, you, you.

And I've drunk that, I've drunk this,
I've spewed up on a pint of piss.
So what, so what.
I've had scank, I've had speed,
I've jacked up until I bleed.
So what, so what.
So what, so what, you boring little cunt.

Well, who cares, who cares what you do.
Yeah, who cares, who cares about you, you, you, you, you, you.

I've had crabs, I've had lice,
I've had the clap and that ain't nice.
So what, so what.
I fucked this, I fucked that,
I've even fucked a school girl's twat.
So what, so what.
So what, so what, you boring little fuck.

Well, who cares, who cares what you do.
And, who cares, who cares about you, you, you, you, you, you.

So fucking what! Yeah!
*/

#include <math.h>
#include <string>
#include <iostream>
#include<algorithm>
//#include <stdio.h>
//#include <fstream>
#define M_PI        3.14159265358979323846
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