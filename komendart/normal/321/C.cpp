//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define sz(a) ((ll)(a).size())
#define X first
#define Y second

using ll = long long;
using ull = unsigned long long;
using dbl = long double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll mod) {
    return (ull)rng() % mod;
}

const int maxn = (int) 1e5 + 42;

int n;
vector<int> graph[maxn];
int color[maxn];

unsigned dfs(int v, int p) {
    unsigned merged = 0;
    unsigned twice = 0;
    for (auto to: graph[v]) {
        if (to != p) {
            unsigned t = dfs(to, v);
            twice |= merged & t;
            merged |= t;
        }
    }
    if (twice) {
        int bit = 32 - __builtin_clz(twice);
        merged |= (1 << bit) - 1;
    }
    int bit = __builtin_ctz(~merged);
    color[v] = bit;
    merged ^= 1 << bit;
    merged ^= (1 << bit) - 1;
    return merged;
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) {
        cout << (char)('Z' - color[i]) << ' ';
    }
    cout << '\n';
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