#include <bits/stdc++.h>

using int64 = long long;

const int N = 300005;

int64 now = 0;
int64 fa[N], deg[N], dp1[N];

std::vector<int64> e[N], v[N];

inline void dfs(int64 u, int64 f) {
    fa[u] = f, dp1[u] = 1;
    for (auto v : e[u]) {
        if (v != f) dfs(v, u), dp1[u] = std::max(dp1[v] + 1, dp1[u]);
    }
}

int64 cnt[N][22], a[N], k, s, mx[N];

inline void updmx(int64 x, int64 y) {
    if (!x) return;
    if (mx[x] < y) s += y - mx[x], mx[x] = y, updmx(fa[x], y);
}

inline int64 cal(int64 x) {
    int64 sum = 0;
    for (int64 i = 20; i >= 0; --i) {
        sum += cnt[x][i];
        if (sum >= k) return i + 1;
    }
    return 1;
}

inline void upda(int64 x) {
    if (!x) return;
    int64 y = cal(x);
    if (y <= a[x]) return;
    --cnt[fa[x]][a[x]];
    a[x] = y;
    updmx(x, y);
    ++cnt[fa[x]][a[x]];
    int64 sum = 0;
    for (int64 i = 20; i >= 0; --i) {
        sum += cnt[fa[x]][i];
        if (fa[x]) v[sum].push_back(fa[x]);
        if (sum >= k) {
            upda(fa[x]);
            break;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int64 n;
    std::cin >> n;
    for (int64 i = 1; i < n; ++i) {
        int64 u, v;
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int64 i = 1; i <= n; ++i) ++deg[fa[i]];
    for (int64 i = 1; i <= n; ++i) v[deg[i]].push_back(i);
    int64 ans = 0;
    for (int64 i = 1; i <= n; ++i) ans += dp1[i], ++cnt[fa[i]][1];
    s = n;
    for (int64 i = 1; i <= n; ++i) mx[i] = a[i] = 1;
    for (int64 i = n; i >= 2; --i) {
        k = i;
        for (int64 x = 0; x < v[i].size(); ++x) upda(v[i][x]);
        ans += s;
    }
    std::cout << ans << std::endl;
    return 0;
}