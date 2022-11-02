#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(n));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u][v] = true;
        g[v][u] = true;
    }
    bool bipartition = true;
    int conn = 0;
    vector<int> color(n, -1);
    function<void(int)> dfs = [&](int u) {
        for (int v = 0; v < n; ++v) {
            if (!g[u][v]) continue;
            if (color[v] == color[u]) bipartition = false;
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                dfs(v);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            color[i] = 0;
            ++conn;
            dfs(i);
        }
    }
    int iso = 0;
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (g[i][j]) ok = false;
        }
        if (ok) ++iso;
    }
    int64 ans = 0;
    ans += 1ll << n;
    ans -= 1ll << conn;
    if (bipartition) ans += 1ll << conn;
    ans += 1ll << iso + 1;
    if (m == 0) ans -= 1ll << n;
    int n1 = n / 2, n2 = n - n1;
    vector<int> Ca(1 << n1);
    Ca[0] = (1 << n2) - 1;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            if (!g[i][j + n1]) Ca[1 << i] |= 1 << j;
        }
    }
    for (int i = 1; i < 1 << n1; ++i) {
        if ((i & -i) == i) continue;
        int u = 0;
        while (~i >> u & 1) ++u;
        Ca[i] = Ca[i ^ 1 << u];
        for (int v = 0; v < n1; ++v) {
            if (g[u][v] && (i >> v & 1)) Ca[i] = -1;
        }
        if (Ca[i] != -1) Ca[i] = Ca[1 << u] & Ca[i ^ 1 << u];
    }
    vector<int> cnt(1 << n2);
    cnt[0] = 1;
    for (int i = 1; i < 1 << n2; ++i) {
        int u = 0;
        while (~i >> u & 1) ++u;
        cnt[i] = cnt[i ^ 1 << u];
        for (int v = 0; v < n2; ++v) {
            if (g[u + n1][v + n1] && (i >> v & 1)) cnt[i] = 0;
        }
    }
    for (int i = 1; i < 1 << n2; i <<= 1) {
        for (int j = 0; j < 1 << n2; ++j) {
            if (~j & i) cnt[i | j] += cnt[j];
        }
    }
    int64 res = 0;
    for (int i = 0; i < 1 << n1; ++i) {
        if (Ca[i] != -1) res += cnt[Ca[i]];
    }
    ans -= res << 1;
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
    return 0;
}