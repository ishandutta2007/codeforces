#include <bits/stdc++.h>

using i64 = long long;

struct Info {
    int c[2];
    i64 s[2];
    Info() : c{}, s{} {}
    Info(int x, int v) : Info() {
        c[x] = 1;
        s[x] = v;
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.c[0] = a.c[0] + b.c[0];
    c.c[1] = a.c[1] + b.c[1];
    c.s[0] = a.s[0] + b.s[0];
    c.s[1] = a.s[1] + b.s[1];
    return c;
}

void apply(Info &a, int b) {
    if (b) {
        std::swap(a.c[0], a.c[1]);
        std::swap(a.s[0], a.s[1]);
    }
}

void apply(int &a, int b) {
    a ^= b;
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
    bool rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return true;
        }
        if (l >= x && r <= y && info[p].c[0] + info[p].c[1] == r - l) {
            apply(p, v);
            return true;
        }
        if (l >= x && r <= y && info[p].c[0] + info[p].c[1] == 0) {
            return false;
        }
        int m = (l + r) / 2;
        push(p);
        bool res;
        if (rangeApply(2 * p + 1, m, r, x, y, v)) {
            res = rangeApply(2 * p, l, m, x, y, v);
        } else {
            res = false;
        }
        pull(p);
        return res;
    }
    bool rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        
        adj[u].emplace_back(v, i + 1);
        adj[v].emplace_back(u, i + 1);
    }
    
    std::vector<int> id(n), parent(n, -1), dep(n), top(n), in(n), out(n), siz(n);
    int clk = 0;
    
    std::function<void(int)> dfs1 = [&](int u) {
        if (u > 0) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), std::pair(parent[u], id[u])));
        }
        siz[u] = 1;
        for (auto &e : adj[u]) {
            auto [v, i] = e;
            id[v] = i;
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0].first]) {
                std::swap(adj[u][0], e);
            }
        }
    };
    dfs1(0);
    
    std::function<void(int)> dfs2 = [&](int u) {
        in[u] = clk++;
        for (auto [v, i] : adj[u]) {
            top[v] = v == adj[u][0].first ? top[u] : v;
            dfs2(v);
        }
        out[u] = clk;
    };
    dfs2(0);
    
    LazySegmentTree<Info, int> seg(n);
    seg.modify(0, Info(1, 0));
    
    while (true) {
        int op;
        std::cin >> op;
        
        if (op == 3) {
            break;
        }
        
        if (op == 1) {
            int x;
            std::cin >> x;
            x--;
            int s = 1;
            for (auto [v, i] : adj[x]) {
                s ^= seg.rangeQuery(in[v], in[v] + 1).c[1];
            }
            
            seg.modify(in[x], Info(s, id[x]));
            if (s == 1) {
                x = parent[x];
                while (x != -1) {
                    if (!seg.rangeApply(in[top[x]], in[x] + 1, 1)) {
                        break;
                    }
                    x = parent[top[x]];
                }
            }
        }
        
        auto info = seg.info[1];
        if (info.c[0] != info.c[1]) {
            std::cout << 0 << std::endl;
        } else if (op == 1) {
            std::cout << info.s[1] << std::endl;
        } else {
            std::vector<int> ans;
            for (int i = 0; i < n; i++) {
                if (seg.rangeQuery(in[i], in[i] + 1).c[1] == 1) {
                    ans.push_back(id[i]);
                }
            }
            std::sort(ans.begin(), ans.end());
            
            std::cout << ans.size();
            for (auto x : ans) {
                std::cout << " " << x;
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}