#include <bits/stdc++.h>

using int64 = long long;

struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::array<int, 3>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w, --u, --v;
        edges[i] = {w, u, v};
    }
    int p, k, a, b, c;
    std::cin >> p >> k >> a >> b >> c;
    std::vector<int> q(k);
    for (int i = 0; i < p; ++i) std::cin >> q[i];
    for (int i = p; i < k; ++i) q[i] = (1LL * a * q[i - 1] + b) % c;
    std::sort(q.begin(), q.end());
    std::vector<int> e{0};
    std::sort(edges.begin(), edges.end());
    for (int i = 0; i < m; ++i) {
        for (int j = i; j < m; ++j) e.push_back((edges[i][0] + edges[j][0] + 1) / 2);
    }
    std::sort(e.begin(), e.end());
    int64 coef = 0, cons = 0;
    int64 ans = 0;
    for (int i = 0, j = 0; i < k; ++i) {
        int oj = j;
        while (j < int(e.size()) && q[i] >= e[j]) ++j;
        if (oj != j) {
            std::sort(edges.begin(), edges.end(), [&](auto a, auto b) {
                int x = std::abs(a[0] - e[j - 1]);
                int y = std::abs(b[0] - e[j - 1]);
                return x != y ? x < y : a[0] > b[0];
            });
            coef = cons = 0;
            DSU g(n);
            for (auto [w, u, v] : edges) {
                if (g.merge(u, v)) {
                    if (w > e[j - 1]) {
                        --coef;
                        cons += w;
                    } else {
                        ++coef;
                        cons -= w;
                    }
                }
            }
        }
        ans ^= coef * q[i] + cons;
    }
    std::cout << ans << "\n";
    return 0;
}