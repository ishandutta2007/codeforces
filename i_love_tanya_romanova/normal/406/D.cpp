/*
All the photographs are peeling
and colors turn to gray, he stayed
in his room with memories for days, he faced
an undertow of future's laid to waste, embraced
by the loss of one he could not replace

and there's no reason that she'd passed
and there is no god with a plan, it's sad
and his loneliness is proof, it's sad
he could only love you, it's sad

the door swings through a passing fable
a fate we may delay, we say
holding on, live within our embrace
eleven nights, he laid in bed
hoping that dreams will bring her back, it's sad
and his loneliness is cruel, it's sad
he could only love you, it's sad

holding his last breath, believing
he'll make his way
but she's not forgotten
he's haunted
he's searching for escape

if just one wish could bring her back, it's sent
and his loneliness is proof, it's sad
he will always love you, he said
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

#define  INF 100000000
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long tests,a,b;
long long n,x[200000],y[200000],par[200000];
long long x1,y1,x2,y2,s;
vector<long> g[200000];
long tin[200000],tout[200000],timer;
long l;
vector<long> up[200000];
vector<long> avec;

bool cansee(long a,long b)
{
 if (b==a+1)return true;
 x1=x[par[a]]-x[a];
 y1=y[par[a]]-y[a];
 x2=x[b]-x[par[a]];
 y2=y[b]-y[par[a]];
 s=x1*y2-x2*y1;
 if (s<=0)return false;
 return true;
}

bool canmove(long x)
{
 if (par[x]==n)return false;
 if (cansee(x,par[par[x]]))return true;
 return false;  
}

void move(long x)
{
 par[x]=par[par[x]];
}

void dfs(long v,long p)
{
     tin[v]=++timer;
     up[v][0]=p;
     for (int i=1;i<=l;i++)
     {
      up[v][i]=up[up[v][i-1]][i-1];
     } 
     for (int i=0;i<g[v].size();i++)
     {
      long to=g[v][i];
      if (to!=p)dfs(to,v);
     }
     tout[v]=++timer;
}

bool upper(long a,long b)
{
 return (tin[a]<=tin[b]&&tout[a]>=tout[b]);
}

long lca(long a,long b)
{
// cout<<"%"<<a<<" "<<b<<endl;

 if (upper(a,b))return a;
 if (upper(b,a))return b;
 for (int i=l;i>=0;--i){//cout<<up[a][i]<<endl;
 if  (!upper(up[a][i],b))a=up[a][i];}
 return up[a][0];
}

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>x[i]>>y[i];
}

par[n]=n;
for (int i=n-1;i;--i)
{
 par[i]=i+1;
// if (cansee(i,par[i+1]))par[i]=par[i+1];
 while (canmove(i))move(i);
}
/*
for (int i=1;i<=n;i++)
cout<<i<<"  "<<par[i]<<endl;
*/
for(int i=1;i<=n;i++)
if (par[i]!=i)g[par[i]].push_back(i);

l=1;
while ((1<<l)<=n)++l;
for (int i=1;i<=n;i++)
{up[i].resize(l+2);for (int j=0;j<up[i].size();j++)up[i][j]=n;}

dfs(n,n);

cin>>tests;
for (;tests;--tests)
{
 cin>>a>>b;
 avec.push_back(lca(a,b));
}

for (int i=0;i<avec.size();i++)
{
    if (i)cout<<" ";
    cout<<avec[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}