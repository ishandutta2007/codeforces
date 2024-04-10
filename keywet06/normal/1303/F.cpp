#include <bits/stdc++.h>

const std::vector<std::pair<int, int>> V{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

struct DSU {
    std::vector<int> fa;
    DSU(int n) : fa(n, -1) {}
    int find(int x) {
        while (fa[x] >= 0 && fa[fa[x]] >= 0) x = fa[x] = fa[fa[x]];
        return fa[x] >= 0 ? fa[x] : x;
    }
    bool query(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (fa[x] > fa[y]) std::swap(x, y);
        fa[x] += fa[y];
        fa[y] = x;
        return true;
    }
};

int n, m, q;

std::vector<int> sum;
std::vector<std::vector<int>> a;
std::vector<std::vector<std::tuple<int, int, int>>> inverse;

bool isLegal(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> q;
    a.assign(n, std::vector<int>(m));
    sum.resize(q);
    DSU t(n * m);
    int now = 0;
    sum[0] = n * m - 1;
    for (int i = 0; i < q; ++i) {
        int x, y, c;
        std::cin >> x >> y >> c, --x, --y;
        if (c > now) {
            now = c;
            inverse.resize(c + 1);
            t.fa.assign(n * m, -1);
        }
        if (a[x][y] != c) {
            inverse[a[x][y]].emplace_back(i, x, y);
            a[x][y] = c;
        }
        for (auto [dx, dy] : V) {
            int x1 = x + dx, y1 = y + dy;
            sum[i] += isLegal(x1, y1) && a[x1][y1] == c &&
                      t.merge(x * m + y, x1 * m + y1);
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) inverse[a[i][j]].emplace_back(-1, i, j);
    for (int i = 0; i <= now; ++i) {
        a.assign(n, std::vector<int>(m, -1));
        std::reverse(inverse[i].begin(), inverse[i].end());
        t.fa.assign(n * m, -1);
        for (auto [id, x, y] : inverse[i]) {
            for (auto [dx, dy] : V) {
                int x1 = x + dx, y1 = y + dy;
                sum[id] -= isLegal(x1, y1) && a[x1][y1] == i &&
                           t.merge(x * m + y, x1 * m + y1) && id != -1;
            }
            a[x][y] = i;
        }
    }
    for (int i = 1; i < q; ++i) sum[i] += sum[i - 1];
    for (int i : sum) std::cout << n * m - i << "\n";
    return 0;
}