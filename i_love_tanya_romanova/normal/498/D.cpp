/*
Round one, swear to God I do it for fun
Just a dead man walking with a double barrel shotgun
Ain't a single fucker left to fear
See their lips moving but I don't wanna hear

Showdown, I ain't backing down from anybody
Throw down, if I don't get some space
Lay down, not in this life or another
Deny me, if it's not your way

All I wanted was your honesty
Something more than this, something more than me
Death can take me if I can't be free
I'm not like you, I'm a dying breed

Round two, something you just don't wanna do
You're dancing with the devil if you wearing my shoes
You've got nerve and I'll give you that
Watch the world crumble while you sit on your ass

Wake up, get your head together motherfucker
Straight up before it's too late
Stand up, nothing ever lasts forever
Don't cry and that's how it's gonna stay

All I wanted was your honesty
Something more than this, something more than me
Death can take me if I can't be free
I'm not like you, I'm a dying breed

All I wanted was your honesty
Something more than this, more than me
Death can take me if I can't be free
I'm not like you, I'm a dying breed
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
#define bs 1000000009
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,ar[1<<20];
string st;
long b;

long t[1<<19][60];
long bad[100500][60];
long a;

void build(long v,long l,long r)
{
 if (l==r)
 {
  for (int i=0;i<60;i++)
  {
   if (bad[l][i])
    t[v][i]=2;
   else t[v][i]=1;  
  }
  return ;
 }
 long m=l+r;
 m/=2;
 build(v*2,l,m);
 build(v*2+1,m+1,r);
 long need,rem;
 for (int j=0;j<60;j++)
 {
  need=t[v*2][j];
  rem=need%60+j;
  if (rem>=60)rem-=60;
  need+=t[v*2+1][rem];
  t[v][j]=need;
 }
}

void update(long v,long l,long r,long ps,long val)
{
 if (l==r)
 {
  for (int i=0;i<60;i++)
  {
   if (bad[l][i])
    t[v][i]=2;
   else t[v][i]=1;  
  }
  return ;
 }
 long m=l+r;
 m/=2;
 if (ps<=m)
 update(v*2,l,m,ps,val);
 else
 update(v*2+1,m+1,r,ps,val);
 long need,rem;
 for (int j=0;j<60;j++)
 {
  need=t[v*2][j];
  rem=need%60+j;
  if (rem>=60)rem-=60;
  need+=t[v*2+1][rem];
  t[v][j]=need;
 }
}

long get(long v,long tl,long tr,long l,long r,long rem)
{
     if (l>r)return 0;
     if (tl==l&&tr==r)
     {
      return t[v][rem];
     }
     long tm=tl+tr;
     tm/=2;
     long res=0;
     if (l<=tm)
     {
      res+=get(v*2,tl,tm,l,min(r,tm),rem);
     }
     rem+=(res%60);
     if (rem>=60)rem-=60;
     if (r>tm)
     {
      res+=get(v*2+1,tm+1,tr,max(l,tm+1),r,rem);
     }
     return res;
}

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>ar[i];

for (int i=1;i<=n;i++)
{
 for (int j=0;j<60;j++)
  if (j%ar[i]==0)
   bad[i][j]=1;
   else bad[i][j]=0;
}

build(1,1,n);
long tests;
cin>>tests;
for (;tests;--tests)
{
 cin>>st;
 if (st=="A")
 {
  cin>>a>>b;
  --b;
  cout<<get(1,1,n,a,b,0)<<endl;
 }
 if (st=="C")
 {
  cin>>a>>b;
  ar[a]=b;
  for (int j=0;j<60;j++)
   if (j%ar[a]==0)
    bad[a][j]=1;
    else 
    bad[a][j]=0;
  update(1,1,n,a,b);
 }
}

cin.get();cin.get();
return 0;}