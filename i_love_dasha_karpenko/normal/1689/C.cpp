#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 3e5+7;
vector<int> G[N];
int dp[N],sz[N];
void dfs(int v,int par){
    vector<int> cld;
    sz[v] = 1;
    for(int to:G[v]){
        if (to==par){
            continue;
        }
        cld.push_back(to);
        dfs(to,v);
        sz[v] += sz[to];
    }
    dp[v] = 0;
    if (cld.size()==1){
        dp[v] = sz[cld[0]]-1;
    }
    if (cld.size()==2){
        dp[v] = max(sz[cld[0]]-1+dp[cld[1]],sz[cld[1]]-1+dp[cld[0]]);
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i+=1){
        G[i].clear();
    }
    for(int i = 1;i<n;i+=1){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    cout<<dp[1]<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}