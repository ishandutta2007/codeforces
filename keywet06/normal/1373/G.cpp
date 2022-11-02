#include <bits/stdc++.h>

struct SegmentTree {
    int n;
    std::vector<int> max, tag;
    SegmentTree(int n) : n(n), max(4 * n), tag(4 * n) {}
    void add(int p, int v) {
        max[p] += v;
        tag[p] += v;
    }
    void push(int p) {
        add(2 * p, tag[p]);
        add(2 * p + 1, tag[p]);
        tag[p] = 0;
    }
    void rangeAdd(int p, int l, int r, int l1, int r1, int v) {
        if (l >= r1 || r <= l1) return;
        if (l >= l1 && r <= r1) return add(p, v);
        int m = (l + r) / 2;
        push(p);
        rangeAdd(2 * p, l, m, l1, r1, v);
        rangeAdd(2 * p + 1, m, r, l1, r1, v);
        max[p] = std::max(max[2 * p], max[2 * p + 1]);
    }
    void rangeAdd(int l, int r, int v) { rangeAdd(1, 0, n, l, r, v); }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k, m;
    std::cin >> n >> k >> m;
    SegmentTree t(2 * n);
    t.rangeAdd(0, 2 * n, -1e9);
    for (int i = 0; i < 2 * n; ++i) t.rangeAdd(i, i + 1, i);
    std::set<std::pair<int, int>> s;
    std::vector<int> cnt(2 * n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        int v = y + std::abs(x - k);
        if (s.count({x, y})) {
            s.erase({x, y});
            if (!--cnt[v]) t.rangeAdd(v, v + 1, -1e9);
            t.rangeAdd(v + 1, 2 * n, 1);
        } else {
            s.emplace(x, y);
            if (!cnt[v]++) t.rangeAdd(v, v + 1, 1e9);
            t.rangeAdd(v + 1, 2 * n, -1);
        }
        std::cout << std::max(0, t.max[1] + int(s.size()) - n - 1) << "\n";
    }
    return 0;
}