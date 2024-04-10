#include <bits/stdc++.h>
using int64 = long long;
const int Lim = 2e5 + 1;
const int64 Inf = 1e18;

struct tree {
    int64 tag, mn;
    tree *lc, *rc;
};

tree *null = new tree;

tree *newTree() {
    auto t = new tree;
    t->lc = t->rc = null;
    t->tag = 0;
    t->mn = Inf;
    return t;
}

void add(tree *t, int64 v) {
    t->tag += v;
    t->mn += v;
}

void push(tree *t) {
    if (t->lc != null) add(t->lc, t->tag);
    if (t->rc != null) add(t->rc, t->tag);
    t->tag = 0;
}

void pull(tree *t) { t->mn = std::min(t->lc->mn, t->rc->mn); }

void modify(tree *&t, int l, int r, int x, int64 v) {
    if (t == null) t = newTree();
    if (r - l == 1) {
        t->mn = v;
        return;
    }
    int m = (l + r) / 2;
    push(t);
    if (x < m)
        modify(t->lc, l, m, x, v);
    else
        modify(t->rc, m, r, x, v);
    pull(t);
}

int64 query(tree *t, int l, int r, int x) {
    if (r - l == 1 || t == null) return t->mn;
    int m = (l + r) / 2;
    push(t);
    if (x < m)
        return query(t->lc, l, m, x);
    else
        return query(t->rc, m, r, x);
}

tree *merge(tree *t1, tree *t2) {
    if (t1 == null) return t2;
    if (t2 == null) return t1;
    t1->mn = std::min(t1->mn, t2->mn);
    push(t1);
    push(t2);
    t1->lc = merge(t1->lc, t2->lc);
    t1->rc = merge(t1->rc, t2->rc);
    return t1;
}

tree *solve(int s, int64 v, int ban) {
    tree *t = null;
    modify(t, 0, Lim, s, v);
    std::string opt;
    while (std::cin >> opt) {
        if (opt == "end") return t;
        if (opt == "set") {
            int y, v;
            std::cin >> y >> v;
            int64 mn = t->mn;
            add(t, v);
            if (y != ban) modify(t, 0, Lim, y, mn);
        } else {
            int y;
            std::cin >> y;
            auto t1 = solve(y, query(t, 0, Lim, y), ban);
            modify(t, 0, Lim, y, Inf);
            t = merge(t, t1);
        }
    }
    return t;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    null->mn = Inf;
    null->lc = null->rc = null;
    int n, s;
    std::cin >> n >> s;
    auto t = solve(0, 0, s);
    std::cout << t->mn << "\n";
    return 0;
}