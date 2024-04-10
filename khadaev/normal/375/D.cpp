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
int c[N];
vector<int> e[N];
vector<pair<int, int>> q[N];
int ans[N];
int it[N], sz[N];
map<int, int> cnt[N];
vector<int> atleast[N];

void addTo(int from, int to) {
    for (auto p : cnt[from]) {
        int old_cnt = cnt[to][p.fs];
        int new_cnt = old_cnt + p.sn;
        if ((int)atleast[to].size() <= new_cnt)
            atleast[to].resize(new_cnt + 1);
        for (int i = old_cnt + 1; i <= new_cnt; ++i)
            ++atleast[to][i];
        cnt[to][p.fs] = new_cnt;
    }
}

void dfs(int u, int par) {
    sz[u] = 1;
    int best = -1;
    for (int v : e[u]) {
        if (v == par) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if (best == -1 || sz[v] > sz[best])
            best = v;
    }
    it[u] = u;
    cnt[u][c[u]] = 1;
    atleast[u] = {1, 1};
    if (best != -1) {
        it[u] = it[best];
        for (int v : e[u])
            if (v != par && v != best)
                addTo(it[v], it[u]);
        addTo(u, it[u]);
    }
    for (auto p : q[u]) {
        ans[p.sn] = p.fs >= (int)atleast[it[u]].size() ? 0 : atleast[it[u]][p.fs];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    forn(i, 0, n) cin >> c[i];
    forn(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].eb(v);
        e[v].eb(u);
    }
    forn(i, 0, m) {
        int v, k;
        cin >> v >> k;
        --v;
        q[v].eb(k, i);
    }
    dfs(0, -1);
    forn(i, 0, m) cout << ans[i] << ' ';
}