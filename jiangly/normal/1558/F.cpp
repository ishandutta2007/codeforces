#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

struct Info {
    int x[2][2] = {{-inf, -inf}, {-inf, -inf}};
    int cnt = 0;
};

void chmax(int &a, int b) {
    a = std::max(a, b);
}

Info operator+(const Info &a, const Info &b) {
    Info c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            chmax(c.x[i][j], a.x[i][j] + b.cnt);
            chmax(c.x[(i + a.cnt) % 2][j], b.x[i][j]);
        }
    }
    c.cnt = a.cnt + b.cnt;
    return c;
}

void apply(Info &a, int b) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a.x[i][j] += b;
        }
        if (b % 2 != 0) {
            std::swap(a.x[i][0], a.x[i][1]);
        }
    }
}
void apply(int &a, int b) {
    a += b;
}

template<class Info, class Tag,
    class Merge = std::plus<Info>>
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
    void pull(int p) {
        info[p] = merge(info[2 * p], info[2 * p + 1]);
    }
    void apply(int p, const Tag &v) {
        ::apply(info[p], v);
        ::apply(tag[p], v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x) {
        if (r - l == 1) {
            info[p].cnt = 1;
            if ((x + tag[p]) % 2 == 0) {
                info[p].x[1][0] += 1E9 + x;
            } else {
                info[p].x[1][1] += 1E9 + x;
            }
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x);
        } else {
            modify(2 * p + 1, m, r, x);
        }
        pull(p);
    }
    void modify(int p) {
        modify(1, 0, n, p);
    }
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
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
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
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
};
void solve() {
    int n;
    std::cin >> n;
    
    int a[n], p[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        p[a[i]] = i;
    }
    
    int res = 0;
    
    LazySegmentTree<Info, int> seg(n);
    
    for (int i = 0, j = 0; i < n; i++) {
        seg.modify(p[i]);
        seg.rangeApply(p[i] + 1, n, -1);
        while (j < n && a[j] <= i) {
            seg.rangeApply(j, j + 1, -1E9);
            j++;
        }
        
        auto info = seg.info[1];
        
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
                chmax(res, info.x[x][y] + (x ^ y));
            }
        }
    }
    
    std::cout << res << "\n";
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