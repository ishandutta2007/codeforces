#include <iostream>
#include <vector>
#include <algorithm>
struct SegmentTree {
    int n;
    std::vector<int> sum, max;
    void init(int _n) {
        n = _n;
        sum.assign(4 * n, 0);
        max.assign(4 * n, 0);
    }
    void pull(int p) {
        sum[p] = sum[2 * p] + sum[2 * p + 1];
        max[p] = std::max(max[2 * p + 1], max[2 * p] + sum[2 * p + 1]);
    }
    void modify(int p, int l, int r, int pos, int v) {
        if (r - l == 1) {
            sum[p] = v;
            max[p] = std::max(0, v);
            return;
        }
        int m = (l + r) / 2;
        if (pos < m) {
            modify(2 * p, l, m, pos, v);
        } else {
            modify(2 * p + 1, m, r, pos, v);
        }
        pull(p);
    }
    void modify(int pos, int v) {
        modify(1, 0, n, pos, v);
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> p(n), q(n), pos(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        --p[i];
        pos[p[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> q[i];
        --q[i];
    }
    SegmentTree t;
    t.init(2 * n);
    t.modify(2 * pos[n - 1], 1);
    std::cout << n << " ";
    for (int i = 0, ans = n - 1; i < n - 1; ++i) {
        t.modify(2 * q[i] + 1, -1);
        while (t.max[1] <= 0) {
            --ans;
            t.modify(2 * pos[ans], 1);
        }
        std::cout << ans + 1 << " \n"[i == n - 2];
    }
    return 0;
}