#include <bits/stdc++.h>

using i64 = long long;

struct Info {
    int mx = 0;
    int cnt = 1;
};

Info operator+(const Info &a, const Info &b) {
    if (a.mx > b.mx) {
        return a;
    } else if (a.mx < b.mx) {
        return b;
    } else {
        return {a.mx, a.cnt + b.cnt};
    }
}

void apply(Info &a, int b) {
    a.mx += b;
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
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    std::vector<int> in(n), out(n), parent(n);
    parent[0] = -1;
    int tm = 0;
    std::function<void(int)> dfs = [&](int u) {
        if (parent[u] >= 0) {
            e[u].erase(std::find(e[u].begin(), e[u].end(), parent[u]));
        }
        
        in[u] = tm++;
        for (auto v : e[u]) {
            parent[v] = u;
            dfs(v);
        }
        out[u] = tm;
    };
    dfs(0);
    
    LazySegmentTree<Info, int> seg(std::vector(n, Info{0, 1}));
    
    std::set<std::pair<int, int>> s;
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        if (in[u] > in[v]) {
            std::swap(u, v);
        }
        int coef = 1;
        if (s.find({u, v}) != s.end()) {
            coef = -1;
            s.erase({u, v});
        } else {
            s.emplace(u, v);
        }
        
        seg.rangeApply(in[v], out[v], coef);
        if (in[v] < out[u]) {
            int x = *(std::upper_bound(e[u].begin(), e[u].end(), in[v], [&](int x, int v) { return x < in[v]; }) - 1);
            seg.rangeApply(0, in[x], coef);
            seg.rangeApply(out[x], n, coef);
        } else {
            seg.rangeApply(in[u], out[u], coef);
        }
        
        auto f = seg.info[1];
        if (f.mx < int(s.size())) {
            std::cout << "0\n";
        } else {
            std::cout << f.cnt << "\n";
        }
    }
    
    return 0;
}