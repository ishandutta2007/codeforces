#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 2e5+7;
const int MOD = 1e9+7;
vector<int> G[N];
ll cnt[N],fact[N],rv[N],res = 0,total = 0;
int sz[N],k;
ll binpow(ll x,int power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power%2){
            x = x*mult%MOD;
        }
        mult = mult*mult%MOD;
        power/=2;
    }
    return x;
}
ll rev(ll x){
    return binpow(x,MOD-2);
}
ll C(int n,int k){
    if (n<0 || k<0 || n<k){
        return 0;
    }
    return fact[n]*rv[k]%MOD*rv[n-k]%MOD;
}
void precalc(int v,int par){
    cnt[v] = 0;
    sz[v] = 1;
    for(int to:G[v]){
        if (to==par) {
            continue;
        }
        precalc(to,v);
        sz[v] += sz[to];
        cnt[v] = (cnt[v]-C(sz[to],k)+MOD)%MOD;
    }
    cnt[v] = (cnt[v]+C(sz[v],k))%MOD;
    total = (total + cnt[v]*sz[v]) % MOD;

}
void dfs(int v,int par){
    res = (res+total)%MOD;
    for(int to:G[v]){
        if (to==par){
            continue;
        }
        ll bt = total;
        ll c1 = cnt[v];
        ll c2 = cnt[to];
        int s1 = sz[v];
        int s2 = sz[to];
        total = (total-cnt[v]*sz[v]%MOD+MOD)%MOD;
        total = (total-cnt[to]*sz[to]%MOD+MOD)%MOD;
        cnt[v] = (cnt[v]+C(sz[to],k))%MOD;
        cnt[v] = (cnt[v]-C(sz[v],k)+MOD)%MOD;
        cnt[to] = (cnt[to]-C(sz[to],k)+MOD)%MOD;
        sz[v] -= sz[to];
        sz[to] += sz[v];
        cnt[v] = (cnt[v]+C(sz[v],k))%MOD;
        cnt[to] = (cnt[to]+C(sz[to],k)-C(sz[v],k)+MOD)%MOD;

        total = (total+cnt[v]*sz[v])%MOD;
        total = (total+cnt[to]*sz[to])%MOD;
        dfs(to,v);
        total = bt;
        cnt[v] = c1;
        cnt[to] = c2;
        sz[v] = s1;
        sz[to] = s2;
    }
}
void solve(){
    int n;
    cin>>n>>k;
    for(int i = 1;i<n;i+=1){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    precalc(1,1);
    dfs(1,1);
    cout<<res<<endl;
}
int main()
{
    fact[0] = 1;
    for(int i = 1;i<N;i+=1){
        fact[i] = fact[i-1]*i%MOD;
    }
    rv[N-1] = rev(fact[N-1]);
    for(int i = N-1;i>0;i-=1){
        rv[i-1] = rv[i]*i%MOD;
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}