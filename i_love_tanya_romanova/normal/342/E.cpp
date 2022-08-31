/*
Towards the rich archaic heavens; towards the lack diorama
you are the artist and the texture
that plays with the mantle of the Earth

When the bleakest of powders
lie rooted to the starched stones
and roots that feed the peaking trees
embrace the sleeping shores

Archaic pearls of sleep and death
the voice of December losing its breath
and the floweryard of whit and grey is haunted

White as the down of flaking snow,
the heroic emblems of life

Green is the color of my death
as the winter-guise I swoop towards teh ground
Green is the landscape of my sorrowfilled passing

We are In Flames,
towards the dead archaic heavens
We are the mantle and the texture
the alters the mantle of the Earth
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long timer,tin[200000],tout[200000],l,n,m,a,b;
vector<long> up[200000];
vector<long> g[200000];
long ans[200000],d[200000];
vector<long> temp;
queue<long> qu;

void update()
{
/* for (int i=1;i<=n;i++)
 ans[i]=10000000;
 */
 for (int i=0;i<temp.size();i++)
 {
     qu.push(temp[i]);
     ans[temp[i]]=0;
 }
 
 while (qu.size())
 {
  long q=qu.front();
  qu.pop();
  for (int i=0;i<g[q].size();i++)
  if (ans[g[q][i]]>ans[q]+1)
   {ans[g[q][i]]=ans[q]+1;
   qu.push(g[q][i]);
   }
 }
 temp.clear();
}

void dfs(long v,long p)
{
/*     cout<<v<<" "<<p<<endl;
     cin.get();
  */   
 tin[v]=timer;++timer;
 up[v][0]=p;
 for (int i=1;i<=l;i++)
 {
     up[v][i]=up[up[v][i-1]][i-1];
 }    
 for (int i=0;i<g[v].size();i++)
 {
     long q=g[v][i];
     if (q!=p){d[q]=d[v]+1;
     dfs(q,v);}
 }
 tout[v]=timer;
 ++timer;
}

bool upper(long a,long b)
{
 return tin[a]<=tin[b]&&tout[a]>=tout[b];    
}

long lca(long a,long b)
{
 if (upper(a,b))return a;
 if (upper(b,a))return b;
 for (int i=l;i>=0;i--)
 if (!upper(up[a][i],b))a=up[a][i];
 return up[a][0];
}

int main(){
//freopen("revolutions.in","r",stdin);
//freopen("revolutions.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<n;i++)
{
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}

l=1;
while ((1<<l)<=n)++l;
for (int i=0;i<=n;i++)
up[i].resize(l+1);

dfs(1,1);

//while (cin>>a>>b)cout<<lca(a,b)<<endl;

for (int i=1;i<=n;i++)
ans[i]=1000000;

temp.push_back(1);
update();

for (int i=1;i<=m;i++)
{
 if (i%256==0)
 {
  update();
 }   
 cin>>a>>b;
 if (a==1){temp.push_back(b);}
 else
 {
  long ttemp=ans[b];
  
  for (int i=0;i<temp.size();i++)
    ttemp=min(ttemp,d[b]+d[temp[i]]-2*d[lca(b,temp[i])]);
    cout<<ttemp<<endl;
 }
}

cin.get();cin.get();
return 0;}