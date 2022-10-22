#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;
int n, K;
int c[mxn], q[mxn], id[mxn];
int b[mxn], ans[mxn];

std::mt19937 rng;

struct Node {
    int i, val, key;
    int tagval, tagkey;
    unsigned fix;
    Node *ls, *rs;

    Node(int _i): i(_i), val(b[i]), key(0), tagval(0), tagkey(0), fix(rng()), ls(nullptr), rs(nullptr) { }
};

using node = Node *;

inline void pushval(node x, int v) { x->val += v; x->tagval += v; }
inline void pushkey(node x, int v) { x->key += v; x->tagkey += v; }

inline void pushdown(node x) {
    if (x->tagval) {
        if (x->ls) pushval(x->ls, x->tagval);
        if (x->rs) pushval(x->rs, x->tagval);
        x->tagval = 0;
    }
    if (x->tagkey) {
        if (x->ls) pushkey(x->ls, x->tagkey);
        if (x->rs) pushkey(x->rs, x->tagkey);
        x->tagkey = 0;
    }
}

void split(node x, int v, node &a, node &b) {
    if (!x) return void(a = b = nullptr);
    pushdown(x);
    if (x->val < v) a = x, split(x->rs, v, a->rs, b);
    else b = x, split(x->ls, v, a, b->ls);
}

node merge(node a, node b) {
    if (!a || !b) return a ? a : b;
    pushdown(a), pushdown(b);
    if (a->fix < b->fix) return a->rs = merge(a->rs, b), a;
    else return b->ls = merge(a, b->ls), b;
}

void insert(node &x, node v) {
    node a, b;
    split(x, v->val, a, b);
    x = merge(merge(a, v), b);
}

void traverse(node x, std::vector <node> &vec) {
    if (!x) return ;
    pushdown(x);
    node ls = x->ls, rs = x->rs;
    x->ls = x->rs = nullptr;
    traverse(ls, vec);
    vec.push_back(x);
    traverse(rs, vec);
}

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d %d", &c[i], &q[i]), id[i] = i;
    std::sort(id, id + n, [&] (int i, int j) { return q[i] != q[j] ? q[i] > q[j] : c[i] < c[j]; });
    scanf("%d", &K);
    rep(i, K) scanf("%d", &b[i]);
    node rt = nullptr;
    rep(i, K) insert(rt, new Node(i));
    rep(xx, n) {
        int i = id[xx];
        node A, B, C;
        split(rt, 2 * c[i], B, C);
        split(B, c[i], A, B);
        std::vector <node> vec;
        traverse(B, vec);
        if (C) pushval(C, -c[i]), pushkey(C, +1);
        rt = merge(A, C);
        for (node x : vec) {
            pushval(x, -c[i]), pushkey(x, +1);
            insert(rt, x);
        }
    }
    std::vector <node> vec;
    traverse(rt, vec);
    for (node x : vec) ans[x->i] = x->key;
    rep(i, K) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}