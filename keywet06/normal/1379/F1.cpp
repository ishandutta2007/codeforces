#include <bits/stdc++.h>

struct SegmentTree {
    int n;
    std::vector<std::set<int>> s;
    std::vector<int> mx, mn, ok;
    SegmentTree(int n)
        : n(n),
          s(n),
          mx(4 * n, std::numeric_limits<int>::min()),
          mn(4 * n, std::numeric_limits<int>::max()),
          ok(4 * n) {}
    void modify(int p, int l, int r, int x) {
        if (r - l == 1) {
            mn[p] = std::numeric_limits<int>::max();
            mx[p] = std::numeric_limits<int>::min();
            if (!s[x].empty()) {
                if (x % 2 == 0) {
                    mn[p] = *s[x].begin();
                } else {
                    mx[p] = *s[x].rbegin();
                }
            }
        } else {
            int m = (l + r) / 2;
            if (x < m) {
                modify(2 * p, l, m, x);
            } else {
                modify(2 * p + 1, m, r, x);
            }
            mn[p] = std::min(mn[2 * p], mn[2 * p + 1]);
            mx[p] = std::max(mx[2 * p], mx[2 * p + 1]);
            ok[p] = ok[2 * p] || ok[2 * p + 1] || mn[2 * p] < mx[2 * p + 1];
        }
    }
    void modify(int x, int y) {
        if (s[x].count(y)) {
            s[x].erase(y);
        } else {
            s[x].insert(y);
        }
        modify(1, 0, n, x);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, q;
    std::cin >> n >> m >> q;
    SegmentTree t(2 * n);
    while (q--) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        t.modify(x, y);
        std::cout << (t.ok[1] ? "NO" : "YES") << "\n";
    }
    return 0;
}