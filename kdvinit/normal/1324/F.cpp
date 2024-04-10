/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 1;

vector<int> adj[N];
int n, a[N], dp[N], res[N];

void dfs(int v,int p)
{
    dp[v]=-1;

    for(int i : adj[v])
    {
        if(i==p) continue;
        dfs(i, v);
        
        if(dp[i]>0) dp[v]+=dp[i];
    }
    
    if(a[v]==1) dp[v]+=2;
}

void reroot(int v,int p)
{
    res[v]=dp[v];

    for(int i : adj[v])
    {
        if(i==p) continue;

        if(dp[i]>0) dp[v]-=dp[i];
        if(dp[v]>0) dp[i]+=dp[v];

        reroot(i, v);

        if(dp[v]>0) dp[i]-=dp[v];
        if(dp[i]>0) dp[v]+=dp[i];
        
    }
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<n;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    reroot(1, 0);
    
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}