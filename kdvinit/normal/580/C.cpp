/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 1;

vector<int> adj[N];
int a[N];
int n, m;
int ans=0;

void DFS(int chi, int par, int cats)
{
    if(a[chi]==1) cats++;
    else cats=0;

    if(cats>m) return;

    int leaf=1;
    for(auto x: adj[chi])
    {
        if(x==par) continue;
        leaf=0;
        DFS(x, chi, cats);
    }

    if(leaf) ans++;
}

void solve()
{
    cin>>n>>m;

    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i=1; i<=n-1; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, -1, 0);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}