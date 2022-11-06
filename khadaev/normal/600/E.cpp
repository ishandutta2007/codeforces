#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1e5 + 10;
int col[N], sz[N], cnt[N];
ll sum[N], ans[N];
int cur_max = 0;

vector<int> e[N];

void dfs_sz(int u, int par) {
    sz[u] = 1;
    for (int v : e[u])
        if (v != par) {
            dfs_sz(v, u);
            sz[u] += sz[v];
        }
}

void add(int u) {
    int c = col[u];
    sum[cnt[c]] -= c;
    ++cnt[c];
    sum[cnt[c]] += c;
    if (cnt[c] > cur_max) cur_max = cnt[c];
}

void dfs_add(int u, int par) {
    for (int v : e[u])
        if (v != par)
            dfs_add(v, u);
    add(u);
}

void rem(int u) {
    int c = col[u];
    sum[cnt[c]] -= c;
    --cnt[c];
    sum[cnt[c]] += c;
    if (sum[cur_max] == 0) --cur_max;
}

void dfs_rem(int u, int par) {
    for (int v : e[u])
        if (v != par)
            dfs_rem(v, u);
    rem(u);
}

void solve(int u, int par, bool keep) {
    int mx = -1, bch = -1;
    for (int v : e[u])
        if (v != par && sz[v] > mx) {
            mx = sz[v];
            bch = v;
        }
    for (int v : e[u])
        if (v != par && v != bch)
            solve(v, u, false);
    if (bch != -1)
        solve(bch, u, true);
    for (int v : e[u])
        if (v != par && v != bch)
            dfs_add(v, u);
    add(u);
    ans[u] = sum[cur_max];
    if (!keep) {
        dfs_rem(u, par);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    sum[0] = 1ll * n * (n + 1) / 2;
    fore(i, 1, n) cnt[i] = 0;
    forn(i, 0, n) cin >> col[i];
    forn(i, 1, n) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].eb(v);
        e[v].eb(u);
    }
    dfs_sz(0, -1);
    solve(0, -1, true);
    forn(i, 0, n) cout << ans[i] << ' ';
}