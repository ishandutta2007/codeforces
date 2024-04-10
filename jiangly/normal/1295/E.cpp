#include <iostream>
#include <algorithm>
#include <vector>
class SegmentTree {
private:
    int n;
    std::vector<long long> min, tag;
    void add(int p, long long v) {
        min[p] += v;
        tag[p] += v;
    }
    void push(int p) {
        add(2 * p, tag[p]);
        add(2 * p + 1, tag[p]);
        tag[p] = 0;
    }
    void pull(int p) {
        min[p] = std::min(min[2 * p], min[2 * p + 1]);
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
        pull(p);
    }
public:
    SegmentTree(int n) : n(n), min(4 * n), tag(4 * n) {}
    void rangeAdd(int l, int r, int v) {
        rangeAdd(1, 0, n, l, r, v);
    }
    long long getMin() {
        return min[1];
    }
};
int n;
std::vector<int> p, a, pos;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    p.resize(n);
    a.resize(n);
    pos.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        --p[i];
        pos[p[i]] = i;
    }
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    SegmentTree t(n - 1);
    for (int i = 0; i < n; ++i)
        t.rangeAdd(pos[i], n - 1, a[pos[i]]);
    long long ans = t.getMin();
    for (int i = 0; i < n; ++i) {
        t.rangeAdd(pos[i], n - 1, -a[pos[i]]);
        t.rangeAdd(0, pos[i], a[pos[i]]);
        ans = std::min(ans, t.getMin());
    }
    std::cout << ans << "\n";
    return 0;
}