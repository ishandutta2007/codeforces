/*
Feel like I'm stoned
I wanna be alone
Just for a while, unknown
Weeks on the road
A long way from home
Just shut off the phone

And you say I'll heal you
I'll always be yours
And you say I'll kill you
If I do something wrong
Yeah, yeah, yeah

Still feels like the first time
To stand here by your side
Together regardless
We'll walk through the darkness
Still feels like the first day of my life

Remember the times
Together we swore
To never give up this life
Still hanging on
Still going strong
Here I belong

And maybe I'm crazy
But I just can't slow down
And maybe I'm crazy
But at least I'm still around
Yeah, yeah, yeah

Still feels like the first time
To stand here by your side
Together regardless
We'll walk through the darkness
Still feels like the first day of my life

Feels like the first day of my life
Feels like the first time
Still feels like the first day of my life
Still feels like the first time
To stand here by your side

Together regardless
We'll walk through the darkness
Still feels like the first day of my
Still feels like the first day of my
Still feels like the first day of my life
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

using namespace std;

struct edge{long a,b,cap,flow;};
long n,s,t,d[200000],q[200000],ptr[200000];
vector<edge> e;
vector<long> g[200000];

void add_edge(long a,long b,long cap)
{
// cout<<"%"<<a<<" "<<b<<" "<<cap<<endl;
 edge e1={a,b,cap,0};
 edge e2={b,a,0,0};
 g[a].push_back(e.size());
 e.push_back(e1);
 g[b].push_back(e.size());
 e.push_back(e2);
}

bool bfs()
{
 long qh=0;
 long qt=1;
 q[0]=s;
 for (int i=0;i<=n;i++)
  d[i]=-1;
 d[s]=0;
 while (qh<qt&&d[t]==-1)
 {
  long v=q[qh];qh++;
  for (int i=0;i<g[v].size();i++)
  {
   long id=g[v][i];
   long to=e[id].b;
   if (d[to]==-1&&e[id].cap>e[id].flow)
    {
     q[qt]=to;++qt;
     d[to]=d[v]+1;
    }
  }
 }
 return d[t]!=-1;
}

long dfs(long v,long flow)
{
 //cout<<"%"<<v<<" "<<flow<<endl;
 if (flow==0||v==t)return flow;
 for (;ptr[v]<g[v].size();ptr[v]++)
 {
  long id=g[v][ptr[v]];
  long to=e[id].b;
  if (d[to]!=d[v]+1)continue;
  long pushed=dfs(to,min(flow,e[id].cap-e[id].flow));
  if (pushed)
  {
   e[id].flow+=pushed;
   e[id^1].flow-=pushed;
   return pushed;
  }
 }
 return 0;
}

long dinic()
{
 long flow=0;
 while (true)
 {
  if (!bfs())break;
//  cout<<d[t]<<endl;
  for (int i=0;i<=n;i++)
   ptr[i]=0;
   while (true)
   {
    long pushed=dfs(s,1e8);
//    cout<<pushed<<endl;
    if (pushed==0)break;
    flow+=pushed;
   }
 }
 return flow;
}

long start[200000],l[200000],r[200000];
long a[200000],b[200000],c[200000];
long m;

long eval(long x,long y)
{
 long res=a[x]*y*y+b[x]*y+c[x];
 return res;
}

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
cin>>a[i]>>b[i]>>c[i];
start[1]=1;
for (int i=1;i<=n;i++)
{
 cin>>l[i]>>r[i];
 add_edge(0,start[i],1e9);
 for (int j=l[i];j<=r[i];j++)
  add_edge(start[i]+j-l[i],start[i]+j-l[i]+1,1e6-eval(i,j));
 start[i+1]=start[i]+r[i]-l[i]+2;
  add_edge(start[i]+r[i]-l[i]+1,100000,1e9);
}
/*
for (int i=1;i<=n;i++)
cout<<start[i]<<" ";
cout<<endl;
*/
long p1,p2,d,tx,aa,bb;

for (;m;--m)
{
 cin>>p1>>p2>>d;
 for (int i=l[p1]-1;i<=r[p1];i++)
 {
  tx=i-d;
  if (tx>=l[p2]-1&&tx<=r[p2])
  {
   aa=start[p1]+i-l[p1]+1;
   bb=start[p2]+tx-l[p2]+1;
   add_edge(aa,bb,1e9);
  }
 }
 
}
long long res=1e6*n;
n=100001;
s=0;
t=100000;

//cout<<dinic()<<endl;
cout<<res-dinic()<<endl;


cin.get();cin.get();
return 0;}