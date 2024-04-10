// llll
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
constexpr int C = 1 << 18;
struct DSU {
    std::vector<int> fa;
    void init(int n) {
        fa.assign(n, -1);
    }
    int find(int x) {
        while (fa[x] >= 0 && fa[fa[x]] >= 0)
            x = fa[x] = fa[fa[x]];
        return fa[x] >= 0 ? fa[x] : x;
    }
    bool query(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
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
} tree;
int n, cnt;
std::vector<int> a;
std::vector<std::pair<int, int>> edge;
struct Data {
    int p1, p2;
    void init() {
        p1 = p2 = -1;
    }
    void update(int i) {
        if (i == -1)
            return;
        if (p1 == -1) {
            p1 = i;
        } else if (tree.find(p1) == tree.find(i)) {
            if (a[i] > a[p1])
                p1 = i;
        } else if (p2 == -1 || a[i] > a[p2]) {
            p2 = i;
            if (a[p2] > a[p1])
                std::swap(p1, p2);
        }
    }
};
Data f[C];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    ++n;
    a.resize(n);
    for (int i = 1; i < n; ++i)
        std::cin >> a[i];
    long long ans = 0;
    tree.init(n);
    cnt = n;
    while (cnt > 1) {
        for (int i = 0; i < C; ++i)
            f[i].init();
        for (int i = 0; i < n; ++i)
            f[a[i]].update(i);
        for (int i = 0; i < C; ++i) {
            for (int j = 0; j < 18; ++j) {
                if (i >> j & 1) {
                    f[i].update(f[i ^ 1 << j].p1);
                    f[i].update(f[i ^ 1 << j].p2);
                }
            }
        }
        edge.assign(n, {-1, -1});
        for (int i = 0; i < n; ++i) {
            int t = (C - 1) ^ a[i], v = -1, rt = tree.find(i);
            if (f[t].p1 != -1 && tree.find(f[t].p1) != rt) {
                v = f[t].p1;
            } else {
                v = f[t].p2;
            }
            if (v != -1) {
                auto &[u0, v0] = edge[rt];
                if (u0 == -1 || a[u0] + a[v0] < a[i] + a[v]) {
                    u0 = i;
                    v0 = v;
                }
            }
        }
        for (auto [u, v] : edge) {
            if (u != -1 && tree.merge(u, v)) {
                ans += a[u] + a[v];
                --cnt;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        ans -= a[i];
    std::cout << ans << "\n";
    return 0;
}