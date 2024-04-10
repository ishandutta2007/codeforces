#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9 + 7;
const ll PI = cos(-1.0);
const ll inf = 0x3f3f3f3f3f3f3f3f;

vector<ll> g[N];
ll col[N];
ll fa[N], son[N], siz[N];
ll ans[N], cnt[N], mx, exc, sum;

void dfs1(ll u, ll f) {
    siz[u] = 1;
    fa[u] = f;
    son[u] = -1;
    for (auto v:g[u]) {
        if (v == f) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if (son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
    }
}

void add(ll u, ll val) {
    cnt[col[u]] += val;
    if (cnt[col[u]] > mx) mx = cnt[col[u]], sum = col[u];
    else if (cnt[col[u]] == mx) sum += col[u];
    for (auto x:g[u]) {
        if (x == fa[u] || x == exc) continue;
        add(x, val);
    }
}

void dfs(ll u, ll opt) {
    for (auto x:g[u]) {
        if (x == fa[u] || x == son[u]) continue;
        dfs(x, 0);
    }
    if (son[u] != -1) dfs(son[u], 1), exc = son[u];
    add(u, 1);
    exc = 0;
    ans[u] = sum;
    if (!opt) add(u, -1), mx = sum = 0;
}

int main() {
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> col[i];
    for (ll i = 1; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1, -1);
    dfs(1, 0);
    for (ll i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}