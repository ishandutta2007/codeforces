#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct Node {
    bool r;
    int v;
    int fix;
    int sz;
    Node *ls;
    Node *rs;

    Node(int _v):
        r(0),
        v(_v),
        fix(rand()),
        sz(1),
        ls(0),
        rs(0) {
    }

    void push() {
        r ^= 1;
        swap(ls, rs);
    }

    void pushdown() {
        if (r) {
            if (ls) ls->push();
            if (rs) rs->push();
            r = 0;
        }
    }

    void pushup() {
        sz = 1;
        if (ls) sz += ls->sz;
        if (rs) sz += rs->sz;
    }
};

Node *join(Node *a, Node *b) {
    if (!a || !b) return a ? a : b;
    a->pushdown();
    b->pushdown();
    if (a->fix < b->fix) {
        a->rs = join(a->rs, b);
        a->pushup();
        return a;
    } else {
        b->ls = join(a, b->ls);
        b->pushup();
        return b;
    }
}

void split(Node *x, int k, Node *&a, Node *&b) {
    if (!x) return void(a = b = 0);
    x->pushdown();
    int lsz = x->ls ? x->ls->sz : 0;
    if (lsz + 1 <= k) {
        a = x;
        split(x->rs, k - lsz - 1, a->rs, b);
        a->pushup();
    } else {
        b = x;
        split(x->ls, k, a, b->ls);
        b->pushup();
    }
}

int main() {
    int n, q, m;
    scanf("%d %d %d", &n, &q, &m);
    vector <int> a(n);
    rep(i, n) scanf("%d", &a[i]);
    Node *rt = 0;
    rep(i, n) rt = join(rt, new Node(a[i]));
    while (q --) {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        -- l;
        if (op == 1) {
            Node *a, *b, *c, *d;
            split(rt, r, c, d);
            split(c, r - 1, b, c);
            split(b, l, a, b);
            rt = join(join(a, c), join(b, d));
        } else {
            Node *a, *b, *c;
            split(rt, r, b, c);
            split(b, l, a, b);
            b->push();
            rt = join(join(a, b), c);
        }
    }
    while (m --) {
        int p;
        scanf("%d", &p);
        Node *a, *b, *c;
        split(rt, p, b, c);
        split(b, p - 1, a, b);
        printf("%d ", b->v);
        rt = join(join(a, b), c);
    }
    return 0;
}