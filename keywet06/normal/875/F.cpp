#include <bits/stdc++.h>

const int N = 200000;

struct Edge {
    int x, y, w;
} e[N + 5];

int n, m, ans, f[N + 5], s[N + 5];

int Find(int k) { return f[k] ? f[k] = Find(f[k]) : k; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i) std::cin >> e[i].x >> e[i].y >> e[i].w;
    std::sort(e + 1, e + m + 1, [](Edge a, Edge b) { return a.w > b.w; });
    for (int i = 1; i <= n; ++i) s[i] = 1;
    for (int i = 1; i <= m; ++i) {
        if (Find(e[i].x) != Find(e[i].y)) {
            s[Find(e[i].x)] += s[Find(e[i].y)];
            f[Find(e[i].y)] = Find(e[i].x);
        }
        if (s[Find(e[i].x)]) ans += e[i].w, --s[Find(e[i].x)];
    }
    std::cout << ans << '\n';
    return 0;
}