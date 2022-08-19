#include <bits/stdc++.h>
struct DisjointSetUnion {
    std::vector<int> fa;
    DisjointSetUnion(int n) : fa(n, -1) {}
    int find(int x) {
        while (fa[x] >= 0 && fa[fa[x]] >= 0)
            x = fa[x] = fa[fa[x]];
        return fa[x] >= 0 ? fa[x] : x;
    }
    bool query(int x, int y) {
        return find(x) == find(y);
    }
    bool join(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (fa[x] > fa[y])
            std::swap(x, y);
        fa[x] += fa[y];
        fa[y] = x;
        return true;
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> m >> n;
    std::vector<int> a(m);
    for (int i = 0; i < m; ++i) std::cin >> a[i];
    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) std::cin >> b[i];
    DisjointSetUnion dsu(n + m);
    int64_t sum = 0;
    std::vector<std::tuple<int, int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int s;
        std::cin >> s;
        for (int j = 0; j < s; ++j) {
            int x;
            std::cin >> x;
            --x;
            sum += a[i] + b[x];
            edges.emplace_back(a[i] + b[x], i + n, x);
        }
    }
    std::sort(edges.begin(), edges.end(), std::greater<>());
    for (auto [w, u, v] : edges) {
        if (dsu.join(u, v)) {
            sum -= w;
        }
    }
    std::cout << sum << "\n";
    
    return 0;
}