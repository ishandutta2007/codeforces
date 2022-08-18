/*
You never see what's inside of me
That's why you won't face the truth
Fighting forever a fight you can't win
Touching my soul ain't like touching my skin

Open your mind, don't you ever slow down
Spread out your wings and reach out for the crown

It's not made out of gold, 'cause it's the crown of thorns
Not made for human soul
Ashes to ashes that's where it ends
Nobody could get more far beyond

Flying high I can see the years pass by
And I won't return to the same old places that I've been before
Is it still the same old face I can see no more?
Oh, see no more

Out in the gutter like a fox on the run
Everyone's after your dreams
So did you learn your lesson well?
If you did not they will send you to hell

Inside your heart you will never forget
How things went wrong and made you feel so sad
But the path is too small no one's gonna hear your call
As you wander by yourself

Ashes to ashes that's where it ends
Nobody could get more far beyond

Flying high I can see the years pass by
And I won't return to the same old places that I've been before
Is it still the same old face I can see no more?
Oh, see no more

Flying high I can see the years pass by
And I won't return to the same old places that I've been before
Is it still the same old face I can see no more?
Oh, see no more

Flying high I can see the years pass by
And I won't return to the same old places that I've been before
Is it still the same old face I can see no more?
Oh, see no more
Oh, see no more
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
#define MAGIC 47
#define count adsgasdgasdg

using namespace std;

long n,m,k,q,a,b;
vector<long> x[1<<20],y[1<<20];
long queries;
long x1[1<<20],y1[1<<20],x2[1<<20],y2[1<<20];
long t[1<<20];
vector<long> v1[1<<20],v2[1<<20];
long covered[1<<20];

void build(long v,long l,long r)
{
 if (l==r)
  {
   t[v]=-100;
   return ;
  }
  long m=l+r;
  m/=2;
  build(v*2,l,m);
  build(v*2+1,m+1,r);
  t[v]=-100;
}

long get(long v,long tl,long tr,long l,long r)
{
 if (l>r) return 1000000;
 if (l==tl&&r==tr) return t[v];
 long tm=tl+tr;
 tm/=2;
 long res1=get(v*2,tl,tm,l,min(r,tm));
 long res2=get(v*2+1,tm+1,tr,max(l,tm+1),r);
 return min(res1,res2);
}

void update(long v,long tl,long tr,long ps,long val)
{
 if (tl==tr)
 {
  t[v]=val;
  return;
 }
 long tm=tl+tr;
 tm/=2;
 if (ps<=tm)
  update(v*2,tl,tm,ps,val);
  else update(v*2+1,tm+1,tr,ps,val);
 t[v]=min(t[v*2],t[v*2+1]);
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k>>q;
for (int i=1;i<=k;i++)
{
 cin>>a>>b;
 x[a].push_back(b);
 y[b].push_back(a);
}

queries=q;

for (int i=1;i<=queries;i++)
{
 cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
 v1[x2[i]].push_back(i);
 v2[y2[i]].push_back(i);
}

build(1,1,200000);

for (int i=1;i<=n;i++)
{
 for (int j=0;j<x[i].size();j++)
 {
  long id=x[i][j];
  update(1,1,200000,id,i);
 }   
 for (int j=0;j<v1[i].size();j++)
 {
  long id=v1[i][j];
  long L,R;
  L=y1[id];
  R=y2[id];
  long res=get(1,1,200000,L,R);
  if (res>=x1[id])
   covered[id]=1;
 }
}

// Copy paste

build(1,1,200000);

for (int i=1;i<=m;i++)
{
 for (int j=0;j<y[i].size();j++)
 {
  long id=y[i][j];
  update(1,1,200000,id,i);
 }   
 for (int j=0;j<v2[i].size();j++)
 {
  long id=v2[i][j];
  long L,R;
  L=x1[id];
  R=x2[id];
  long res=get(1,1,200000,L,R);
  if (res>=y1[id])
   covered[id]=1;
 }
}

for (int i=1;i<=queries;i++)
if (covered[i])
puts("YES");
else puts("NO");

cin.get();cin.get();
return 0;}