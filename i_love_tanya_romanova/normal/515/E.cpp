/*
Once upon a time I swore I had a heart
Long before the world I know tore it all apart
Once upon a time there was a part of me I shared
Years before they took away the part of me that cared

I've been a thousand places
And shook a million hands
I don't know where I'm going
But I know just where I've been

I've flown a million miles
And I've rode so many more
Every day, a castaway
A vagabond, battle born
I'm battle born

Once upon a time I had an open point of view
That was just so long ago before I had a clue
Was there such a time where I didn't stand alone?
Was there ever a time, and how would I have known?

I've been a thousand places
And shook a million hands
I don't know where I'm going
But I know just where I've been

I've flown a million miles
And I've rode so many more
Every day, a castaway
A vagabond, battle born

Attention all passengers, flight 555 now departing to Las Vegas to London
Please have your passports and boarding passes ready

I've been a thousand places
And shook a million hands
I don't know where I'm going
But I know just where I've been

I've flown a million miles
And I've rode so many more
Every day, a castaway
A vagabond, battle born

Been a thousand places
And shook a million hands (battle born)
I don't know where I'm going
But I know just where I've been (battle born)

I've flown a million miles
And I've rode so many more
Every day, a castaway
A vagabond, battle born
I'm battle born

I'm battle born

Every day, a castaway
A vagabond, battle born

Battle born
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

long n,m;
long d[1<<21];
long h[1<<21];
long long D[1<<21];
long l,r;
long long minn[1<<21],maxx[1<<21],ans[1<<21];

void build(long v,long tl,long tr)
{
 if (tl==tr)
 {
  minn[v]=2ll*h[tl]-D[tl];
  maxx[v]=2ll*h[tl]+D[tl];
  ans[v]=-1e9;
 //cout<<"^"<<v<<" "<<minn[v]<<" "<<maxx[v]<<" "<<tl<<endl;
  return;
 }
 long tm;
 tm=tl+tr;
 tm/=2;
 build(v*2,tl,tm);
 build(v*2+1,tm+1,tr);
 minn[v]=max(minn[v*2],minn[v*2+1]);
 maxx[v]=max(maxx[v*2],maxx[v*2+1]);
 ans[v]=max(ans[v*2],ans[v*2+1]);
 ans[v]=max(ans[v],maxx[v*2+1]+minn[v*2]);// merge
// cout<<v<<"   "<<tl<<" "<<tr<<" "<<ans[v]<<" "<<minn[v]<<" "<<maxx[v]<<endl;
}

pair<long long, pair<long long,long long> > get(long v,long tl,long tr,long l,long r)
{
 //cout<<v<<"  "<<tl<<" "<<tr<<" "<<l<<"  "<<r<<endl;
 
 pair<long long, pair<long long, long long> > res;
 if (l>r)
 {
  res.first=-1e18;
  res.second.first=-1e18;
  res.second.second=-1e18;
  return res;
 }
 
 if (tl==l&&tr==r)
 {
  res.first=ans[v];
  res.second.first=minn[v];
  res.second.second=maxx[v];
  return res;
 }
 long tm=tl+tr;
 tm/=2;
 pair<long long, pair<long long, long long> > p1,p2;
 p1=get(v*2,tl,tm,l,min(r,tm));
 p2=get(v*2+1,tm+1,tr,max(l,tm+1),r);
 res.second.first=max(p1.second.first,p2.second.first);
 res.second.second=max(p1.second.second,p2.second.second);
 res.first=max(p1.first,p2.first);
 res.first=max(res.first,p2.second.second+p1.second.first);
 return res;
}

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=0;i<n;i++)
{
 cin>>d[i];
}

for (int i=0;i<n;i++)
{
 cin>>h[i];
}

for (int i=0;i<n*2;i++)
d[i+n]=d[i],
h[i+n]=h[i];

D[0]=0;
for (int i=0;i<n*3;i++)
 D[i+1]=D[i]+d[i];
 
build(1,0,n*3-1);

for (;m;--m)
{
 cin>>l>>r;
 --l;
 --r;
 if (l<=r)// ok
 {
  long temp=r;
  r=l+n-1;
  l=temp+1;
 }
 else
 {
  long temp=l;
  //r+n;
  l=r+n+1;
  r=temp+n-1;
 // continue;
 }
// cout<<"^"<<l<<" "<<r<<endl;
 cout<<get(1,0,n*3-1,l,r).first<<endl;
}

cin.get();cin.get();
return 0;}