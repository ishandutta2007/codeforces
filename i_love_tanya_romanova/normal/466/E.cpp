/*
Under Doleful Skies
She was gone forever and ever
Gone without a heartful farewell
Erased for all eternity
Who blame you now?
Memories was my only joy
For a moment I feared myself
As my strength is falling down
Lost, condemned, eternally
Who blame you now?
No more tears of blood
From my mystic Queen
The one I enthroned
Goddess of my destiny
Who blame you now?
A weeping heart!
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
#define bsize 512

using namespace std;

long n,m,x[1<<18],y[1<<18],t[1<<18],indeg[1<<18],used[1<<18],
tin[1<<18],tout[1<<18];
long timer;
vector<pair<long, long> > g[1<<18];
long dep[1<<18];
long parent[1<<18];
long moment[1<<18];
long wors[1<<18][22];
long up[1<<18][22];
long tup,tl;

void dfs(long v)
{
 used[v]=1;
 ++timer;
 tin[v]=timer;

 up[v][0]=parent[v];
 for (int i=1;i<=20;i++)
  up[v][i]=up[up[v][i-1]][i-1];
 
 for (int i=1;i<=20;i++)
  wors[v][i]=max(wors[v][i-1],wors[up[v][i-1]][i-1]);
 
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i].first;
  if (used[q])continue;
  dep[q]=dep[v]+1;
  parent[q]=v;
  moment[q]=g[v][i].second;
  wors[q][0]=g[v][i].second;
  dfs(q);
 }
 tout[v]=timer;
 ++timer;
}

void add_edge(long a,long b,long m)
{
// cout<<"&&"<<a<<" "<<b<<endl;
 g[a].push_back(make_pair(b,m));
 ++indeg[b];
}

long pacs;
long tt[1<<18];
long vert[1<<18];
long targ;

bool upper(long a,long b)
{return (tin[a]<=tin[b]&&tout[a]>=tout[b]);}

string solve()
{
//       cout<<tup<<"   "<<targ<<" "<<tin[tup]<<" "<<tout[tup]<<" "<<tin[targ]<<" "<<tout[targ]<<endl;
 if (!upper(tup,targ))return "NO";
 long mn=-1e9;
 for (int i=20;i>=0;--i)
 {
  if (dep[targ]-(1<<i)>=dep[tup])
  {
   mn=max(mn,wors[targ][i]);
   targ=up[targ][i];
  }
 }
// cout<<mn<<" )) "<<tl<<endl;
 if (mn>tl)return "NO";
 return "YES";
}


int main(){
//freopen("optimize.in","r",stdin);
//freopen("optimize.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>t[i];
 if (t[i]==2)cin>>x[i];
 else cin>>x[i]>>y[i];
 if (t[i]==1)
  add_edge(y[i],x[i],i);
}

for (int i=1;i<=n;i++)
if (indeg[i]==0&&used[i]==0)
{
 dfs(i);
}
/*
for (int i=1;i<=n;i++)
{
    for (int j=0;j<=2;j++)
     cout<<up[i][j]<<" ";
     cout<<endl;
    for (int j=0;j<=2;j++)
     cout<<wors[i][j]<<" ";
    cout<<endl<<endl;
}*/
/*for (int i=1;i<=n;i++)
cout<<tin[i]<<" "<<tout[i]<<" "<<moment[i]<<endl;
*/
for (int i=1;i<=m;i++)
{
 if (t[i]==2){++pacs;tt[pacs]=i;vert[pacs]=x[i];continue;}
 if (t[i]==1)continue;
 tl=tt[y[i]];
 targ=vert[y[i]];
 tup=x[i];
// cout<<targ<<"%"<<endl;
 cout<<solve()<<"\n";
}

cin.get();cin.get();
return 0;}