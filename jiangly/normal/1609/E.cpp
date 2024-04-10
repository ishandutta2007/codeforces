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
    int f[4][4];
    Info() {
        for (int i = 0; i <= 3; i++) {
            for (int j = i; j <= 3; j++) {
                f[i][j] = 0;
            }
        }
    }
    Info(int x) : Info() {
        f[x][x]++;
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    for (int i = 0; i <= 3; i++) {
        for (int j = i; j <= 3; j++) {
            c.f[i][j] = 1E9;
        }
    }
    for (int i = 0; i <= 3; i++) {
        for (int j = i; j <= 3; j++) {
            for (int k = j; k <= 3; k++) {
                c.f[i][k] = std::min(c.f[i][k], a.f[i][j] + b.f[j][k]);
            }
        }
    }
    return c;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::string s;
    std::cin >> s;
    
    SegmentTree<Info> seg(n);
    for (int i = 0; i < n; i++) {
        seg.modify(i, Info(s[i] - 'a'));
    }
    
    while (q--) {
        int x;
        char ch;
        std::cin >> x >> ch;
        x--;
        
        seg.modify(x, Info(ch - 'a'));
        
        auto ans = seg.info[1];
        std::cout << std::min({ans.f[0][0], ans.f[0][1], ans.f[0][2]}) << "\n";
    }
    
    
    return 0;
}