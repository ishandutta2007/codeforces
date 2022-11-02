#include <bits/stdc++.h>

struct SegmentTree {
    int n;
    std::vector<int> mx, tag;
    SegmentTree(int n) : n(n), mx(4 * n), tag(4 * n) {}
    int max() { return mx[1]; }
    void add(int p, int v) {
        mx[p] += v;
        tag[p] += v;
    }
    void push(int p) {
        add(2 * p, tag[p]);
        add(2 * p + 1, tag[p]);
        tag[p] = 0;
    }
    void rangeAdd(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x) {
            return;
        } else if (l >= x && r <= y) {
            add(p, v);
        } else {
            int m = (l + r) / 2;
            push(p);
            rangeAdd(2 * p, l, m, x, y, v);
            rangeAdd(2 * p + 1, m, r, x, y, v);
            mx[p] = std::max(mx[2 * p], mx[2 * p + 1]);
        }
    }
    void rangeAdd(int l, int r, int v) { rangeAdd(1, 0, n, l, r, v); }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> l(n), r(n), t(n);
    std::vector<int> v;
    v.reserve(2 * n + 1);
    v.push_back(0);
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i] >> r[i] >> t[i];
        v.push_back(l[i]);
        v.push_back(r[i]);
    }
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    int m = v.size();
    std::vector<std::vector<int>> e(m);
    for (int i = 0; i < n; ++i) {
        l[i] = std::lower_bound(v.begin(), v.end(), l[i]) - v.begin();
        r[i] = std::lower_bound(v.begin(), v.end(), r[i]) - v.begin();
        e[r[i]].push_back(i);
    }
    SegmentTree t1(m), t2(m);
    int ans = 0;
    for (int i = 1; i < m; ++i) {
        for (auto j : e[i]) (t[j] == 1 ? t1 : t2).rangeAdd(0, l[j], 1);
        int val = std::max(t1.max(), t2.max());
        ans = std::max(ans, val);
        t1.rangeAdd(i, i + 1, val);
        t2.rangeAdd(i, i + 1, val);
    }
    std::cout << ans << "\n";
    return 0;
}