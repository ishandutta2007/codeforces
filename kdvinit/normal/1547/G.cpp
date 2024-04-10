/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 4e5 + 1;

vector<int> adj[N];
int vis1[N], vis2[N], vis3[N], cur[N], ans[N], Infi[N];

void DFS(int chi)
{
    ans[chi]++; vis1[chi]=1; cur[chi]=1;
    for(auto x: adj[chi])
    {
        if(vis1[x]==1) { ans[x]++; if(cur[x]==1) Infi[x]=1; }
        else DFS(x);
    }
    cur[chi]=0;
}

void DFS2(int chi)
{
    vis2[chi]=1; Infi[chi]=1;     ans[chi]=-1;
    for(auto x: adj[chi]) if(!vis2[x]) DFS2(x);
}

void DFS3(int chi)
{
    vis3[chi]=1; ans[chi]=2;
    for(auto x: adj[chi]) if(!vis3[x]) DFS3(x);
}

void solve()
{
    int n, m; cin>>n>>m;
    for(int i=1; i<=n; i++) { adj[i].clear(); vis1[i]=0; vis2[i]=0; cur[i]=0; ans[i]=0; Infi[i]=0; vis3[i]=0; }
    for(int i=1; i<=m; i++) { int u, v; cin>>u>>v; adj[u].push_back(v); }
    DFS(1);
    for(int i=1; i<=n; i++) if(ans[i]>=2 && vis3[i]==0) DFS3(i);
    for(int i=1; i<=n; i++) if(Infi[i]==1 && vis2[i]==0) DFS2(i);
    for(int i=1; i<=n; i++) cout<<ans[i]<<" "; cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}