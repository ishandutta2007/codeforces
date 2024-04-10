/*
I am your needle;
I am your option out of here, it's that simple
Oh, I can guide you,
Through all you fears you'll come out strong, come join me

So save me, I'm falling
And I don't have the strength to go on
I need this, I breathe this
So empty, afraid and alone

Well, we go way back
But now's the time to let it go, I dare you
Across the border something's waiting
Some kind of change, the kind silence

So save me, I'm falling
And I don't have the strength to go on
I need this, I breathe this
So empty, afraid and alone
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
#include <ctime>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
#define bsize 256
 
using namespace std;

long y,m,d,calc,p,t,v;
long mapp[3][100][100];
long tests,ans[200000],answ;
long l[200];

long g(long y,long m)
{
 if (m!=2)return l[m];
 if (y==2012)return 29;
 return 28;
}

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

for (int i=1;i<=12;i++)
l[i]=30;
l[1]=l[3]=l[5]=l[7]=l[8]=l[10]=l[12]=31;

y=2012;
m=1;
d=1;
while (y!=2014)
{
 mapp[y-2012][m][d]=calc;
 ++calc;
 ++d;
// cout<<y<<" "<<m<<" "<<d<<" "<<g(y,m)<<endl;
 if (d>g(y,m)){d=1;m++;if (m>12)m=1,++y;}
}

cin>>tests;
for (;tests;--tests)
{
 cin>>m>>d>>p>>t;
 v=mapp[1][m][d];
// cout<<v<<endl;
 for (int i=v-1;i>=v-t;i--)
 ans[i]+=p;
}
answ=0;
for(int i=1;i<=10000;i++)
answ=max(answ,ans[i]);
cout<<answ<<endl;

cin.get();cin.get();
return 0;}