/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 1;

vector<int> adj[N];
int n, s[N], dp[N];
int ans=0;

void dfs(int v,int p)
{
    s[v]=1,dp[v]=0;

    for(int i : adj[v])
    {
        if(i==p) continue;
        dfs(i, v);
        s[v]+=s[i];
        dp[v]+=dp[i];
    }

    dp[v]+=s[v];
}

void reroot(int v,int p)
{
    ans=max(ans,dp[v]);
    
    for(int i : adj[v])
    {
        if(i==p) continue;
        
        s[v]-=s[i];
        dp[v]-=(dp[i]+s[i]);
        s[i]+=s[v];
        dp[i]+=(dp[v]+s[v]);
        
        reroot(i, v);
        
        s[i]-=s[v];
        dp[i]-=(dp[v]+s[v]);
        s[v]+=s[i];
        dp[v]+=(dp[i]+s[i]);
    }
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    ans=dp[1];
    reroot(1, 0);
    
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}