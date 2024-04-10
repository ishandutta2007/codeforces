//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 2e5+7;
vector<int> G[N];
vector<int> path;
int depth[N];
void dfs(int v,int par){
    depth[v] = depth[par]+1;
    for(int to:G[v]){
        if (to==par)
            continue;
        dfs(to,v);
    }
    path.push_back(v);
}
vector<pair<int,int> > Q[N];
int ans[N],dp[N],vis[N],base[N];
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
    int q;
    cin>>q;
    for(int i = 1;i<=q;++i){
        int v,k;
        cin>>v>>k;
        k = min(k,n);
        Q[k].push_back({v,i});
    }
    for(int k = 0;k<=n;++k){
        vector<int> np;
        for(int v:path){
            vis[v] = 0;
            dp[v] = 0;
            vector<int> gg;
            for(int to:G[v]){
                if (depth[to]<depth[v])
                    continue;

                if (dp[to]-k>1){
                    vis[v] = 1;
                    dp[v]+=dp[to]-k;
                    gg.push_back(to);
                }
                else ++base[v];
            }
            G[v] = gg;
            dp[v]+=base[v];
            if (vis[v])
                np.push_back(v);
        }
        path = np;
        assert(k==0 || n/k+5>np.size());
        for(auto [v,pos]:Q[k]){
            ans[pos] = dp[v];
        }
    }
    for(int i = 1;i<=q;++i)
        cout<<ans[i]<<'\n';
}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;


    while(t--)
        solve();

}