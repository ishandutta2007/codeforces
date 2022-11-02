#include <bits/stdc++.h>

using int64 = long long;

struct Info {
    int64 sum;
    int mn, cnt;
    Info() : sum(0), mn(1000000000), cnt(0) {}
    Info(int64 sum, int mn, int cnt) : sum(sum), mn(mn), cnt(cnt) {}
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.sum = a.sum + b.sum;
    if (a.mn < b.mn) {
        c.mn = a.mn;
        c.cnt = a.cnt;
    } else if (a.mn > b.mn) {
        c.mn = b.mn;
        c.cnt = b.cnt;
    } else {
        c.mn = b.mn;
        c.cnt = a.cnt + b.cnt;
    }
    return c;
}

template <class Info, class Merge = std::plus<Info>>
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
    void pull(int p) { info[p] = merge(info[2 * p], info[2 * p + 1]); }
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
    void modify(int p, const Info &v) { modify(1, 0, n, p, v); }
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
    Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    std::vector<int> p(n, -1), match(n, -1);
    std::vector<int> stk;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            stk.push_back(i);
        } else if (!stk.empty()) {
            int x = stk.back();
            stk.pop_back();
            match[i] = x;
            match[x] = i;
            if (x > 0) {
                if (s[x - 1] == '(') {
                    p[x] = x - 1;
                } else if (match[x - 1] != -1) {
                    p[x] = p[match[x - 1]];
                }
            }
        }
    }
    std::vector<int> deg(n);
    for (int i = 0; i < n; ++i) {
        if (p[i] != -1) ++deg[p[i]];
    }
    SegmentTree<Info> seg(n);
    for (int i = 0; i < n; ++i) {
        if (match[i] > i) {
            seg.modify(i, Info(1LL * deg[i] * (deg[i] + 1) / 2, p[i], 1));
        }
    }
    while (q--) {
        int op, l, r;
        std::cin >> op >> l >> r, --l;
        if (op != 1) {
            auto v = seg.rangeQuery(l, r);
            std::cout << v.sum + 1LL * v.cnt * (v.cnt + 1) / 2 << "\n";
        }
    }
    return 0;
}