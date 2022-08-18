/*
Its haunting
This hole that you have over me
I grow so weak

I see you
And everything around you fades
And I cant see

You can never know what it is you do to me

I can't take what you do to me
I can't take it

I can't take what you do to me
I can't take it

No matter what I say or what I do
I know how this will end
So I turn it away now before we begin

And now matter what you say or what you do
I know how this will end
So I'm turning away now

I'm dangerous for you
I'm dangerous for you

You touch me
And I can barely make a move
And I can't breathe

You never know what it is you do to me

I can't take what you do to me
I can't take it

I can't take what you do to me
I can't take it

No matter what I say or what I do
I know how this will end
So I'm turning away now before we begin

And no matter what you say or what you do
I know how this will end
So I'm turning away now

I'm dangerous

The only promise I could make
Is that my promise is a lie
The only promise I could make you
Is that my promise is a lie

No matter what I say or what I do
I know how this will end
So I'm turning away now before we begin

And no matter what you say or what you do
I know how this will end
So I'm turning away now

I'm dangerous for you
I'm dangerous for you
I'm dangerous for you
I'm dangerous for you
I'm dangerous for you
I'm dangerous for you

I'm dangerous, I'm dangerous for you

My promise is I will hurt you
My promise is I will hurt you
My promise is I will hurt you
My promise is I will hurt you
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

long pr[1<<20];
long n,ar[1<<20];
vector<long> l,r;
long used[1<<20];
vector<long> comp;
vector<vector<long> > av;

struct edge{
      long a,b,cap,flow;
       };

long N,s,t,d[1<<20],ptr[1<<20],q[1<<20];
vector<edge> e;
vector<long> g[1<<20];
vector<long> G[1<<20];

void add_edge(long a,long b,long cap)
{
 edge e1={a,b,cap,0};
 edge e2={b,a,0,0};
 g[a].push_back(e.size());
 e.push_back(e1);
 g[b].push_back(e.size());
 e.push_back(e2);
}

bool bfs()
{
 q[0]=s;
 long qh,qt;
 qh=0;
 qt=1;
 for (int i=0;i<=N;i++)
  d[i]=-1;
 d[s]=0;
 
 while (qh<qt&&d[t]==-1)
 {
  long v=q[qh];
  ++qh;
  for (int i=0;i<g[v].size();i++)
  {
   long id=g[v][i];
   long to=e[id].b;
   if (d[to]==-1&&e[id].flow<e[id].cap)
   {
    q[qt]=to;
    ++qt;
    d[to]=d[v]+1;
   }
  }
 }
 return (d[t]!=-1); 
}

long dfs(long v,long flow)
{
 if (flow==0||v==t)
  return flow;
 for (;ptr[v]<g[v].size();++ptr[v])
 {
  long id=g[v][ptr[v]];
  long to=e[id].b;
  if (d[to]!=d[v]+1)continue;
  if (e[id].flow==e[id].cap)continue;
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
  for (int i=0;i<=N;i++)
   ptr[i]=0;
  while (true)
  {
   long pushed=dfs(s,1000000);
   if (pushed==0)break;
   flow+=pushed;
  }
 }
 return flow;
}

void DFS(long v)
{
 used[v]=1;
 comp.push_back(v);
 for (int i=0;i<G[v].size();i++)
 {
  long id=G[v][i];
  if (used[id])continue;
  DFS(id);
 }
}

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

pr[1]=1;
for (int i=1;i<=20000;i++)
 if (pr[i]==0)
  for (int j=i*2;j<=20000;j+=i)
   pr[j]=1;

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 if (ar[i]%2==0)
  l.push_back(i);
 else
  r.push_back(i);
}

for (int i=0;i<l.size();i++)
 add_edge(0,i+1,2);
for (int i=0;i<r.size();i++)
 add_edge(i+l.size()+1,n+1,2);

for (int i=0;i<l.size();i++)
 for (int j=0;j<r.size();j++)
 {
     long a=ar[l[i]]+ar[r[j]];
     if (pr[a])continue;
     add_edge(i+1,j+l.size()+1,1);
 }

s=0;
t=n+1;
N=t+1;

long res=dinic();
if (res<n)
cout<<"Impossible"<<endl;
else
{
 for (int i=0;i<e.size();i++)
 {
  int a=e[i].a;
  int b=e[i].b;
  int f=e[i].flow;
  if (a>0&&a<=l.size()&&b>l.size()&&b<=l.size()+r.size()&&f>0)
   G[l[a-1]].push_back(r[b-l.size()-1]),
   G[r[b-l.size()-1]].push_back(l[a-1]);
 }

for (int i=1;i<=n;i++)
 if (used[i]==0)
 {
  comp.clear();
  DFS(i);
  av.push_back(comp);
 }

cout<<av.size()<<endl;
for (int i=0;i<av.size();i++)
{
 cout<<av[i].size();
 for (int j=0;j<av[i].size();j++)
  cout<<" "<<av[i][j];
 cout<<endl;
}
}

cin.get();cin.get();
return 0;}