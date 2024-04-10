#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
struct SegmentTree {
    int n;
    std::vector<int> sum, tag;
    SegmentTree(int n) : n(n), sum(4 * n), tag(4 * n, -1) {}
    void pull(int p) {
        sum[p] = sum[2 * p] + sum[2 * p + 1];
    }
    void modify(int p, int l, int r, int v) {
        sum[p] = (r - l) * v;
        tag[p] = v;
    }
    void push(int p, int l, int r) {
        int m = (l + r) / 2;
        if (tag[p] != -1) {
            modify(2 * p, l, m, tag[p]);
            modify(2 * p + 1, m, r, tag[p]);
            tag[p] = -1;
        }
    }
    void modify(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            return modify(p, l, r, v);
        }
        int m = (l + r) / 2;
        push(p, l, r);
        modify(2 * p, l, m, x, y, v);
        modify(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void modify(int x, int y, int v) {
        modify(1, 0, n, x, y, v);
    }
    int rangeSum(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return 0;
        }
        if (l >= x && r <= y) {
            return sum[p];
        }
        int m = (l + r) / 2;
        push(p, l, r);
        return rangeSum(2 * p, l, m, x, y) + rangeSum(2 * p + 1, m, r, x, y);
    }
    int rangeSum(int l, int r) {
        return rangeSum(1, 0, n, l, r);
    }
};
void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s, f;
    std::cin >> s >> f;
    std::vector<int> l(q), r(q);
    for (int i = 0; i < q; i++) {
        std::cin >> l[i] >> r[i];
        l[i]--;
    }
    SegmentTree t(n);
    for (int i = 0; i < n; i++) {
        if (f[i] == '1') {
            t.modify(i, i + 1, 1);
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        int s = t.rangeSum(l[i], r[i]);
        if (2 * s == r[i] - l[i]) {
            std::cout << "NO\n";
            return;
        }
        if (2 * s < r[i] - l[i]) {
            t.modify(l[i], r[i], 0);
        } else {
            t.modify(l[i], r[i], 1);
        }
    }
    for (int i = 0; i < n; i++) {
        if (t.rangeSum(i, i + 1) != s[i] - '0') {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}