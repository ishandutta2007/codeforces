#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<pair<int,int>,null_type,less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> super_set;
#define endl '\n'
const int N = 2e5+7;
const int INF = 1e9;
vector<int> G[N],R[N];
vector<int> V[N];
int dp[N];
bool vis[N];
int val(int v){
    int l = V[v][0]+1,r = V[v][1]+1;
    int base = G[v].size()-V[v].size();
    if (V[v].size()==1){
        return V[v][0]+base+1;
    }
    else{
        return min(V[v].back()+base+1,dp[v]);
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;i+=1){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        R[v].push_back(u);
    }
    set<pair<int,int> > Q;
    memset(dp,-1,sizeof(dp));
    dp[n] = 0;
    Q.insert({dp[n],n});
    int ptr = 1;
    while(!Q.empty()){
        int v = Q.begin()->second;
        vis[v] = 1;
        Q.erase(Q.begin());
        for(int to:R[v]){
            if (vis[to]){
                continue;
            }
            Q.erase({dp[to],to});
            V[to].push_back(dp[v]);
            dp[to] = val(to);
            Q.insert({dp[to],to});
        }
    }
    cout<<dp[1]<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}