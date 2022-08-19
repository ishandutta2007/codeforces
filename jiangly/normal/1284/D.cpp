#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
class SegmentTree {
private:
    int n;
    std::vector<int> mx, lazy;
    void add(int p, int v) {
        mx[p] += v;
        lazy[p] += v;
    }
    void push(int p) {
        add(2 * p, lazy[p]);
        add(2 * p + 1, lazy[p]);
        lazy[p] = 0;
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
        mx[p] = std::max(mx[2 * p], mx[2 * p + 1]);
    }
    int rangeMax(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x)
            return 0;
        if (l >= x && r <= y)
            return mx[p];
        int m = (l + r) / 2;
        push(p);
        return std::max(rangeMax(2 * p, l, m, x, y), rangeMax(2 * p + 1, m, r, x, y));
    }
public:
    SegmentTree(int n) : n(n), mx(4 * n), lazy(4 * n) {}
    void rangeAdd(int l, int r, int v) {
        rangeAdd(1, 0, n, l, r, v);
    }
    int rangeMax(int l, int r) {
        return rangeMax(1, 0, n, l, r);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> la(n), ra(n), lb(n), rb(n);
    std::vector<int> va, vb;
    for (int i = 0; i < n; ++i) {
        std::cin >> la[i] >> ra[i] >> lb[i] >> rb[i];
        ++ra[i];
        ++rb[i];
        va.push_back(la[i]);
        va.push_back(ra[i]);
        vb.push_back(lb[i]);
        vb.push_back(rb[i]);
    }
    std::sort(va.begin(), va.end());
    va.erase(std::unique(va.begin(), va.end()), va.end());
    std::sort(vb.begin(), vb.end());
    vb.erase(std::unique(vb.begin(), vb.end()), vb.end());
    for (int i = 0; i < n; ++i) {
        la[i] = std::lower_bound(va.begin(), va.end(), la[i]) - va.begin();
        ra[i] = std::lower_bound(va.begin(), va.end(), ra[i]) - va.begin();
        lb[i] = std::lower_bound(vb.begin(), vb.end(), lb[i]) - vb.begin();
        rb[i] = std::lower_bound(vb.begin(), vb.end(), rb[i]) - vb.begin();
    }
    auto check = [&]() {
        std::vector<std::tuple<int, int, int>> a;
        for (int i = 0; i < n; ++i) {
            a.emplace_back(la[i], 1, i);
            a.emplace_back(ra[i], -1, i);
        }
        std::sort(a.begin(), a.end());
        SegmentTree t(vb.size());
        for (auto [x, op, i] : a) {
            if (op == 1) {
                if (t.rangeMax(lb[i], rb[i]) > 0) {
                    std::cout << "NO\n";
                    exit(0);
                }
            } else {
                t.rangeAdd(lb[i], rb[i], 1);
            }
        }
    };
    check();
    swap(va, vb);
    swap(la, lb);
    swap(ra, rb);
    check();
    std::cout << "YES\n";
    return 0;
}