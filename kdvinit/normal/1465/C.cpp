/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 1;

vector<int> adj[N];
int vis[N];

bool cyc(int chi, int root)
{
    vis[chi]=1;

    for(auto x: adj[chi])
    {
        if(x==root) return true;

        if(vis[x]==1) return false;
        else return cyc(x, root);
    }

    return false;
}

void solve()
{
    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++) adj[i].clear(), vis[i]=0;

    int ans=0;
    for(int i=1; i<=m; i++)
    {
        int x, y; cin>>x>>y;
        if(x==y) continue;
        ans++;
        adj[x].push_back(y);
    }

    for(int i=1; i<=n; i++)
    {
        if(vis[i]==1) continue;
        ans += cyc(i, i);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}