/*
Holes in the fabric of the soul
Like whispers from a rotting corpse
The cancer of your carelessness
Swimming so treacherous

The falling motionless into venture
If only I could transcend away

Into a place where all emotions fade away
Escape from an animated system of imperfections
The world runs empty of ways

I'm swimming through this nightmare
Where black waves pull me under

Black is the fuel running through this membrane
Frozen corpse eyes starring blind
Only smiling faces trapped in the grave
How long before this silence fades

I'm swimming through this nightmare
Where black waves pull me under

In another place where memories will fade
Choking underneath these waves
Why have you forsaken me
I can't see any future anymore

If I could just transcend away
Into a place where all emotions will fade

Transcend
Transcend

I'm swimming through this nightmare
Where black waves pull me under
*/

#pragma comment(linker, "/STACK:16777216")
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long temp,ans;
long cbits(long x)
{
 long r=0;
 for (int i=0;i<10;i++)
  if (x&(1<<i))++r;
 return r;
}

string zr;
long same;

long solve(char c)
{
 for(int i=0;i<zr.size();i++)
  if (zr[i]==c)return i;
}

long n;
string st;
long t1[2000],t2[2000];

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

zr="GRBYW";

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>st;
 t1[i]=solve(st[0]);
 t2[i]=st[1]-'1'+5;
}

ans=1e9;
for (int mask=0;mask<1024;mask++)
{
 temp=cbits(mask);
 if (temp>ans)continue;
 long er=0;
 for (int i=1;i<=n;i++)
  for (int j=i+1;j<=n;j++)
  {
   if (t1[i]==t1[j]&&t2[i]==t2[j])continue;
   same=1;
   if (t1[i]!=t1[j])
   {
    if (mask&(1<<t1[i]))same=0;
    if (mask&(1<<t1[j]))same=0;
   }
   if (t2[i]!=t2[j])
   {
    if (mask&(1<<t2[i]))same=0;
    if (mask&(1<<t2[j]))same=0;
   }
   if (same)er=1;
  }
 if (er==0)ans=min(ans,temp);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}