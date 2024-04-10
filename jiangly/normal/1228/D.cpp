#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
const int MAX_N = 100000;
int n, m;
set<int> g[MAX_N];
int color[MAX_N];
int cnt[3];
void solve(int case_id) {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (u > v)
            swap(u, v);
        g[u].insert(v);
    }
    color[0] = 1;
    for (int i = 1; i < n; ++i)
        if (g[0].count(i) == 0)
            color[i] = 1;
    int u = 0;
    while (u < n && color[u] == 1)
        ++u;
    if (u == n) {
        cout << "-1\n";
        return;
    }
    color[u] = 2;
    for (int i = u + 1; i < n; ++i)
        if (color[i] == 0 && g[u].count(i) == 0)
            color[i] = 2;
    for (int i = 0; i < n; ++i)
        ++cnt[color[i]];
    
    if (cnt[0] == 0 || m != 1ll * cnt[0] * cnt[1] + 1ll * cnt[1] * cnt[2] + 1ll * cnt[0] * cnt[2]) {
        cout << "-1\n";
        return;
    }
    for (int u = 0; u < n; ++u)
        for (int v : g[u])
            if (color[u] == color[v]) {
                cout << "-1\n";
                return;
            }
    for (int i = 0; i < n; ++i)
        cout << color[i] + 1 << " \n"[i == n - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; ++i)
        solve(i);
    return 0;
}