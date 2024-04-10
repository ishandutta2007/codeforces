/*
Yeah, I get it, you're an outcast
Always under attack, always coming in last
Bringing up the past, no one owes you anything
I think you need a shotgun blast, a kick in the ass
So paranoid, watch your back

Oh my, here we go

Another lose cannon gone bi-polar
Slipped down, couldn't get much lower
Quicksand's got no sense of humor
I'm still laughing like hell

You think that by crying to me
Looking so sorry that I'm gonna believe
You've been infected by a social disease
Well, then take your medicine

I created the sound of madness, wrote the book on pain
Somehow I'm still here to explain
That the darkest hour never comes in the night
You can sleep with a gun
When you gonna wake up and fight for yourself?

I'm so sick of this tombstone mentality
If there's an afterlife then it'll set you free
But I'm not gonna part the seas
You're a self-fulfilling prophecy

You think that by crying to me
Looking so sorry that I'm gonna believe
You've been infected by a social disease
Well, then take your medicine

I created the sound of madness, wrote the book on pain
Somehow I'm still here to explain
That the darkest hour never comes in the night
You can sleep with a gun
When you gonna wake up and fight for yourself?

I created the sound of madness, wrote the book on pain
Somehow I'm still here to explain
That the darkest hour never comes in the night
You can sleep with a gun
When you gonna wake up, when you gonna wake up and fight?

I created the sound of madness, wrote the book on pain
Somehow I'm still here to explain
That the darkest hour never comes in the night
You can sleep with a gun
When you gonna wake up and fight for yourself?

When you gonna wake up and fight for yourself?
When you gonna wake up and fight for yourself?
When you gonna wake up and fight for yourself?
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
#define l 19

using namespace std;

long par[1<<18][20];
long sub[1<<20];
long dep[1<<20];
long tests,a,b,n;
vector<long> g[1<<20];

void dfs(long v,long p=1)
{
 par[v][0]=p;
 sub[v]=1;
 for (int i=1;i<=l;i++)
  par[v][i]=par[par[v][i-1]][i-1];
 for (int i=0;i<g[v].size();i++)
 {
     long to=g[v][i];
     if (to==p)continue;
     dep[to]=dep[v]+1;
     dfs(to,v);
     sub[v]+=sub[to];
 }
}

long lca(long a,long b)
{
 if (dep[a]<dep[b])swap(a,b);
 for (int i=l;i>=0;i--)
  if (dep[a]-(1<<i)>=dep[b])
   a=par[a][i];
 for (int i=l;i>=0;--i)
  if (par[a][i]!=par[b][i])
   a=par[a][i],
   b=par[b][i];
 if (a!=b)
  a=par[a][0];
 return a;
}

pair<long, long> LCA(long a,long b)
{
 if (dep[a]<dep[b])swap(a,b);
 for (int i=l;i>=0;i--)
  if (dep[a]-(1<<i)>=dep[b])
   a=par[a][i];
 for (int i=l;i>=0;--i)
  if (par[a][i]!=par[b][i])
   a=par[a][i],
   b=par[b][i];
 return make_pair(a,b);
}

long gp(long v,long d)
{
 for (int i=l;i>=0;--i)
 {
  if (d>=(1<<i))
  d-=(1<<i),
  v=par[v][i];
 }
 return v;
}

long solve(long a,long b)
{
 if (a==b)
  return n;
 if (dep[a]==dep[b])
 {
  pair<long, long> tp=LCA(a,b);
  return n-sub[tp.first]-sub[tp.second];
 }
 if (dep[a]<dep[b])
  swap(a,b);
 long q=lca(a,b);
 long dist=dep[a]+dep[b]-2*dep[q];
 if (dist%2) return 0;
 long qq=gp(a,dist/2-1);
 long qw=gp(qq,1);
 return sub[qw]-sub[qq];
}

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<n;i++)
{
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
dfs(1,1);

cin>>tests;
for (;tests;--tests)
{
 cin>>a>>b;
 cout<<solve(a,b)<<endl;
}

cin.get();cin.get();
return 0;}