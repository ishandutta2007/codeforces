#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
int n, m, q;
bool rotated;
std::vector<std::vector<int>> l, r, faL, faR;
struct Data {
    int d, x, y;
    Data(int d, int x, int y) : d(d), x(x), y(y) {
        if (rotated)
            std::swap(this -> x, this -> y);
    }
    friend bool operator<(const Data &lhs, const Data &rhs) {
        if (lhs.d != rhs.d)
            return lhs.d < rhs.d;
        if (lhs.x != rhs.x)
            return lhs.x < rhs.x;
        return lhs.y < rhs.y;
    }
};
int find(std::vector<std::vector<int>> &fa, int x, int y) {
    while (fa[x][y] >= 0 && fa[x][fa[x][y]] >= 0)
        y = fa[x][y] = fa[x][fa[x][y]];
    if (fa[x][y] >= 0)
        return fa[x][y];
    return y;
}
void merge(std::vector<std::vector<int>> &fa, std::vector<std::vector<int>> &g, int x, int y0, int y1) {
    y0 = find(fa, x, y0);
    y1 = find(fa, x, y1);
    g[x][y0] = g[x][y1];
    if (fa[x][y0] > fa[x][y1])
        std::swap(y0, y1);
    fa[x][y0] += fa[x][y1];
    fa[x][y1] = y0;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> q;
    if (n > m) {
        std::swap(n, m);
        rotated = true;
    }
    l.assign(n, std::vector<int>(m));
    r.assign(n, std::vector<int>(m));
    faL.assign(n, std::vector<int>(m, -1));
    faR.assign(n, std::vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        std::iota(l[i].begin(), l[i].end(), 0);
        std::iota(r[i].begin(), r[i].end(), 0);
    }
    for (int i = 0; i < q; ++i) {
        int x0, y0;
        std::cin >> x0 >> y0;
        --x0;
        --y0;
        if (rotated)
            std::swap(x0, y0);
        Data ans(10000, 10000, 10000);
        for (int dx = 0; dx <= ans.d && dx < n; ++dx) {
            int xl = x0 - dx, xr = x0 + dx;
            if (xl >= 0) {
                int yl = l[xl][find(faL, xl, y0)];
                int yr = r[xl][find(faR, xl, y0)];
                if (yl != -1)
                    ans = std::min(ans, Data(dx + y0 - yl, xl, yl));
                if (yr != -1)
                    ans = std::min(ans, Data(dx + yr - y0, xl, yr));
            }
            if (xr < n) {
                int yl = l[xr][find(faL, xr, y0)];
                int yr = r[xr][find(faR, xr, y0)];
                if (yl != -1)
                    ans = std::min(ans, Data(dx + y0 - yl, xr, yl));
                if (yr != -1)
                    ans = std::min(ans, Data(dx + yr - y0, xr, yr));
            }
        }
        std::cout << ans.x + 1 << " " << ans.y + 1 << "\n";
        if (rotated)
            std::swap(ans.x, ans.y);
        if (ans.y == 0) {
            l[ans.x][find(faL, ans.x, ans.y)] = -1;
        } else {
            merge(faL, l, ans.x, ans.y, ans.y - 1);
        }
        if (ans.y == m - 1) {
            r[ans.x][find(faR, ans.x, ans.y)] = -1;
        } else {
            merge(faR, r, ans.x, ans.y, ans.y + 1);
        }
    }
    return 0;
}