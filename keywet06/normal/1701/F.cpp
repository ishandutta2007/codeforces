#include <bits/stdc++.h>

using int64 = long long;

const int N = 2E5;

struct Info {
    int cnt;
    int64 sum;
    Info(int x = 0, int64 s = 0) : cnt(x), sum(s) {}
};

Info operator+(const Info &a, const Info &b) { return Info(a.cnt + b.cnt, a.sum + b.sum); }

void apply(Info &a, int b) { a.sum += 1LL * a.cnt * b; }

void apply(int &a, int b) { a += b; }

template <class Info, class Tag, class Merge = std::plus<Info>>
struct LazySegmentTree {
    const int n;
    const Merge merge;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree(int n) : n(n), merge(Merge()), info(4 << std::__lg(n)), tag(4 << std::__lg(n)) {}
    LazySegmentTree(std::vector<Info> init) : LazySegmentTree(init.size()) {
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
    void apply(int p, const Tag &v) {
        ::apply(info[p], v);
        ::apply(tag[p], v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
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
        push(p);
        return merge(rangeQuery(2 * p, l, m, x, y), rangeQuery(2 * p + 1, m, r, x, y));
    }
    Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) { return rangeApply(1, 0, n, l, r, v); }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q, d;
    std::cin >> q >> d;

    std::array<bool, N> have{};

    LazySegmentTree<Info, int> seg(N);

    int64 ans = 0;
    for (int i = 0, x; i < q; ++i) {
        std::cin >> x, --x;
        if (have[x]) {
            have[x] = false;
            int cl = seg.rangeQuery(std::max(0, x - d), x).cnt;
            ans -= 1LL * cl * (cl - 1) / 2;
            int cr = seg.rangeQuery(x + 1, std::min(N, x + d + 1)).cnt;
            ans -= 1LL * cr * (cr - 1) / 2;
            ans -= seg.rangeQuery(std::max(0, x - d), x).sum - 1LL * cl * seg.rangeQuery(0, x + 1).cnt;
            seg.rangeApply(std::max(0, x - d), N, -1);
            seg.modify(x, Info(0, 0));
        } else {
            have[x] = true;
            int cl = seg.rangeQuery(std::max(0, x - d), x).cnt;
            ans += 1LL * cl * (cl - 1) / 2;
            int cr = seg.rangeQuery(x + 1, std::min(N, x + d + 1)).cnt;
            ans += 1LL * cr * (cr - 1) / 2;
            ans += seg.rangeQuery(std::max(0, x - d), x).sum - 1LL * cl * seg.rangeQuery(0, x + 1).cnt;
            seg.rangeApply(std::max(0, x - d), N, 1);
            seg.modify(x, Info(1, seg.rangeQuery(0, std::min(N, x + d + 1)).cnt + 1));
        }
        std::cout << ans << "\n";
    }

    return 0;
}