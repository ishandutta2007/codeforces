//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 100+7;
const ll MOD = 1E9+7;
ll res = 0,fact[N],rev[N],dp[N][N];
vector<int> G[N];
int timer = 0,cnt[N],tin[N],depth[N],sum[N];
void add(int pos,int val){
    if (tin[pos]!=timer){
        tin[pos] = timer;
        cnt[pos] = 0;
    }
    cnt[pos]+=val;
}
int get(int pos){
    if (tin[pos]!=timer){
        tin[pos] = timer;
        cnt[pos] = 0;
    }
    return cnt[pos];
}
void dfs(int v,int par){
    depth[v] = depth[par]+1;
    add(depth[v],1);
    for(int to:G[v]){
        if (to==par)
            continue;
        dfs(to,v);
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<n;++i){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    res = 0;
    for(int root = 1;root<=n;++root){
        if (G[root].size()<k)
            continue;
        for(int i = 0;i<=n;++i) {
            for (int j = 1; j <= k; ++j)
                dp[i][j] = 0;
            dp[i][0] = 1;
            sum[i] = 0;
        }

        depth[root] = 0;
        for(int v:G[root]){
            ++timer;
            dfs(v,root);
            for(int dep = 1;dep<=n;++dep){
                if (get(dep)==0)
                    continue;
                for(int ct = min(k-1,sum[dep]);ct>=0;--ct){
                    dp[dep][ct+1] = (dp[dep][ct+1]+dp[dep][ct]*get(dep))%MOD;
                }
                sum[dep] = min(sum[dep]+1,k);
            }
        }
        for(int dep = 1;dep<=n;++dep)
            res = (res+dp[dep][k])%MOD;
    }
    if (k==2){
        res = ll(n)*(n-1)/2%MOD;
    }
    if (k==1){
        res = n;
    }
    cout<<res<<endl;
    for(int i = 1;i<=n;++i)
        G[i].clear();
}
ll binpow(ll x,int power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)
            x = x*mult%MOD;
        mult = mult*mult%MOD;
        power = power>>1;
    }
    return x;
}
int main()
{
    fact[0] = rev[0] = 1;
    for(int i = 1;i<N;++i){
        fact[i] = fact[i-1]*i%MOD;
        rev[i] = binpow(fact[i],MOD-2);
    }
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    //t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}