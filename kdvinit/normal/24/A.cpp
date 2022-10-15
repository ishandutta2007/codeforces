/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 101;

vector<pair<int, int>> adj[N];
int ans=1e10;

void DFS(int chi, int par, int cost)
{
    if(chi==1 && par!=-1)
    {
        ans = min(ans, cost);
        return;
    }

    for(auto cur: adj[chi])
    {
        int v = cur.first;
        int w = cur.second;
        if(v==par) continue;

        DFS(v, chi, cost+w);
    }
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, w});
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