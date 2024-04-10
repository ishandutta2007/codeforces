/*  
And now I wait my whole lifetime
For you
And now I wait my whole lifetime
For you

I ride the dirt, I ride the tide
For you
I search the outside, search inside
For you

To take back what you left me
I know I'll always burn to be
The one who seeks so I may find
And now I wait my whole lifetime

My outlaw torn
My outlaw torn
And I'm torn

So on I wait my whole lifetime
For you
So on I wait my whole lifetime
For you

The more I search, the more my need
For you
The more I bless, the more I bleed
For you

You make me smash the clock and feel
I'd rather die behind the wheel
Time was never on my side
So on I wait my whole lifetime

My outlaw torn
My outlaw torn
My outlaw torn
And I'm torn

Hear me
And if close my mind in fear
Please pry it open
See me
And if my face becomes sincere
Beware
Hold me
And when I start to come undone
Stitch me together
Save me
And when you see me strut
Remind me of what left this outlaw torn
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
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
#define lr asgasgash

#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long ar[110][3],ar1[110][3],creach[110000];
long temp,ps,ps1,tspan,ta,tb;
long sg[200][5][5];
long n,m,a,b,q,bd[110][4];

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int span=1;span<=100;span++)
for (int tline=0;tline<=2;tline++)
for (int bline=0;bline<=2;bline++)
{
    for (int i=0;i<=span+3;i++)
    ar[i][1]=ar[i][2]=0;
    for (int i=0;i<=span+3;i++)
    ar1[i][1]=ar1[i][2]=0;
    
    if (tline==1)ar[1][1]=1;
    if (tline==2)ar[1][2]=1;
    if (bline==1)ar[span][1]=1;
    if (bline==2)ar[span][2]=1;
    
    for (int i=0;i<=200;i++)
    creach[i]=0;
    
    for (int a=1;a<=span;a++)
    for (int b=1;b<=2;b++)
    {
        for (int i=1;i<=span;i++)
            for(int j=1;j<=2;j++)
                ar1[i][j]=ar[i][j];
        if (ar1[a][b])continue;
        ar1[a][b]=1;
        ar1[a-1][3-b]=ar1[a][3-b]=ar1[a+1][3-b]=1;
        temp=0;
        ps=1;
        while (ps<=span)
        {
         while (ps<=span&&ar1[ps][1]+ar1[ps][2]==2)++ps;
         ps1=ps;
         while (ps1<=span&&ar1[ps1][1]+ar1[ps1][2]<2)++ps1;
         --ps1;
         if (ps>span)continue;
         tspan=ps1-ps+1;
         ta=tb=0;
         if (ar1[ps][1])ta=1;
         if (ar1[ps][2])ta=2;
         if (ar1[ps1][1])tb=1;
         if (ar1[ps1][2])tb=2;
         temp^=sg[tspan][ta][tb];
         ps=ps1+1;
        }
        creach[temp]=1;
    }
    q=0;
    while (creach[q])++q;
    sg[span][tline][bline]=q;
}

/*
for (int i=1;i<=10;i++)
cout<<sg[i][0][0]<<" "<<sg[i][0][1]<<" "<<sg[i][0][2]<<" "<<sg[i][1][0]<<" "<<
sg[i][1][1]<<" "<<sg[i][1][2]<<" "<<sg[i][2][0]<<" "<<sg[i][2][1]<<" "<<sg[i][2][2]<<endl;
*/


cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 bd[a][b]=1;
 bd[a-1][3-b]=1;
 bd[a][3-b]=1;
 bd[a+1][3-b]=1;   
}
long span=n;
for (int i=0;i<=span+5;i++)
ar1[i][1]=ar1[i][2]=0;

for (int i=1;i<=span;i++)
{
    ar1[i][1]=bd[i][1];ar1[i][2]=bd[i][2];
}
temp=0;ps=1;
 while (ps<=span)
        {
         while (ps<=span&&ar1[ps][1]+ar1[ps][2]==2)++ps;
         ps1=ps;
         while (ps1<=span&&ar1[ps1][1]+ar1[ps1][2]<2)++ps1;
         --ps1;
         if (ps>span)continue;
         tspan=ps1-ps+1;
         ta=tb=0;
         if (ar1[ps][1])ta=1;
         if (ar1[ps][2])ta=2;
         if (ar1[ps1][1])tb=1;
         if (ar1[ps1][2])tb=2;
      //   cout<<tspan<<" "<<ta<<" "<<tb<<" "<<ps<<" "<<ps1<<endl;
         temp^=sg[tspan][ta][tb];
         ps=ps1+1;
        }
// cout<<temp<<endl;
 if (temp)cout<<"WIN"<<endl;
 else cout<<"LOSE"<<endl;
 
cin.get();cin.get();
return 0;}