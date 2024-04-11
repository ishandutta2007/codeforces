#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <queue>
#include <memory.h>

using namespace std;

/*
CAUTION: IS INT REALLY INT, BUT NOT LONG LONG?
REAL SOLTION AFTER MAIN FUNCTION
*/

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef double ld;
typedef vector <int> vi;
typedef pair <int, int> pi;
typedef vector <li> vli;
typedef pair <li, li> pli;

void solve();
int main() 
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while (t--)
        solve();
    return 0;

}

//#define int li

int n;
vector <int> g[100500];
int tin[100500], tout[100500];
int up[100500][40];
int timer=0;
int l=20;
int cnt[100500];
int pred[100500];

int level[100500];

void dfs (int v, int p=0, int lev=0) 
{
    level[v]=lev;
    pred[v]=p;
    tin[v]=timer++;
    up[v][0]=p;
    for (int i=1; i<=l; i++)
            up[v][i]=up[up[v][i-1]][i-1];
    cnt[v]=1;
    for (int i=0; i<g[v].size(); i++) 
    {    
        int to=g[v][i];
        if (to!=p)
        {
            dfs (to, v, lev+1);
            cnt[v]+=cnt[to];
        }
    }
    tout[v]=timer++;
}

bool upper (int a, int b) 
{
    return tin[a]<=tin[b] && tout[a]>=tout[b];
}

int lca (int a, int b) 
{
    if (upper (a, b))  
        return a;
    if (upper (b, a))  
        return b;
    for (int i=l; i>=0; i--)
        if (! upper (up[a][i], b))
            a=up[a][i];
    return up[a][0];
}

bool has[100500];

bool heavy (int v, int to)
{
    return 2*cnt[to]>=cnt[v];
}

int begs[100500], Ends[100500];

vector < pair <int, int> > e;
map < pair <int, int>, int > ans;

void dfs1 (int v, int p=0)
{
    for (int i=0; i<g[v].size(); i++)
        if (g[v][i]!=p)
        {
            int to=g[v][i];
            dfs1(to, v);
            ans[mp(p, v)]+=ans[mp(v, to)];
        }
    ans[mp(p, v)]+=Ends[v]-begs[v];
    //cout<<p<<' '<<v<<' '<<ans[mp(p, v)]<<endl;
}



void solve()
{  
    cin>>n;
    for (int i=0; i<n-1; i++)
    {
        int q, w;
        cin>>q>>w;
        q--; w--;
        g[q].pb(w);
        g[w].pb(q);
        e.pb(mp(q, w));
    }
    dfs(0);
    for (int i=0; i<n-1; i++)
        if (level[e[i].first]>level[e[i].second])
            swap(e[i].first, e[i].second);
    int k;
    cin>>k;
    for (int i=0; i<k; i++)
    {
        int q, w;
        cin>>q>>w;
        q--; w--;
        int cur=lca(q, w);
        if (cur!=q)
        {
            begs[cur]++;
            Ends[q]++;
        }
        if (cur!=w)
        {
            begs[cur]++;
            Ends[w]++;
        }
    }
    
    /*for (int i=0; i<n; i++)
        cout<<begs[i]<<' '<<Ends[i]<<endl;*/
    
    dfs1(0);
    for (int i=0; i<n-1; i++)
        cout<<ans[e[i]]<<' ';
    
}