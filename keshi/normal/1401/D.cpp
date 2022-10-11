//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll t, n, m, a[maxn], b[maxn], sz[maxn], ans;
vector<ll> g[maxn];
bool vis[maxn];

void dfs(ll v){
    vis[v] = 1;
    for(ll u : g[v]){
        if(vis[u]) continue;
        dfs(u);
        sz[v] += sz[u];
        b[u - 2] = sz[u] * (n - sz[u]);
    }
    return;
}

int main(){
    fast_io;

    cin >> t;
    while(t--){
        ans = 0;
        cin >> n;
        for(ll i = 1; i <= n; i++){
            sz[i] = 1;
            vis[i] = 0;
            g[i].clear();
        }
        for(ll i = 1; i < n; i++){
            ll v, u;
            cin >> v >> u;
            g[v].pb(u);
            g[u].pb(v);
        }
        cin >> m;
        for(ll i = 0; i < m; i++){
            cin >> a[i];
        }
        dfs(1);
        sort(a, a + m, greater<ll>());
        sort(b, b + n - 1, greater<ll>());
        while(m < n - 1){
            a[m++] = 1;
        }
        for(ll i = 1; i < n - 1; i++){
            ans = (ans + a[m - n + 1 + i] * b[i]) % mod;
        }
        ll p = 1;
        for(ll i = 0; i < m - n + 2; i++){
            p = (p * a[i]) % mod;
        }
        ans = (ans + p * b[0]) % mod;
        cout << ans << '\n';
    }

    return 0;
}