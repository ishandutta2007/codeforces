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
int ans = 0;
int cols[N];

void dfs(int u, int col, int prv, int par) {
    cols[u] = col;
    int nxt = 0;
    for (int v : e[u]) {
        if (v == par) continue;
        while (nxt == col || nxt == prv) {
            ++nxt;
            if (nxt == ans) nxt = 0;
        }
        dfs(v, nxt, col, u);
        ++nxt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    forn(i, 1, n) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].eb(v);
        e[v].eb(u);
    }
    forn(i, 0, n) ans = max(ans, (int)e[i].size());
    ++ans;
    cout << ans << '\n';
    dfs(0, 0, -1, -1);
    forn(i, 0, n) cout << 1 + cols[i] << ' ';

}