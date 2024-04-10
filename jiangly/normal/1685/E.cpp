#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

struct Min {
    int v = inf;
    int pos = -1;
};

Min operator+(Min a, Min b) {
    if (a.v < b.v) {
        return a;
    } else {
        return b;
    }
}

void apply(int &a, int b) {
    a += b;
}
void apply(Min &a, int b) {
    a.v += b;
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
    
    int n, Q;
    std::cin >> n >> Q;
    
    std::vector<int> p(2 * n + 1), q(2 * n + 1);
    for (int i = 0; i < 2 * n + 1; i++) {
        std::cin >> p[i];
        p[i]--;
        q[p[i]] = i;
    }
    
    std::vector<int> s(2 * n + 1);
    for (int i = 0; i < 2 * n; i++) {
        s[i + 1] = s[i] + (p[i] >= n ? 1 : -1);
    }
    std::vector<Min> val(2 * n + 1);
    for (int i = 0; i <= 2 * n; i++) {
        val[i] = {s[i], i};
    }
    LazySegmentTree<Min, int> seg(val);
    
    std::set<int> small, large;
    
    int wrongs = 0, wrongl = 0;
    auto isWrong = [&](int x, int y) -> bool {
        if (x < n) {
            return y != (x < n - 1 ? x + 1 : 0);
        } else {
            return y != (x < 2 * n ? x + 1 : n);
        }
    };
    
    auto add = [&](int i, int x) {
        if (x < n) {
            auto it = small.insert(i).first;
            if (it != small.begin()) {
                wrongs += isWrong(p[*std::prev(it)], x);
            }
            if (std::next(it) != small.end()) {
                wrongs += isWrong(x, p[*std::next(it)]);
            }
            if (it != small.begin() && std::next(it) != small.end()) {
                wrongs -= isWrong(p[*std::prev(it)], p[*std::next(it)]);
            }
        } else {
            auto it = large.insert(i).first;
            if (it != large.begin()) {
                wrongl += isWrong(p[*std::prev(it)], x);
            }
            if (std::next(it) != large.end()) {
                wrongl += isWrong(x, p[*std::next(it)]);
            }
            if (it != large.begin() && std::next(it) != large.end()) {
                wrongl -= isWrong(p[*std::prev(it)], p[*std::next(it)]);
            }
        }
    };
    
    auto del = [&](int i, int x) {
        if (x < n) {
            auto it = small.find(i);
            if (it != small.begin()) {
                wrongs -= isWrong(p[*std::prev(it)], x);
            }
            if (std::next(it) != small.end()) {
                wrongs -= isWrong(x, p[*std::next(it)]);
            }
            if (it != small.begin() && std::next(it) != small.end()) {
                wrongs += isWrong(p[*std::prev(it)], p[*std::next(it)]);
            }
            small.erase(it);
        } else {
            auto it = large.find(i);
            if (it != large.begin()) {
                wrongl -= isWrong(p[*std::prev(it)], x);
            }
            if (std::next(it) != large.end()) {
                wrongl -= isWrong(x, p[*std::next(it)]);
            }
            if (it != large.begin() && std::next(it) != large.end()) {
                wrongl += isWrong(p[*std::prev(it)], p[*std::next(it)]);
            }
            large.erase(it);
        }
    };
    
    for (int i = 0; i < 2 * n + 1; i++) {
        add(i, p[i]);
    }
    
    for (int i = 0; i < Q; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        del(u, p[u]);
        del(v, p[v]);
        seg.rangeApply(u + 1, 2 * n + 1, (p[u] >= n ? -1 : 1));
        seg.rangeApply(v + 1, 2 * n + 1, (p[v] >= n ? -1 : 1));
        std::swap(p[u], p[v]);
        std::swap(q[p[u]], q[p[v]]);
        add(u, p[u]);
        add(v, p[v]);
        seg.rangeApply(u + 1, 2 * n + 1, (p[u] >= n ? 1 : -1));
        seg.rangeApply(v + 1, 2 * n + 1, (p[v] >= n ? 1 : -1));
        
        auto k = seg.info[1].pos;
        if (p[k] == n && p[(k + 2 * n) % (2 * n + 1)] == n - 1 && wrongs + wrongl == 0) {
            std::cout << "-1\n";
        } else {
            if (wrongl == 0 && p[k] == n) {
                k = (k + 1) % (2 * n + 1);
            }
            std::cout << k << "\n";
        }
    }
    
    return 0;
}