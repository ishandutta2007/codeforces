#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define int long long
const int N = 2e5+7;
const int INF = 1e9;
vector<int> G[N];
int dp[N][3];
void dfs(int v,int par){
    int sum01 = 0,sum0 = 0,sumall = 0;
    dp[v][0] = dp[v][1] = dp[v][2] = INF;

    for(int to:G[v]){
        if (to==par)
            continue;

        dfs(to,v);
        sum01+=min(dp[to][0],dp[to][1]);
        sum0+=dp[to][0];
        sumall+=min({dp[to][0],dp[to][2]});
    }
    for(int to:G[v]){
        if (to==par)
            continue;
        dp[v][0] = min(dp[v][0],dp[to][1]+sum01-min(dp[to][1],dp[to][0])-1);
    }
    dp[v][1] = min(dp[v][1],sum0+1);
    for(int to:G[v]){
        if (to==par)
            continue;
        dp[v][2] = min(dp[v][2],dp[to][2]+sumall-min(dp[to][2],dp[to][0]));
    }
    dp[v][2] = min(dp[v][2],sum0+1);

}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<n;++i){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1,1);
    cout<<dp[1][2]<<endl;
    for(int i = 1;i<=n;++i)
        G[i].clear();
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}