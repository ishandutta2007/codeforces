/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 1;
const int mod = 1e9 + 7;

vector<int> adj[N];
int n, a[N], s[N], dp[N], ans=0;

void dfs(int v,int p)
{
    dp[v]=0;
    s[v]=1;

    for(int i : adj[v])
    {
        if(i==p) continue;
        dfs(i, v);
        dp[v]-=dp[i]; dp[v]%=mod;
        s[v]+=s[i]; s[v]%=mod;
    }
    
    dp[v]+=(a[v]*s[v]); dp[v]%=mod;
}

void reroot(int v,int p)
{
    ans+=dp[v]; ans%=mod;

    for(int i : adj[v])
    {
        if(i==p) continue;

        s[v]-=s[i]; s[v]%=mod;
        dp[v]-=(a[v]*s[i] - dp[i]); dp[v]%=mod;
        s[i]+=s[v]; s[i]%=mod;
        dp[i]+=(a[i]*s[v]-dp[v]); dp[i]%=mod;

        reroot(i, v);

        s[i]-=s[v]; s[i]%=mod;
        dp[i]-=(a[i]*s[v] - dp[v]); dp[i]%=mod;
        s[v]+=s[i]; s[v]%=mod;
        dp[v]+=(a[v]*s[i]-dp[i]); dp[v]%=mod;
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
    
    ans=(ans+mod)%mod;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}