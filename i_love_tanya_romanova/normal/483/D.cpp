/*
Crying on the pyre, feelin' all so strange
Once you took my mind to deteriorate
Told me that you like me, atrocious and deterrent lies
You told me how, how to suffer hate

Celebrate my funeral, vultures on my corpse
Ashes to ashes, me to hell
You want to bury me alive but you never knew
You're too deaf to hear my forces yell

On your mind the creeping hate
You hold the link to seal my fate, I stare into the light
Fire burning brightly, inquisition in our time
But I'll tell you what I am

Burning like a frozen, oh
Burning like a frozen candle
Burning like a frozen, oh
Burning like a frozen candle

I can still remember you coming with the reaper
How you tried to unlock my door
Sleepless nights, evil dreams, faces in the window
Voices that I've never heard before

On your mind the creeping hate
You hold the link to seal my fate, I stare into the light
Fire burning brightly, inquisition in our time
But I'll tell you what I am

Burning like a frozen, oh
Burning like a frozen candle
Burning like a frozen, oh
Burning like a frozen candle

Burning like a frozen, oh
Burning like a frozen candle
Burning like a frozen, oh
Burning like a frozen candle

Burning like a frozen
Burning like a frozen candle
Burning like a frozen, oh
Burning like a frozen candle
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long n,m,a[1<<20],b[1<<20],val[1<<20],ad[1<<18][33];
long ttl[1<<20];
long v;
long ar[1<<20];
long er;
long t[1<<20];

void build(long v,long tl,long tr)
{
 if (tl==tr)
 {
  t[v]=ar[tl];
  return;
 }
 long tm=tl+tr;
 tm/=2;
 build(v*2,tl,tm);
 build(v*2+1,tm+1,tr);
 t[v]=(t[v*2]&t[v*2+1]);
// cout<<v<<" "<<tl<<" "<<tr<<"  "<<t[v]<<endl;
}

long get(long v,long tl,long tr,long l,long r)
{
 if (l>r)
  return ((1<<30)-1);
 if (tl==l&&tr==r)
  return t[v];
 long tm=tl+tr;
 tm/=2;
 long v1=get(v*2,tl,tm,l,min(r,tm));
 long v2=get(v*2+1,tm+1,tr,max(l,tm+1),r);
 return (v1&v2);
}

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=m;i++)
{
 cin>>a[i]>>b[i]>>val[i];
 
 for (int j=0;j<=30;j++)
  if (val[i]&(1<<j))
   ad[a[i]][j]++,
   ad[b[i]+1][j]--;
}

for (int i=1;i<=n;i++)
{
 for (int j=0;j<=30;j++) 
 ttl[j]+=ad[i][j];
 v=0;
 for (int j=0;j<=30;j++)
  if (ttl[j]) v+=(1<<j);
 ar[i]=v;
}

 
build(1,1,n);

er=0;
for (int i=1;i<=m;i++)
{
 //cout<<get(1,1,n,a[i],b[i])<<endl;
 if (get(1,1,n,a[i],b[i])!=val[i])
  er=1;
}
if (er)cout<<"NO"<<endl;
else
{
 cout<<"YES"<<endl;
 for (int i=1;i<=n;i++)
 {
  if (i>1)
  cout<<" ";
  cout<<ar[i];
 }
 cout<<endl;
}

cin.get();cin.get();
return 0;}