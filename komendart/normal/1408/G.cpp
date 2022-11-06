//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define sz(a) ((ll)(a).size())
#define X first
#define Y second

using ll = long long;
using ull = unsigned long long;
using dbl = long double;

const int mod = 998244353;
const int maxn = 1505;

int n;
int dsu[maxn];
int rk[maxn];
int dp[maxn][maxn];
int cache[maxn];
vector<int> naive_dsu[maxn];
vector<int> together[maxn];

int find_set(int v) {
    if (v == dsu[v]) return v;
    return dsu[v] = find_set(dsu[v]);
}

int unite(int a, int b) {
    assert(a == find_set(a));
    assert(b == find_set(b));
    if (a == b) return a;
    if (rk[a] < rk[b]) {
        swap(a, b);
    }
    rk[a] += rk[b];
    dsu[b] = a;
    for (auto t: naive_dsu[b]) {
        naive_dsu[a].push_back(t);
    }
    for (auto t: together[b]) {
        together[a].push_back(t);
    }
    sort(together[a].begin(), together[a].end());
    together[a].resize(unique(together[a].begin(), together[a].end()) - together[a].begin());
    naive_dsu[b].clear();
    together[b].clear();
    return a;
}

void init(int n) {
    for (int i = 0; i < n; ++i) {
        dsu[i] = i;
        rk[i] = 1;
        dp[i][1] = 1;
        naive_dsu[i].push_back(i);
        together[i].push_back(i);
    }
}

void solve() {
    cin >> n;
    vector<tuple<int, int, int>> a;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
            if (i < j) {
                a.emplace_back(g[i][j], i, j);
            }
        }
    }
    sort(a.begin(), a.end());
    init(n);
    set<pair<pair<int, int>, pair<int, int>>> cached_pair;
    for (auto [cost, u, v]: a) {
        u = find_set(u);
        v = find_set(v);
        if (u == v) {
            continue;
        }
        if (u > v) {
            swap(u, v);
        }
        auto key = pair<pair<int, int>, pair<int, int>>{{u, rk[u]}, {v, rk[v]}};
        if (!cached_pair.count(key)) {
            int res = cost;
            for (auto i: naive_dsu[u]) {
                for (auto j: naive_dsu[v]) {
                    res = max(res, g[i][j]);
                }
            }
            cache[u] = max(cache[u], res);
            cache[v] = max(cache[v], res);
            cached_pair.insert(key);
        }
        cache[u] = cache[v] = max(cache[u], cache[v]);
        if (cache[v] > cost || cache[u] > cost) {
            together[v].push_back(u);
            together[u].push_back(v);
            continue;
        }
        vector<int> children;
        for (auto i: together[v]) children.push_back(i);
        for (auto i: together[u]) children.push_back(i);
        
        vector<int> d;
        int leader = -1;
        for (auto v: children) {
            v = find_set(v);
            if (d.empty()) {
                d.resize(rk[v] + 1);
                for (int i = 1; i <= rk[v]; ++i) {
                    d[i] = dp[v][i];
                }
                leader = v;
                continue;
            }
            if (v == leader) {
                continue;
            }
            vector<int> newd(rk[leader] + rk[v] + 1);
            for (int a = 1; a <= rk[leader]; ++a) {
                for (int b = 1; b <= rk[v]; ++b) {
                    newd[a + b] += d[a] * dp[v][b];
                    newd[a + b] %= mod;
                }
            }
            leader = unite(leader, v);
            d = newd;
        }
        d[1] = 1;
        for (int i = 1; i < sz(d); ++i) {
            dp[leader][i] = d[i];
        }
    }
    int root = find_set(1);
    for (int k = 1; k <= n; ++k) {
        cout << dp[root][k] << ' ';
    }
}

signed main() {
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    // assert(freopen("output.txt", "w", stdout));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

    int T = 1;
    // cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}