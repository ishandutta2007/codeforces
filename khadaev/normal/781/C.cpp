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

const int N = 2e5 + 10;
vector<int> e[N];
char used[N];
vector<int> path;

void dfs(int u) {
    used[u] = 1;
    path.eb(u);
    for (int v : e[u]) {
        if (!used[v]) {
            dfs(v);
            path.eb(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    forn(i, 0, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].eb(v);
        e[v].eb(u);
    }
    dfs(0);
    int cnt = (2 * n + k - 1) / k;
    vector<vector<int>> ans(k);
    int ix = 0;
    for (auto u : path) {
        if (ans[ix].size() == cnt) ++ix;
        ans[ix].eb(u);
    }
    forn(i, 0, k) {
        if (ans[i].empty()) {
            cout << "1 1\n";
            continue;
        }
        cout << ans[i].size() << ' ';
        for (int u : ans[i]) cout << 1 + u << ' ';
        cout << '\n';
    }
}