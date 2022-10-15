/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 100;
vector<int> adj[N];
int parr[N], ans[N], vis[N], col[N];

void DFS(int chi, int par)
{
    parr[chi]=par;
    for(auto x: adj[chi])
    {
        if(x==par) continue;
        DFS(x, chi);
    }
}

void DFS2(int chi)
{
    ans[chi]=0;
    for(auto x: adj[chi])
    {
        if(vis[x]) continue;
        vis[x]=1;
        DFS2(x);
    }
}

void solve()
{
    int n; cin>>n;
    for(int i=1; i<=n; i++) adj[i].clear(), vis[i]=0;
    for(int i=1; i<=n; i++) cin>>col[i];

    for(int i=1; i<=n-1; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> blk;
    for(int i=1; i<=n; i++) if(col[i]) blk.push_back(i);

    int root = blk[0];
    DFS(root, -1);

    int allp=0;
    for(int i=1; i<=n; i++) ans[i]=1;

    int spec[n+1]={0}, cr=0;
    for(int node: blk)
    {
        vis[node]=1;
        if(node==root) continue;
        int cur = parr[node];
        while(1)
        {
            vis[cur]=1;
            if(col[cur]==1) { allp=1; break; }
            if(ans[cur]==0) { spec[cur]=1; break; }
            ans[cur]=0;
            cur = parr[cur];
            if(cur==root) { cr++; break; }
        }
    }

    if(cr>1) allp=1;

    for(int x: blk)
    {
        for(int y: adj[x])
        {
            ans[y]=1;
            if(spec[y]==1) allp=1;
        }
    }

    if(allp) for(int i=1; i<=n; i++) ans[i]=1;

    for(int i=1; i<=n; i++) if(ans[i]==0) DFS2(i);

    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}