#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(n));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u][v] = true;
        g[v][u] = true;
    }
    bool bipartition = true;
    int conn = 0;
    vector<int> color(n, -1);
    function<void(int)> dfs = [&](int u) {
        for (int v = 0; v < n; ++v) {
            if (!g[u][v])
                continue;
            if (color[v] == color[u])
                bipartition = false;
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                dfs(v);
            }
        }
    };
    for (int i = 0; i < n; ++i)
        if (color[i] == -1) {
            color[i] = 0;
            ++conn;
            dfs(i);
        }
    int iso = 0;
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j < n; ++j)
            if (g[i][j])
                ok = false;
        if (ok)
            ++iso;
    }
    LL ans = 0;
    // {0, 1, 2}
    ans += 1ll << n;
    // {0, 2}
    ans -= 1ll << conn;
    // {1}
    if (bipartition)
        ans += 1ll << conn;
    // {0} and {2}
    ans += 1ll << iso + 1;
    // {}
    if (m == 0)
        ans -= 1ll << n;
    // {0, 1} and {1, 2}
    int n1 = n / 2, n2 = n - n1;
    vector<int> can_add(1 << n1);
    can_add[0] = (1 << n2) - 1;
    for (int i = 0; i < n1; ++i)
        for (int j = 0; j < n2; ++j)
            if (!g[i][j + n1])
                can_add[1 << i] |= 1 << j;
    for (int i = 1; i < 1 << n1; ++i) {
        if ((i & -i) == i)
            continue;
        int u = 0;
        while (~i >> u & 1)
            ++u;
        can_add[i] = can_add[i ^ 1 << u];
        for (int v = 0; v < n1; ++v)
            if (g[u][v] && (i >> v & 1))
                can_add[i] = -1;
        if (can_add[i] != -1)
            can_add[i] = can_add[1 << u] & can_add[i ^ 1 << u];
    }
    vector<int> cnt(1 << n2);
    cnt[0] = 1;
    for (int i = 1; i < 1 << n2; ++i) {
        int u = 0;
        while (~i >> u & 1)
            ++u;
        cnt[i] = cnt[i ^ 1 << u];
        for (int v = 0; v < n2; ++v)
            if (g[u + n1][v + n1] && (i >> v & 1))
                cnt[i] = 0;
    }
    for (int i = 1; i < 1 << n2; i <<= 1)
        for (int j = 0; j < 1 << n2; ++j)
            if (~j & i)
                cnt[i | j] += cnt[j];
    LL res = 0;
    for (int i = 0; i < 1 << n1; ++i)
        if (can_add[i] != -1)
            res += cnt[can_add[i]];
    ans -= res << 1;
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}