#include <bits/stdc++.h>

using i64 = long long;
template<class Info,
    class Merge = std::plus<Info>>
struct SegmentTree {
    const int n;
    const Merge merge;
    std::vector<Info> info;
    SegmentTree(int n) : n(n), merge(Merge()), info(4 << std::__lg(n)) {}
    SegmentTree(std::vector<Info> init) : SegmentTree(init.size()) {
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = merge(info[2 * p], info[2 * p + 1]);
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return merge(rangeQuery(2 * p, l, m, x, y), rangeQuery(2 * p + 1, m, r, x, y));
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
};

struct Info {
    int l;
    int r;
    int len;
    i64 s;
    Info() : l(0), r(0), len(0), s(0) {}
    Info(int x) : l(x), r(x), len(1), s(x + 1) {}
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.l = a.l == a.len ? a.len + b.l : a.l;
    c.r = b.r == b.len ? a.r + b.len : b.r;
    c.len = a.len + b.len;
    c.s = a.s + b.s + 1LL * a.r * b.l;
    return c;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    SegmentTree<Info> seg(n - 1);
    for (int i = 0; i < n - 1; i++) {
        seg.modify(i, a[i] <= a[i + 1]);
    }
    
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y;
            std::cin >> x >> y;
            x--;
            a[x] = y;
            if (x > 0) {
                seg.modify(x - 1, a[x - 1] <= a[x]);
            }
            if (x < n - 1) {
                seg.modify(x, a[x] <= a[x + 1]);
            }
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.rangeQuery(l - 1, r - 1).s + 1 << "\n";
        }
    }
    
    return 0;
}