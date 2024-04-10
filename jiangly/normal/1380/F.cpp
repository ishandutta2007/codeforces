#include <bits/stdc++.h>
constexpr int P = 998244353;
struct Matrix {
    int a[4];
    Matrix() : a{} {}
    friend Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
        Matrix res;
        res.a[0] = (1ll * lhs.a[0] * rhs.a[0] + 1ll * lhs.a[1] * rhs.a[2]) % P;
        res.a[1] = (1ll * lhs.a[0] * rhs.a[1] + 1ll * lhs.a[1] * rhs.a[3]) % P;
        res.a[2] = (1ll * lhs.a[2] * rhs.a[0] + 1ll * lhs.a[3] * rhs.a[2]) % P;
        res.a[3] = (1ll * lhs.a[2] * rhs.a[1] + 1ll * lhs.a[3] * rhs.a[3]) % P;
        return res;
    }
};
struct SegmentTree {
    const int n;
    std::vector<int> a;
    std::vector<Matrix> t;
    SegmentTree(const std::vector<int> &a) : n(a.size()), a(a), t(4 * n) {
        build(1, 0, n);
    }
    void build(int p, int l, int r) {
        if (r - l == 1) {
            t[p].a[0] = a[l] + 1;
            t[p].a[1] = 1;
            t[p].a[2] = (l && a[l - 1] == 1) ? (9 - a[l]) : 0;
        } else {
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            t[p] = t[2 * p] * t[2 * p + 1];
        }
    }
    void update(int p, int l, int r, int x) {
        if (r - l == 1) {
            t[p].a[0] = a[l] + 1;
            t[p].a[2] = (l && a[l - 1] == 1) ? (9 - a[l]) : 0;
        } else {
            int m = (l + r) / 2;
            if (x < m) {
                update(2 * p, l, m, x);
            } else {
                update(2 * p + 1, m, r, x);
            }
            t[p] = t[2 * p] * t[2 * p + 1];
        }
    }
    void modify(int x, int y) {
        a[x] = y;
        update(1, 0, n, x);
        if (x + 1 < n)
            update(1, 0, n, x + 1);
    }
    int query() {
        return t[1].a[0];
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        char c;
        std::cin >> c;
        a[i] = c - '0';
    }
    SegmentTree t(a);
    while (m--) {
        int x, y;
        std::cin >> x >> y;
        --x;
        t.modify(x, y);
        std::cout << t.query() << "\n";
    }
    return 0;
}