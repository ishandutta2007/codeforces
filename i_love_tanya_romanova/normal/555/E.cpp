/*
You build up your walls
and burn a bridge with every fight
Cast crippling stones that do
offend with all of your might

And you're so convinced
Ignorant defense

Miles away the troops do roar
closer to their goal
Cast away alone you plot
Temperamental soul

River of rapture
Cleanse me whole
Nullify this plague
River of rapture
Mend these bones
So broken, so displaced

You hiss out the blame
for your tough and common life
Yet you made this choice
again to sit, not stand up and fight

Twisted point of view
Solely felt by you

Miles away the troops do storm
closer to their goal
cast away, alone you rot
Bitter angry soul

Rise up bleeding
knock me down
I'll get back up again
Always pushing forward
And I'll fight until the end

I will hear your voice no more
And you won't have a choice no more
Yet I will choose to bend no more
and you can't condescend no more
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
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define maxlen (1<<20)
#define alphabet 256
#define root asdfasdfadsfassdg

using namespace std;

int n,m,q;
vector<int> g[1<<20];
int used[1<<20];
int w[1<<20];
int comps;
int root;
set<pair<int, int> > bridges;
set<pair<int, int> > ::iterator it;
int tin[1<<20],tout[1<<20];
int timer;
int fup[1<<20];
int up[1<<19][20];
int dep[1<<19];
int er,cA[1<<20],cB[1<<20],cC[1<<20];
int W[1<<20];
map<pair<int,int> ,int> cnt;

int get(int x)
{
    if (W[x]==x)
        return x;
    return W[x]=get(W[x]);
}

void merge(int a,int b)
{
    a=get(a);
    b=get(b);
    W[a]=b;
}

bool invalid(int a,int b)
{
    if (bridges.find(make_pair(a,b))!=bridges.end())
        return true;
    if (bridges.find(make_pair(b,a))!=bridges.end())
        return true;
    return false;
}

void trace(int v)
{
    w[v]=comps;
    
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        if (invalid(to,v))
            continue;
        if (w[to])
            continue;
        trace(to);
    }
}

void add_bridge(int a,int b)
{
    pair<int, int> p=make_pair(a,b);
    if (cnt[p]>1)
        return;
    bridges.insert(make_pair(a,b));
}

void dfs(int v,int p=-1)
{
    tin[v]=timer;
    fup[v]=timer;
    ++timer;
    used[v]=1;
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        if (to==p)
            continue;
        if (used[to])
            fup[v]=min(fup[v],tin[to]);
        else
        {
            dfs(to,v);
            fup[v]=min(fup[v],fup[to]);
            if (fup[to]>tin[v])
                add_bridge(v,to);
        }
    }
}

int ldfs(int v,int p=1)
{
    used[v]=1;
    tin[v]=timer;
    ++timer;
    up[v][0]=p;
    for (int lev=1;lev<=18;lev++)
    {
        up[v][lev]=up[up[v][lev-1]][lev-1];
    }
    
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        if (used[to])
            continue;
        dep[to]=dep[v]+1;
        ldfs(to,v);
    }
    tout[v]=timer;
    ++timer;
}

bool upper(int a,int b)
{
    return (tin[a]<=tin[b]&&tout[a]>=tout[b]);
}

int lca(int a,int b)
{
    if (upper(a,b))
        return a;
    if (upper(b,a))
        return b;
    if (dep[a]<dep[b])
    {
        swap(a,b);
    }
    int dif=dep[a]-dep[b];
    for (int i=18;i+1;--i)
        if (dif&(1<<i))
        {
            a=up[a][i]; 
        }
    
    for (int i=18;i+1;--i)
    {
        if (up[a][i]!=up[b][i])
            a=up[a][i],
            b=up[b][i];
    }
    
    return up[a][0];
}

void solve(int v)
{
    used[v]=1;
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        if (used[to])
            continue;
        solve(to);
        cA[v]+=cA[to];
        cB[v]+=cB[to];
        cC[v]+=cC[to];
    }
    if (cA[v]>cC[v]&&cB[v]>cC[v])
        er=1;
}

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>q;

for (int i=1;i<=n;i++)
    W[i]=i;

for (int i=1;i<=m;i++)
{
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
    pair<int, int> p=make_pair(a,b);
    cnt[p]++;
    p=make_pair(b,a);
    cnt[p]++;
    merge(a,b);
}

for (int i=1;i<=n;i++)
    used[i]=0;

for (int i=1;i<=n;i++)
    if (used[i]==0)
        dfs(i);

for (int i=1;i<=n;i++)  
    used[i]=0;

for (int i=1;i<=n;i++)
{
    if (w[i])
        continue;
    comps++;
//  cout<<i<<" ^ "<<comps<<endl;
    
    root=comps;
    trace(i);
}

for (int i=1;i<=n;i++)
    g[i].clear();

for (it=bridges.begin();it!=bridges.end();it++)
{
    int v1=(*it).first;
    int v2=(*it).second;
//  cout<<"#"<<v1<<" "<<v2<<endl;
    v1=w[v1];
    v2=w[v2];
    g[v1].push_back(v2);
    g[v2].push_back(v1);    
}
/*
for (int i=1;i<=comps;i++)
{
    cout<<i<<": ";
    for (int j=0;j<g[i].size();j++)
        cout<<g[i][j]<<" ";
    cout<<endl;
}
*/
timer=0;

for (int i=1;i<=n;i++)
    used[i]=0;

for (int i=1;i<=n;i++)
    if (used[i]==0)
        ldfs(i,i);

for (;q;--q)
{
    int a,b;
    cin>>a>>b;
    a=w[a];
    b=w[b];
    int ta=get(a);
    int tb=get(b);
    
    if (ta!=tb)
    {
        er=1;
        break;
    }
    
    int t=lca(a,b);
    cA[a]++;
    cB[b]++;
    cC[t]++;
}

for (int i=1;i<=n;i++)
{
    used[i]=0;
}

for (int i=1;i<=n;i++)
    if (used[i]==0&&er==0)
        solve(i);

if (er)
    cout<<"No"<<endl;
else
    cout<<"Yes"<<endl;
    
//cin.get();cin.get();
return 0;}