/*
Why did I ever think
life is about to go on
in a minute

And did I ever see
life is about to go on
in a minute
Life never goes on
Those are empty words

This is the back door
that will lead you out
to find the alley of your dreams
They try and tell you
They're just empty words

It's just a frame of mind

This is the back door
Leading me out
Sweep you away
We'll never go on
We're used to these empty words

It's just a frame of mind
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
 
using namespace std;

long used[1<<20];
vector<long> g[1<<15],gt[1<<15];
vector<long> order;
long comp[1<<20];
long cl;

void dfs1(long v)
{
 used[v]=1;
 for (int i=0;i<g[v].size();i++)
 {
     long to=g[v][i];
     if (used[to])continue;
     dfs1(to);
 }
 order.push_back(v);
}

void dfs2(long v)
{
 comp[v]=cl;
 for (int i=0;i<gt[v].size();i++)
 {
     long to=gt[v][i];
     if (comp[to]==0)
      dfs2(to);
 }
}

long n,m,a[1<<10],b[1<<10];
long er;
string ans[10000];

void add_edge(long a,long b)
{
 g[a].push_back(b);
 gt[b].push_back(a);
}

void check(long x,long y)
{
 if (a[x]==b[y])return;
 if (a[x]==a[y])return ;
 if (b[x]==a[y])return ;
 if (b[x]==b[y])return;
 vector<pair<long, long> > v;
 v.push_back(make_pair(a[x],1));
 v.push_back(make_pair(a[y],2));
 v.push_back(make_pair(b[x],1));
 v.push_back(make_pair(b[y],2));
 sort(v.begin(),v.end());
 for (int i=1;i<4;i++)
  if (v[i].second==v[i-1].second)
   return;
  // build graph
  add_edge(x,y+2*n);
  add_edge(x+2*n,y);
  add_edge(y+2*n,x);
  add_edge(y,x+2*n);
}

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>m>>n;
for (int i=1;i<=n;i++)
{
 cin>>a[i]>>b[i];
}

for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
 {
  check(i,j);
 }

for (int i=1;i<=n;i++)
{
 add_edge(i,i+3*n);
 add_edge(i+2*n,i+n);
 add_edge(i+3*n,i);
 add_edge(i+n,i+2*n);
}

for (int i=1;i<=4*n;i++)
{
 if (used[i])continue;
 dfs1(i);   
}

for (int i=1;i<=n*4;i++)
{
 long v=order.back();
 order.pop_back();
 if (comp[v]!=0)continue;
 ++cl;
 dfs2(v);
}

for (int i=1;i<=n*2;i++)
{
 if (comp[i]==comp[i+n*2])
 {
  er=1;break;
 }
}

for (int i=1;i<=n*2;i++)
{
 if (comp[i]>comp[i+n*2])
 {
  if (i<=n)ans[i]="i";
  else 
  ans[i-n]="o";
 }
}

if (er)cout<<"Impossible"<<endl;
else for (int i=1;i<=n;i++)
{
     cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}