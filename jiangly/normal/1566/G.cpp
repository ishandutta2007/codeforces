#include <bits/stdc++.h>

using i64 = long long;

constexpr int C = 1 << 30;

constexpr i64 inf = 1E18;

struct Node {
    Node *l;
    Node *r;
    int cnt;
};

Node *null = new Node;

Node *newNode() {
    Node *p = new Node;
    *p = *null;
    return p;
}

void addw(Node *&t, int l, int r, int x, int v) {
    if (t == null) {
        t = newNode();
    }
    t->cnt += v;
    if (r - l == 1) {
        return;
    }
    int m = (l + r) / 2;
    if (x < m) {
        addw(t->l, l, m, x, v);
    } else {
        addw(t->r, m, r, x, v);
    }
}

i64 queryMin(Node *t, Node *tu, Node *tv, int l, int r, int w) {
    int c = t->cnt - tu->cnt - tv->cnt + (l <= w && w < r);
    if (c == 0) {
        return inf;
    }
    if (r - l == 1) {
        return l;
    }
    int m = (l + r) / 2;
    c = t->l->cnt - tu->l->cnt - tv->l->cnt + (l <= w && w < m);
    if (c > 0) {
        return queryMin(t->l, tu->l, tv->l, l, m, w);
    } else {
        return queryMin(t->r, tu->r, tv->r, m, r, w);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    null->l = null->r = null;
    null->cnt = 0;
    
    int n, m;
    std::cin >> n >> m;
    
    i64 f[n];
    for (int i = 0; i < n; i++) {
        f[i] = inf;
    }
    
    std::multiset<i64> fs(f, f + n);
    
    Node *all = null;
    Node *tree[n];
    std::fill(tree, tree + n, null);
    
    std::set<std::tuple<int, int, int>> edges;
    std::set<std::pair<int, int>> adj[n];
    std::map<int, int> wt[n];
    
    auto calcf = [&](int u) {
        fs.erase(fs.find(f[u]));
        if (adj[u].size() < 3) {
            f[u] = inf;
        } else {
            auto it = adj[u].begin();
            f[u] = 0;
            for (int i = 0; i < 3; i++) {
                f[u] += it->first;
                it++;
            }
        }
        fs.insert(f[u]);
    };
    
    auto add = [&](int u, int v, int w) {
        if (u > v) {
            std::swap(u, v);
        }
        addw(all, 0, C, w, 1);
        addw(tree[u], 0, C, w, 1);
        addw(tree[v], 0, C, w, 1);
        wt[u][v] = w;
        edges.emplace(w, u, v);
        adj[u].emplace(w, v);
        adj[v].emplace(w, u);
        calcf(u);
        calcf(v);
    };
    
    auto del = [&](int u, int v) {
        if (u > v) {
            std::swap(u, v);
        }
        int w = wt[u][v];
        addw(all, 0, C, w, -1);
        addw(tree[u], 0, C, w, -1);
        addw(tree[v], 0, C, w, -1);
        wt[u].erase(v);
        edges.erase({w, u, v});
        adj[u].erase({w, v});
        adj[v].erase({w, u});
        calcf(u);
        calcf(v);
    };
    
    auto query = [&]() {
        i64 res = *fs.begin();
        auto [w, u, v] = *edges.begin();
        auto i = std::next(adj[u].begin());
        auto j = std::next(adj[v].begin());
        if (i != adj[u].end() && j != adj[v].end()) {
            if (i->second != j->second) {
                res = std::min(res, 1LL * i->first + j->first);
            } else {
                if (std::next(i) != adj[u].end()) {
                    res = std::min(res, 1LL * std::next(i)->first + j->first);
                }
                if (std::next(j) != adj[v].end()) {
                    res = std::min(res, 1LL * i->first + std::next(j)->first);
                }
            }
        }
        res = std::min(res, 1LL * w + queryMin(all, tree[u], tree[v], 0, C, w));
        return res;
    };
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        add(u, v, w);
    }
    
    std::cout << query() << "\n";
    
    int q;
    std::cin >> q;
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 0) {
            int u, v;
            std::cin >> u >> v;
            u--;
            v--;
            del(u, v);
        } else {
            int u, v, w;
            std::cin >> u >> v >> w;
            u--;
            v--;
            add(u, v, w);
        }
        std::cout << query() << "\n";
    }
    
    return 0;
}