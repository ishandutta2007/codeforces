#include <bits/stdc++.h>

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
        if (r - l == 1) return void(info[p] = v);
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
        if (l >= y || r <= x) return Info();
        if (l >= x && r <= y) return info[p];
        int m = (l + r) / 2;
        return merge(rangeQuery(2 * p, l, m, x, y), rangeQuery(2 * p + 1, m, r, x, y));
    }
    Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
};

const int inf = (1 << 30) - 1;

struct Info {
    int v[31];
    Info(int x = inf) {
        v[0] = x;
        for (int i = 1; i < 31; ++i) v[i] = inf;
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    int i = 0, j = 0;
    while (i + j < 31) {
        if (a.v[i] < b.v[j]) {
            c.v[i + j] = a.v[i], ++i;
        } else {
            c.v[i + j] = b.v[j], ++j;
        }
    }
    return c;
}

void Solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    SegmentTree<Info> seg(std::vector<Info>(a.begin(), a.end()));
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        std::cin >> l >> r, --l;
        int ans = inf;
        auto a = seg.rangeQuery(l, r);
        for (int x = 0; x < 31; ++x) {
            for (int y = x + 1; y < 31; ++y) ans = std::min(a.v[x] | a.v[y], ans);
        }
        std::cout << ans << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) Solve();
    return 0;
}