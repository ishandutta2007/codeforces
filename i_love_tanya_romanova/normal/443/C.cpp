/*
The stench of poison in the heat reflects
My sweet crystal myth
One day bleeds into the next

Into the next

When will the corrosion of emotion
Will happen this time
Can you feel it dropping?
In the depths of a comet's stomach
I travel with this hollow vessel

Spirals and shadows dancing in front
I relapse and inhale the dust

Well it's all just an organic illusion
You know what makes us breathe
Makes our heart beat
In the valve of the heart

You know it makes me bleed
I just meant you're alive

Spirals and shadows dancing in front
I relapse and inhale the dust

Somewhere somehow
Somewhere somehow

Spirals and shadows dancing in front
I relapse and inhale the dust
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