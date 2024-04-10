// Centroid Decomposition
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define eb emplace_back
#define pii pair<int,int>
#define F first
#define S second
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";

const int N = 100005;
const int logN = 20;
set<int> con[N];
vi conc[N];
int st[N], par[logN][N],depth[N], parent[N],parent2[N], depth2[N];
bool vis[N];

void dfs_original(int s, int d, int p)
{
    depth[s] = d;
    par[0][s] = p;
    for(int v:con[s])
        if(v!=p)
            dfs_original(v,d+1,s);
}
void dfs1(int s,int p)
{
    st[s] = 1;
    parent[s] = p;
    for(int v:con[s])
        if(v!=p)
            dfs1(v,s),st[s]+=st[v];
}
int dfs2(int s, int p, int n)
{
    for(int v:con[s])
        if(v!=p && st[v]>n/2)
            return dfs2(v,s,n);
    return s;    
}
int decomp[N];
void decompose(int root, int p, int n, int d)
{
    dfs1(root,0);
    int cen = dfs2(root,0,n);
    parent2[cen] = p;
    depth2[cen] = d;
    int sz = 0;
    int _par = parent[cen];
    for(int v:con[cen])
        if(v!=_par)
            sz+=st[v],decomp[v] = st[v];
    for(int v:con[cen])
    {
        if(v!=_par){
            con[v].erase(cen);
            decompose(v,cen,decomp[v],d+1);
        }
    }
    if(con[cen].find(_par)!=con[cen].end())
    {
        con[_par].erase(cen);
        decompose(_par,cen,n-1-sz,d+1);
    }
}
int lca_centroid(int a, int b)
{
    if(depth2[a]>depth2[b])
        swap(a,b);
    while(depth2[a]!=depth2[b])
        b = parent2[b];
    while(a != b)
    {
        a = parent2[a];
        b = parent2[b];
    }
    return a;
}

void pre(int n)
{
    for(int j = 1;j<logN;j++)
        for(int i = 1;i<=n;i++)
            par[j][i] = par[j-1][par[j-1][i]];
}

int lca(int a, int b)
{
    if(depth[a]<depth[b])
        swap(a,b);
    int l = depth[a]-depth[b];
    for(int i = 0;i<logN;i++) if(l&(1<<i)) a = par[i][a];    
    if(a==b)
        return a;
    assert(depth[a] == depth[b]);
    for(int i = logN-1;i>=0;i--)
    if(par[i][a]!=par[i][b])
    {
        a = par[i][a],b = par[i][b];
    }
    return par[0][a];
}
int dist(int a, int b)
{
    int l = lca(a,b);
    return depth[a]+depth[b] - 2*depth[l];
}
int ans[N];
int main()
{
    int n,u,v,m;
    scanf("%d %d", &n, &m);
    for(int i = 1;i<=n-1;i++)
    {
        scanf("%d %d", &u, &v);
        con[u].insert(v);
        con[v].insert(u);
    }
    dfs_original(1,0,0);
    decompose(1,0,n,0);
    pre(n);
    const int inf = 1e9+7;
    for(int i = 1;i<=n;i++)
        ans[i] = inf;
    for(int i = 1;i<=m+1;i++)
    {
        if(i==1)
            u=1,v=1;
        else
            scanf("%d %d", &u, &v);
        if(u==1)
        {
            int v0 = v;
            while(v)
            {
                ans[v] = min(ans[v],dist(v,v0));
                v = parent2[v];
            }
        }
        else
        {
            int v0 = v;
            int mn = inf;
            while(v)
            {
                mn = min(mn,ans[v] + dist(v,v0));
                v = parent2[v];
            }
            if(mn==inf)
                mn = -1;
            printf("%d\n",mn);
        }
    }
}