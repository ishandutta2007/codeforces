/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 3e5 + 10;
const int mod = 998244353;

vector<int> adj[N];
int dp[N][4];       //1 = empty, 2 = col, 3 = notcol

void DFS(int chi, int par)
{
    if(par!=-1 && adj[chi].size()==1)
    {
        dp[chi][1] = 1;
        dp[chi][2] = 1;
        dp[chi][3] = 1;
        return;
    }

    dp[chi][1]=1;
    dp[chi][2]=1;
    dp[chi][3]=1;

    for(auto x: adj[chi])
    {
        if(x==par) continue;
        DFS(x, chi);

        dp[chi][1]*=(dp[x][2]+dp[x][3]-dp[x][1]);
        dp[chi][1]%=mod;

        dp[chi][2]*=(dp[x][2]+2*dp[x][3]-dp[x][1]);
        dp[chi][2]%=mod;

        dp[chi][3]*=(2*dp[x][2]+2*dp[x][3]-dp[x][1]);
        dp[chi][3]%=mod;
    }
}

void solve()
{
    int n; cin>>n;
    for(int i=1; i<=n; i++) adj[i].clear();

    for(int i=1; i<=n-1; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, -1);

    int ans = (dp[1][2]+dp[1][3]-dp[1][1]-1)%mod;
    if(ans<0) ans+=mod;
    //ans-=mod;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}