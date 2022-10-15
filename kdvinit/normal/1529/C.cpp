/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5;
vector<int> adj[N];
int l[N], r[N];
int dp[N][2];       //dp[i][0] = l, dp[i][1]=r;

void DFS(int chi, int par)
{
    dp[chi][0]=0; dp[chi][1]=0;
    for(auto x: adj[chi])
    {
        if(x==par) continue;
        DFS(x, chi);
        dp[chi][0] += max( (dp[x][0]+abs(l[chi]-l[x])), (dp[x][1]+abs(l[chi]-r[x])) );
        dp[chi][1] += max( (dp[x][0]+abs(r[chi]-l[x])), (dp[x][1]+abs(r[chi]-r[x])) );
    }
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>l[i]>>r[i];
        adj[i].clear();
    }

    for(int i=1; i<n; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, -1);
    int ans = max(dp[1][0], dp[1][1]);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}