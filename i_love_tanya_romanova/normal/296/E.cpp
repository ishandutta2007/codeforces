/*
I can see how you are beautiful, can you feel my eyes on you,
I'm shy and turn my head away
Working late in diner Citylite, I see that you get home alright
Make sure that you can't see me, hoping you will see me

Sometimes I'm Wondering why you look me and you blink your eye
You can't be acting like my Dana
I see you in Citylite diner serving all those meals and then
I see reflection of me in your eye, oh please

Talk to me, show some pity
You touch me in many, many ways
But I'm shy can't you see

Obsessed by you, your looks, well, anyway "I would any day die for you",
I write on paper & erased away
Still I sit in diner Citylite, drinking coffee and reading lies
Turn my head and I can see you, could that really be you

Sometimes I'm wondering why you look me and you blink your eye
You can't be acting like my Dana?
I see your beautiful smile and I would like to run away from
Reflections of me in your eyes, oh please

Talk to me, show some pity
You touch me in many, many ways
But I'm shy can't you see

I see, can't have you, can't leave you there 'cos I must sometimes see you
But I don't understand how you can keep me in chains
And every waken hour, I feel your taking power From me and I can't leave
Repeating the scenery over again

Sometimes I'm wondering why you look me and you blink your eye
You can't be acting like my Dana?
I see your beautiful smile and I would like to run away from
Reflections of me in your eyes, oh please

Talk to me, show some pity
You touch me in many, many ways
But I'm shy can't you see
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
 
using namespace std;

long long n,k,c[240][240]; long long ways[240][60][60];
long long p,m1,m2,bmoves;
long reach[260][60][60];
long ml1,ml2; long long remm,add;
long fitt[100][100];
long long prec[51][51][51][51];

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
long long overfl=1000000000;
overfl*=overfl;
overfl*=7;

for (int i=0;i<=50;i++)
for (int j=0;j<=50;j++)
if (i*50+j*100<=k)
fitt[i][j]=1;

for (int i=0;i<=50;i++)
for (int j=0;j<=50;j++)
{
    if (j==0)
    c[i][j]=1;
    else c[i][j]=(c[i-1][j]+c[i-1][j-1])%bs;
}

for (int i=0;i<=50;i++)
for (int j=0;j<=i;j++)
for (int q=0;q<=50;q++)
for (int w=0;w<=q;w++)
{
    prec[i][j][q][w]=c[i][j]*c[q][w]%bs;
}

for (int i=1;i<=n;i++)
{
    cin>>p;
//if (i%2)p=50;
//else p=100;

    if (p==50)m1++;
    else m2++;
}

ways[0][m1][m2]=1;
reach[0][m1][m2]=1;

bmoves=100000;


for (long long moves=1;moves<=200;moves++)
{
    remm=moves%2;
    
    for (int l1=0;l1<=m1;l1++)
    for (int l2=0;l2<=m2;l2++)
    {
     if (reach[moves-1][l1][l2]==0)continue;
     
     if (remm==1)
     {ml1=l1;ml2=l2;}
     else{ml1=m1-l1;ml2=m2-l2;}
     
     for (int j=0;j<=ml2;j++)
     if (j*100<=k)
     for (int i=0;i<=ml1;i++)
     if (fitt[i][j])
     if (i+j>0)
     {
         add=prec[ml1][i][ml2][j];
         //c[ml1][i]*c[ml2][j]%bs;
         add*=ways[moves-1][l1][l2];
         
         if (remm==1)
         {reach[moves][l1-i][l2-j]=1;ways[moves][l1-i][l2-j]+=add;
         //while (ways[moves][l1-1][l2-j]>=bs)ways[moves][l1-i][l2-j]-=bs;
         if (ways[moves][l1-i][l2-j]>overfl)ways[moves][l1+i][l2+j]%=bs;}
         
         else
         {reach[moves][l1+i][l2+j]=1;ways[moves][l1+i][l2+j]+=add;
          if (ways[moves][l1+i][l2+j]>overfl)
          ways[moves][l1+i][l2+j]%=bs;
         //while(ways[moves][l1+i][l2+j]>=bs)ways[moves][l1+i][l2+j]-=bs;
         }
         
     } 
              
    }
    for (int i=0;i<=50;i++)
    for (int j=0;j<=50;j++)
    ways[moves][i][j]%=bs;
    
    if (reach[moves][0][0])bmoves=min(bmoves,moves);
    if (bmoves<1000)break;
}

if (bmoves>1000)cout<<-1<<endl<<0<<endl;
else {
cout<<bmoves<<endl;

cout<<ways[bmoves][0][0]<<endl;
}
cin.get();cin.get();
return 0;}