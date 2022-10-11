//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 4e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define lc (id << 1)
#define rc (id << 1 | 1)

ll n, a[maxn], b[maxn];
bool vis[maxn];
vector<pll> g[maxn];
vector<ll> vec;

void bld(ll id, ll s, ll e){
    g[id].resize(e - s);
    if(e - s == 1){
        g[id][0] = Mp(b[s], s);
        return;
    }
    ll mid = (s + e) / 2;
    bld(lc, s, mid);
    bld(rc, mid, e);
    merge(g[lc].begin(), g[lc].end(), g[rc].begin(), g[rc].end(), g[id].begin());
    return;
}

void dfs(ll v);

void solve(ll id, ll s, ll e, ll l, ll r, ll x){
    if(r <= s || e <= l) return;
    if(l <= s && e <= r){
        while(!g[id].empty() && g[id].back().F >= x){
            ll v = g[id].back().S;
            g[id].pop_back();
            dfs(v);
        }
        return;
    }
    ll mid = (s + e) >> 1;
    solve(lc, s, mid, l, r, x);
    solve(rc, mid, e, l, r, x);
    return;
}

void dfs(ll v){
    if(vis[v]) return;
    vis[v] = 1;
    dfs(b[v]);
    solve(1, 0, n, 0, a[v], v);
    vec.pb(v);
    return;
}
int main(){
    fast_io;

    cin >> n;
    fill(b, b + n, n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == -1) a[i] = n + 1;
        a[i]--;
        b[a[i]] = i;
    }
    bld(1, 0, n);
    vis[n] = 1;
    for(ll i = 0; i < n; i++){
        dfs(i);
    }
    for(ll i = 0; i < n; i++){
        a[vec[i]] = i + 1;
    }
    for(ll i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}