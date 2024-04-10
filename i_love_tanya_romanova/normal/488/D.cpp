/*
So you found out today your life's not the same
Not quite as perfect as it was yesterday but
When you were just getting in the groove
Now you're faced with something new
And I know it hurts and I know you feel torn
But you never gave up this easily before
So why do you choose today to give it all away

Well, it's not so bad y'all together we all fall
Just as long we get up we'll stand tall
We shouldn't waste another day
Thinking 'bout the things that we forgot to say

I'm hittin' back y'all, kickin' these four walls
Just as hard as I can 'til I can't crawl
I won't waste another day
With all these silly things swimmin' in my brain

There's no giving up now
Do you really want to give this all away
Can't you ever see things in a different way
Some days, no giving up now

Such a beautiful thing to throw away
You should think things through
Over and over again
All over again

So your scars fade away, you're soaked up the pain
A better person 'cause you lived through those days
And now you know what it's like to prove
You can overcome anything that gets to you

Well it's alright, we're sayin' our goodbyes
To the past and everything that ain't right
We won't waste another day
With all these silly things in our way

There's no giving up now
Do you really want to give this all away
Can't you ever see things in a different way
Some days, no giving up now

Such a beautiful thing to throw away
You should think things through
Over and over again
All over again

I know we have given all that we can give
When there's nothing to lean on, well, I remember this
All we make of this lifetime is always here within
And remembering that's why we should never give in

There's no giving up now
Do you really want to give this all away
Can't you ever see things in a different way
Some days, no giving up now

Such a beautiful thing to throw away
You should think things through
Over and over again
All over again

There's no giving up now
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,l,s,ar[1<<20];
long tmin[1<<20],tmax[1<<20];

void build(long v,long tl,long tr)
{
 if (tl==tr)
 {
  tmin[v]=tmax[v]=ar[tl];
  return;
 }
 long tm=tl+tr;
 tm/=2;
 build(v*2,tl,tm);
 build(v*2+1,tm+1,tr);
 tmin[v]=min(tmin[v*2],tmin[v*2+1]);
 tmax[v]=max(tmax[v*2],tmax[v*2+1]);
}

pair<long, long> get(long v,long tl,long tr,long l,long r)
{
 if (l>r)
 {
  return make_pair(1000000000,-1000000000);
 }
 if (tl==l&&tr==r)
  return make_pair(tmin[v],tmax[v]);
 long tm=tl+tr;
 tm/=2;
 pair<long, long> p1,p2;
 p1=get(v*2,tl,tm,l,min(r,tm));
 p2=get(v*2+1,tm+1,tr,max(l,tm+1),r);
 p1.first=min(p1.first,p2.first);
 p1.second=max(p1.second,p2.second);
 return p1;
}

long dp[1<<20];
long T[1<<20];

long g1(long v,long tl,long tr,long l,long r)
{
 if (l>r)return 1e9;
 if (tl==l&&tr==r)
  return T[v];
 long tm=tl+tr;
 tm/=2;
 long p1,p2;
 p1=g1(v*2,tl,tm,l,min(r,tm));
 p2=g1(v*2+1,tm+1,tr,max(l,tm+1),r);
 return min(p1,p2);
}

void update(long v,long tl,long tr,long ps,long val)
{
 if (tl==tr)
 {
  T[v]=val;
  return;
 }
 long tm=tl+tr;
 tm/=2;
 if (ps<=tm)
  update(v*2,tl,tm,ps,val);
  else
  update(v*2+1,tm+1,tr,ps,val);
  T[v]=min(T[v*2],T[v*2+1]);
}

void bld(long v,long tl,long tr)
{
 if (tl==tr)
 {
  T[v]=dp[tl];
  return ;
 }
 long tm=tl+tr;
 tm/=2;
 bld(v*2,tl,tm);
 bld(v*2+1,tm+1,tr);
 T[v]=min(T[v*2],T[v*2+1]);
}

int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>s>>l;
for (int i=1;i<=n;i++)
 cin>>ar[i];

build(1,1,n);

for (int i=1;i<=n;i++)
 dp[i]=1e9;

bld(1,0,n);

pair<long, long> tp;

for (int i=1;i<=n;i++)
{
 if (i<l)continue;
 long a,b;
 
 a=1;
 b=i-l+1;
 while(a<b)
 {
  long m=a+b;
  m/=2;
  tp=get(1,1,n,m,i);
  if (tp.first+s<tp.second)
   a=m+1;
  else b=m;
 }
// cout<<a<<"   "<<i<<endl;
 
 tp=get(1,1,n,a,i);
// cout<<tp.first<<" ^ "<<tp.second<<endl;//<<"  "<<endl;
 if (tp.first+s<tp.second)continue;
 //cout<<"^"<<endl;
 long tv=g1(1,0,n,a-1,i-l);
// cout<<tv<<endl;
 update(1,0,n,i,tv+1);
}

long res=g1(1,0,n,n,n);
if (res>1e6)res=-1;

cout<<res<<endl;

cin.get();cin.get();
return 0;}