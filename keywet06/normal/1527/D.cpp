#include <bits/stdc++.h>

using int64 = long long;

const int N = 200005;

int T, n, x, y, u, v, p;
int fa[N], size[N], used[N];

int64 sx, sy, ans;

std::vector<int> to[N];

inline int64 sqr(int64 x) { return x * x; }

inline void dfs(int u, int f) {
    fa[u] = f, size[u] = 1;
    for (int v : to[u]) {
        if (v == f) continue;
        dfs(v, u), size[u] += size[v];
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 0; i < n; ++i) to[i].clear(), used[i] = 0;
        for (int i = 1; i < n; ++i) {
            std::cin >> x >> y;
            to[x].push_back(y), to[y].push_back(x);
        }
        dfs(0, 0), ans = 0;
        for (int v : to[0]) ans += sqr(size[v]) - size[v];
        std::cout << ans / 2 << ' ', used[x = y = 0] = 1;
        u = 1;
        while (fa[u]) u = fa[u];
        size[u] -= p = size[1];
        ans = sqr(n - p) - (n - p);
        for (int v : to[0]) ans -= sqr(size[v]) - size[v];
        std::cout << ans / 2;
        size[v = u] += p, used[u = 1] = 1;
        while (fa[u]) used[u = fa[u]] = 1;
        sx = size[x = 1], sy = n - size[v];
        for (int i = 2; i < n; ++i) {
            if (!used[u = i]) {
                while (!used[fa[u]]) u = fa[u];
                if (fa[u] != x) std::swap(x, y), std::swap(sx, sy);
                if (fa[u] != x) {
                    std::cout << ' ' << sx * sy;
                    for (++i; i < n; ++i) std::cout << ' ' << 0;
                    break;
                }
                sx -= size[i];
                std::cout << ' ' << sx * sy;
                sx = size[u = x = i];
                while (!used[u]) used[u] = 1, u = fa[u];
            } else {
                std::cout << ' ' << 0;
            }
        }
        ans = 0;
        for (int i = 0; i < n; ++i) ans += used[i];
        std::cout << ' ' << (ans == n) << std::endl;
    }
    return 0;
}