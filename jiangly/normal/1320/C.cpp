#include <iostream>
#include <vector>
#include <queue>
struct SegmentTree {
    const int n;
    std::vector<int> max, tag;
    void add(int p, int v) {
        max[p] += v;
        tag[p] += v;
    }
    void push(int p) {
        add(2 * p, tag[p]);
        add(2 * p + 1, tag[p]);
        tag[p] = 0;
    }
    void rangeAdd(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x)
            return;
        if (l >= x && r <= y)
            return add(p, v);
        int m = (l + r) / 2;
        push(p);
        rangeAdd(2 * p, l, m, x, y, v);
        rangeAdd(2 * p + 1, m, r, x, y, v);
        max[p] = std::max(max[2 * p], max[2 * p + 1]);
    }
    SegmentTree(int n) : n(n), max(4 * n), tag(4 * n) {}
    void rangeAdd(int l, int r, int v) {
        rangeAdd(1, 0, n, l, r, v);
    }
};
int n, m, p, ans = std::numeric_limits<int>::min();
std::vector<int> ca, cb;
std::vector<std::vector<std::pair<int, int>>> mon;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> p;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        if (int(ca.size()) < x)
            ca.resize(x, std::numeric_limits<int>::max());
        ca[x - 1] = std::min(ca[x - 1], y);
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        if (int(cb.size()) < x)
            cb.resize(x, std::numeric_limits<int>::max());
        cb[x - 1] = std::min(cb[x - 1], y);
    }
    for (int i = int(ca.size()) - 2; i >= 0; --i)
        ca[i] = std::min(ca[i], ca[i + 1]);
    for (int i = int(cb.size()) - 2; i >= 0; --i)
        cb[i] = std::min(cb[i], cb[i + 1]);
    mon.resize(ca.size());
    SegmentTree t(cb.size());
    for (int i = 0; i < int(cb.size()); ++i)
        t.rangeAdd(i, i + 1, -cb[i]);
    for (int i = 0; i < p; ++i) {
        int x, y, z;
        std::cin >> x >> y >> z;
        if (x < int(ca.size()) && y < int(cb.size()))
            mon[x].emplace_back(y, z);
    }
    for (int i = 0; i < int(ca.size()); ++i) {
        for (auto [b, c] : mon[i])
            t.rangeAdd(b, cb.size(), c);
        ans = std::max(ans, t.max[1] - ca[i]);
    }
    std::cout << ans << "\n";
    return 0;
}