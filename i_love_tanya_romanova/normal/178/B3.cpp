//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 201004
//#define szz 400
//#define pb push_back
using namespace std;

const int MAXN = 120000;
vector<int> g[MAXN];
bool used[MAXN];
int timer, l,k,tin[MAXN], fup[MAXN],tout[MAXN],tin1[MAXN],tout1[MAXN];
vector <vector <int> >up;
 
set<pair <long, long> > br;
pair <long, long> p;
long n,m,arp[200000],d[200000],a,b;

void IS_BRIDGE(long a,long b)
{
     p=make_pair(a,b);
     br.insert(p);
}

void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] > tin[v])
                IS_BRIDGE(v,to);
        }
    }
}
 
void find_bridges() {
    timer = 0;
    for (int i=0; i<n; ++i)
        used[i] = false;
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);
}

void dfs1(long a,long b)
{
 
 arp[a]=1;
 d[a]=b;
 
 for (int i=0;i<g[a].size();i++)
 if (arp[g[a][i]]==0)
 {p=make_pair(a,g[a][i]);
  if (br.find(p)!=br.end())
  dfs1(g[a][i],b+1); else dfs1(g[a][i],b);
                           
                     }
 }
 
 void dfs2 (int v, int p = 0) {
    tin1[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p&&tin1[to]==0)
            dfs2 (to, v);
    }
    tout[v] = ++timer;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=0;i<m;i++)
{
    cin>>a>>b;
    --a;--b;
    g[a].push_back(b);
    g[b].push_back(a);
}

dfs(0);

set <pair<long, long> > ::iterator it;

/*for (it=br.begin();it!=br.end();++it)
{
    cout<<(*it).first<<" "<<(*it).second<<endl;
}*/


for (int i=0;i<n;i++)
arp[i]=0;

dfs1(0,0);

/*
for(int i=0;i<n;i++)
cout<<i<<" "<<d[i]<<endl;
*/

up.resize(n+10);
timer=0;
l=1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    
//  cout<<"A"<<endl;
dfs2(0);
//cout<<"A"<<endl;
cin>>k;long pp;
for (int i=0;i<k;i++)
{
    cin>>a>>b;
    --a;--b;
    pp=lca(a,b);
    cout//<<pp<<" "
    <<d[a]-d[pp]+d[b]-d[pp]<<endl;
}
cin.get();cin.get();
return 0;}