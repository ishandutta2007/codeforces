//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define gi(x) int(x-'a')
const int N = 3e3+7;
const ll INF =-1e18;
pair<int,ll> dp[N][N],ndp[N];
int sz[N],A[N];
vector<int> G[N];
int n,m;
const pair<int,ll> operator + (const pair<int,ll> &a,const pair<int,ll> &b){
    return {a.first+b.first,a.second+b.second};
}
pair<int,ll> trans(pair<int,ll> a){
    a.first+=a.second>0;
    a.second = 0;
    return a;
}
void dfs(int v,int par){
    sz[v] = 1;
    dp[v][0] = {0,A[v]};
    for(int to:G[v]){
        if (to==par)
            continue;
        dfs(to,v);

        for(int w = 0;w<min(m,sz[v]);++w){
            for(int add = 0;w+add<m && add<min(m,sz[to]);++add){
                ndp[w+add] = max(ndp[w+add],dp[v][w]+dp[to][add]);
                if (w+add<n)
                    ndp[w+add+1] = max(ndp[w+add+1],dp[v][w]+trans(dp[to][add]));
            }
        }
        sz[v]+=sz[to];
        for(int w = 0;w<min(m,sz[v]);++w){
            dp[v][w] = ndp[w];
            ndp[w] = {-INF,-INF};
        }
    }

}
void solve(){

    cin>>n>>m;
    for(int i = 0;i<=m;++i){
        ndp[i] = {-INF,-INF};
    }
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        A[i] = -A[i];
    }
    for(int i = 1;i<=n;++i){
        int val;
        cin>>val;
        A[i]+=val;
    }
    for(int i = 1;i<n;++i){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    cout<<trans(dp[1][m-1]).first<<endl;
    for(int i = 1;i<=n;++i)
        G[i].clear();
}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while (t--)
        solve();

    return 0;
}