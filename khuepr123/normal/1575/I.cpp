/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")*/
// only when really needed

/* GNU G++17 7.3.0: No long long for faster code
   GNU G++17 9.2.0 (64 bit, msys 2): Long long only for faster code */
 
#include <bits/stdc++.h>
  
#define for1(i,a,b) for (int i = a; i <= b; i++)
#define for2(i,a,b) for (int i = a; i >= b; i--)
#define int long long

#define sz(a) (int)a.size()
#define pii pair<int,int>
#define pb push_back
 
/*
__builtin_popcountll(x) : Number of 1-bit
__builtin_ctzll(x) : Number of trailing 0
*/
 
#define PI 3.1415926535897932384626433832795
#define INF 1000000000000000000
#define MOD 998244353
#define MOD2 1000000009
#define EPS 1e-6

using namespace std;

int n, q;
int a[100005], fentree[100005];
int par[100005], tin[100005], tout[100005], up[100005][17], now;
vector<int> g[100005];

void update(int i, int val) {
    for (; i <= n; i += i & -i) fentree[i] += val;
}

int get(int i) {
    int res = 0;
    for (; i; i -= i & -i) res += fentree[i];
    return res;
}

void dfs(int u, int p) {
    tin[u] = ++now;
    for1(i,1,16) up[u][i] = up[up[u][i - 1]][i - 1];

    for (auto v : g[u]) if (v != p) {
        par[v] = u;
        up[v][0] = u;
        dfs(v, u);
    }
    tout[u] = now;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    for2(i,16,0) if (!is_ancestor(up[u][i], v)) u = up[u][i];
    return up[u][0];
}

int query(int u, int v) {
    if (tin[u] > tin[v]) swap(u, v);
    int x = lca(u, v);

    if (u == v) return 0;

    if (is_ancestor(u, v)) return (get(tin[v]) - (u == 1 ? 0 : get(tin[par[u]]))) * 2 - a[u] - a[v];
    return (get(tin[u]) + get(tin[v]) - get(tin[x]) - (x == 1 ? 0 : get(tin[par[x]]))) * 2 - a[u] - a[v];
}

signed main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // freopen("cf.inp", "r", stdin);
    // freopen("cf.out", "w", stdout);

    cin >> n >> q;

    for1(i,1,n) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }

    for1(i,1,n - 1) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }    

    tin[0] = -INF; tout[0] = INF;
    dfs(1, 0);

    for1(i,1,n) {
        update(tin[i], a[i]);
        update(tout[i] + 1, -a[i]);
    }

    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            y = abs(y);
            update(tin[x], y - a[x]);
            update(tout[x] + 1, a[x] - y);
            a[x] = y;
        }
        else cout << query(x, y) << "\n";
    }
}