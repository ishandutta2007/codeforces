//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll lg = 19;
const ll maxm = 1e7 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, d[maxn], a[maxn], par[lg][maxn], p[maxm], cnt[maxm];
long long ans[maxn];
vector<ll> g[maxn];
vector<pll> q[maxn], vec[maxn];

void dfs(ll v){
    for(ll u : g[v]){
        if(u == par[0][v]) continue;
        d[u] = d[v] + 1;
        par[0][u] = v;
        for(ll i = 1; i < lg; i++){
            par[i][u] = par[i - 1][par[i - 1][u]];
        }
        dfs(u);
    }
    return;
}

ll lca(ll v, ll u){
    if(d[v] < d[u]) swap(v, u);
    ll h = d[v] - d[u];
    for(ll i = 0; i < lg; i++){
        if((h >> i) & 1) v = par[i][v];
    }
    for(ll i = lg; i--;){
        if(d[v] >= (1 << i) && par[i][v] != par[i][u]){
            v = par[i][v];
            u = par[i][u];
        }
    }
    if(v != u) v = par[0][v];
    return v;
}
long long pw(ll pa, ll pb){
    if(pb == 0) return 1;
    long long pc = pw(pa, pb >> 1);
    pc = (pc * pc) % mod;
    if(pb & 1) pc = (pc * pa) % mod;
    return pc;
}
void solve(ll v){
    ll x = a[v];
    while(x != 1){
        ll y = p[x];
        ll z = 1;
        while(x % y == 0){
            x /= y;
            z *= y;
            cnt[z]++;
        }
    }
    for(pll i : q[v]){
        ll e = 1;
        for(pll j : vec[i.F]){
            ll z = 1;
            ll c = 0;
            for(ll k = 1; k <= j.S; k++){
                z *= j.F;
                c += cnt[z];
            }
            e = (e * pw(j.F, c)) % mod;
        }
        if(i.S == 1){
            ans[i.F] = (ans[i.F] * e) % mod;
        }
        else{
            ans[i.F] = (ans[i.F] * pw(e, mod - 2)) % mod;
        }
    }
    for(ll u : g[v]){
        if(u != par[0][v]) solve(u);
    }
    x = a[v];
    while(x != 1){
        ll y = p[x];
        ll z = 1;
        while(x % y == 0){
            x /= y;
            z *= y;
            cnt[z]--;
        }
    }
    return;
}

int main(){
    fast_io;

    for(ll i = 2; i < maxm; i++){
        if(p[i]) continue;
        p[i] = i;
        if(i > 10000) continue;
        for(ll j = i * i; j < maxm; j += i){
            p[j] = i;
        }
    }

    cin >> n;
    for(ll i = 1; i < n; i++){
        ll v, u;
        cin >> v >> u;
        g[v].pb(u);
        g[u].pb(v);
    }
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    dfs(1);
    cin >> m;
    for(ll i = 0; i < m; i++){
        ans[i] = 1;
        ll v, u, x;
        cin >> v >> u >> x;
        ll l = lca(v, u);
        q[v].pb(Mp(i, 1));
        q[u].pb(Mp(i, 1));
        q[l].pb(Mp(i, -1));
        q[par[0][l]].pb(Mp(i, -1));
        while(x != 1){
            ll y = p[x];
            ll z = 0;
            while(x % y == 0){
                x /= y;
                z++;
            }
            if(z){
                vec[i].pb(Mp(y, z));
            }
        }
    }
    solve(1);
    for(ll i = 0; i < m; i++){
        cout << ans[i] << '\n';
    }

    return 0;
}