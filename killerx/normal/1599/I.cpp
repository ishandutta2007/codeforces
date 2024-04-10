#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct Node {
    bool rev;
    bool type, have;
    int tag, eid, max;
    Node *ch[2], *fa;

    Node(bool f) {
        rev = false;
        type = have = f;
        tag = -2; eid = max = -1;
        ch[0] = ch[1] = fa = nullptr;
    }
};

inline void pushtag(Node *x, int t) {
    x->tag = t;
    if (x->type) x->eid = t; else x->eid = -1;
    if (x->have) x->max = t; else x->max = -1;
}

inline void pushrev(Node *x) {
    x->rev ^= 1;
    std::swap(x->ch[0], x->ch[1]);
}

inline void pushdown(Node *x) {
    if (x->tag != -2) {
        if (x->ch[0]) pushtag(x->ch[0], x->tag);
        if (x->ch[1]) pushtag(x->ch[1], x->tag);
        x->tag = -2;
    }
    if (x->rev) {
        if (x->ch[0]) pushrev(x->ch[0]);
        if (x->ch[1]) pushrev(x->ch[1]);
        x->rev = false;
    }
}

inline void pushup(Node *x) {
    x->max = x->eid;
    if (x->ch[0]) x->max = std::max(x->max, x->ch[0]->max);
    if (x->ch[1]) x->max = std::max(x->max, x->ch[1]->max);
    x->have = x->type;
    if (x->ch[0]) x->have |= x->ch[0]->have;
    if (x->ch[1]) x->have |= x->ch[1]->have;
}

inline bool nroot(Node *x) {
    return x->fa && (x->fa->ch[0] == x || x->fa->ch[1] == x);
}

inline void rotate(Node *x) {
    Node *y = x->fa, *z = y->fa;
    bool d = x == y->ch[1];
    if (nroot(y)) z->ch[y == z->ch[1]] = x;
    x->fa = z;
    y->ch[d] = x->ch[d ^ 1];
    if (x->ch[d ^ 1]) x->ch[d ^ 1]->fa = y;
    x->ch[d ^ 1] = y;
    y->fa = x;
    pushup(y);
    pushup(x);
}

void update_tag(Node *x) {
    if (nroot(x)) update_tag(x->fa);
    pushdown(x);
}

inline void splay(Node *x) {
    update_tag(x);
    while (nroot(x)) {
        Node *y = x->fa, *z = y->fa;
        if (nroot(y)) rotate((x == y->ch[1]) ^ (y == z->ch[1]) ? x : y);
        rotate(x);
    }
}

inline void access(Node *x) {
    Node *last = nullptr;
    while (x) {
        splay(x);
        x->ch[1] = last;
        pushup(x);
        last = x;
        x = x->fa;
    }
}

inline void makeroot(Node *x) {
    access(x);
    splay(x);
    pushrev(x);
}

inline Node *findroot(Node *x) {
    access(x);
    splay(x);
    pushdown(x);
    while (x->ch[0]) {
        x = x->ch[0];
        pushdown(x);
    }
    splay(x);
    return x;
}

inline bool same(Node *x, Node *y) {
    makeroot(x);
    if (findroot(y) != x) return false;
    return true;
}

inline Node *split(Node *x, Node *y) {
    makeroot(x);
    access(y);
    splay(y);
    return y;
}

inline void link(Node *x, Node *y) {
    makeroot(x);
    access(y);
    splay(y);
    x->fa = y;
}

inline void cut(Node *x, Node *y) {
    makeroot(x);
    access(y);
    splay(y);
    y->ch[0] = x->fa = nullptr;
    pushup(y);
}

const int mxn = 2.5e5;
const int mxm = 5e5;

int n, m;
int E[mxm][2];

std::set <int> tr, ntr;
Node *nd[mxn], *ed[mxm];

inline bool link_cact(int u, int v, int e) {
    if (!same(nd[u], nd[v])) {
        tr.insert(e);
        *ed[e] = Node(true);
        link(nd[u], ed[e]);
        link(nd[v], ed[e]);
        return true;
    } else {
        Node *x = split(nd[u], nd[v]);
        if (x->max != -1) return false;
        ntr.insert(e);
        pushtag(x, e);
        return  true;
    }
}

inline void cut_cact(int u, int v, int e) {
    if (tr.find(e) != tr.end()) {
        tr.erase(e);
        Node *x = split(nd[u], nd[v]);
        int ne = x->max;
        if (ne != -1) {
            ntr.erase(ne);
            tr.insert(ne);
            int nu = E[ne][0], nv = E[ne][1];
            Node *y = split(nd[nu], nd[nv]);
            pushtag(y, -1);
            cut(nd[u], ed[e]);
            cut(nd[v], ed[e]);
            *ed[ne] = Node(true);
            link(nd[nu], ed[ne]);
            link(nd[nv], ed[ne]);
        } else {
            cut(nd[u], ed[e]);
            cut(nd[v], ed[e]);
        }
    } else {
        ntr.erase(e);
        Node *x = split(nd[u], nd[v]);
        pushtag(x, -1);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    rep(i, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        -- u, -- v;
        E[i][0] = u, E[i][1] = v;
    }
    rep(i, n) nd[i] = new Node(false);
    rep(i, m) ed[i] = new Node(true);
    long long ans = 0;
    for (int r = 0, l = 0; r < m; ++ r) {
        while (!link_cact(E[r][0], E[r][1], r)) {
            cut_cact(E[l][0], E[l][1], l);
            ++ l;
        }
        assert(same(nd[E[r][0]], nd[E[r][1]]));
//        eprintf("[%d, %d]\n", l + 1, r + 1);
        ans += (r - l + 1);
    }
    printf("%lld\n", ans);
    return 0;
}