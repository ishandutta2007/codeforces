#include <bits/stdc++.h>
using namespace std;


struct Node {
    int sz;
    bool rev;
    Node *l, *r, *p, *pp;
    Node *mx; int val;
    int subtree, s0;
    int id;

    Node();
    explicit Node(nullptr_t) {
        l = r = p = pp = this;
        sz = 0; rev = 0;
        mx = this; val = -1;
        subtree = 0; s0 = 0;
        id = -1;
    }
    void update();
    void push() {
        if (rev) {
            swap(l, r);
            rev = 0;
            l->rev ^= 1;
            r->rev ^= 1;
        }
    }
};
typedef Node* node;
node NIL = new Node(nullptr);

Node::Node() {
    sz = 1;
    rev = 0;
    l = r = p = pp = NIL;
    mx = this; val = -1;
    s0 = subtree = 0;
}

void Node::update() {
    sz = (this != NIL) + l->sz + r->sz;
    l->p = r->p = this;
    mx = this;
    if (l->mx->val > mx->val) mx = l->mx;
    if (r->mx->val > mx->val) mx = r->mx;
    subtree = s0 + l->subtree + r->subtree;
}

void rotate(node v) {
    assert(v != NIL && v->p != NIL && !v->rev && !v->p->rev);
    auto pr = v->p;
    if (pr->l == v) {
        pr->l = v->r;
        v->r = pr;
    } else {
        pr->r = v->l;
        v->l = pr;
    }
    swap(v->p, pr->p);
    swap(v->pp, pr->pp);
    if (v->p != NIL) {
        assert(v->p->l == pr || v->p->r == pr);
        if (v->p->l == pr) v->p->l = v;
        else v->p->r = v;
    }
    pr->update(); v->update();
}

void rotate2(node v) {
    assert(v != NIL && v->p != NIL);
    v->p->p->push(); v->p->push(); v->push();
    if (v->p->p != NIL) {
        if ((v->p->p->l == v->p) == (v->p->l == v)) {
            rotate(v->p);
        } else {
            rotate(v);
        }
    }
    rotate(v);
}

void splay(node v) {
    while (v->p != NIL) rotate2(v);
}

struct LinkCut {
    int n;
    vector<Node> nodes;
    vector<node> pnode;

    LinkCut() {}
    /*LinkCut(int _n) {
        n = _n;
        nodes.assign(n, Node());
        for (int i = 0; i < n; i++) {
            nodes[i].id = i;
            pnode[i] = &nodes[i];
        }
    }*/

    multiset<int> st;
    int odd;

    void upd(int x, int d) {
        if (d == +1) {
            st.insert(x);
            odd += x % 2 == 1;
        } else {
            st.erase(st.find(x));
            odd -= x % 2 == 1;
        }
    }

    LinkCut(int _n1, int _m1) {
        n = _n1 + _m1;
        nodes.assign(n, Node());
        pnode.assign(n, NIL);
        odd = 0;
        for (int i = 0; i < n; i++) {
            nodes[i].id = i;
            pnode[i] = &nodes[i];
            pnode[i]->s0 = i < _n1;
            pnode[i]->update();
            upd(pnode[i]->subtree, +1);
        }
    }

    void cutRight(node v) {
        v->push();
        splay(v);
        v->r->pp = v;
        v->s0 += v->r->subtree;
        v->r->p = NIL;
        v->r = NIL;
        v->update();
    }

    void expose(int x) {
        cutRight(pnode[x]);
        for (node v = pnode[x];;) {
            splay(v);
            node p = v->pp;
            if (p == NIL) break;
            cutRight(p);
            p->r = v;
            v->pp = NIL;
            p->s0 -= v->subtree;
            p->update();
            v = p;
        }
        splay(pnode[x]);
    }

    void makeRoot(int x) {
        expose(x);
        pnode[x]->rev = 1;
    }

    void add(int x, int y) {
        makeRoot(y);
        makeRoot(x);
        upd(pnode[x]->subtree, -1);
        upd(pnode[y]->subtree, -1);
        pnode[x]->pp = pnode[y];
        pnode[y]->s0 += pnode[x]->subtree;
        pnode[y]->update();
        upd(pnode[y]->subtree, +1);
    }

    void del(int x, int y) {
        expose(x);
        upd(pnode[x]->subtree, -1);
        splay(pnode[y]);
        if (pnode[y]->pp != pnode[x]) {
            swap(x, y);
            expose(x);
            splay(pnode[y]);
        }
        pnode[y]->pp = NIL;
        pnode[x]->s0 -= pnode[y]->subtree;
        pnode[x]->update();
        upd(pnode[x]->subtree, +1);
        upd(pnode[y]->subtree, +1);
    }

    node max(int u, int v) {
        makeRoot(u);
        expose(v);
        return pnode[v]->mx;
    }

    bool connected(int u, int v) {
        makeRoot(u);
        expose(v);
        expose(u);
        splay(pnode[v]);
        return pnode[v]->pp == pnode[u];
    }
};

void print(vector<int> v) {
    for (int x : v) printf("%d\n", x);
}

vector<int> fast(int n, vector<pair<pair<int, int>, int> > ed) {
    int m = ed.size();

    LinkCut lc(n, m);
    vector<int> ans;
    set<pair<int, int> > st;

    auto cadd = [&](int id) {
        lc.add(n + id, ed[id].first.first);
        lc.add(n + id, ed[id].first.second);
        st.insert({ed[id].second, id});

    };

    auto cdel = [&](int id) {
        lc.del(n + id, ed[id].first.first);
        lc.del(n + id, ed[id].first.second);
        st.erase({ed[id].second, id});
    };

    for (int i = 0; i < m; i++) {
        int u = ed[i].first.first, v = ed[i].first.second, w = ed[i].second;
        bool f = lc.connected(u, v);
        if (f) {
            auto x = lc.max(u, v);
            if (x->val > w) {
                int id = x->id - n;
                assert(0 <= id && id < m);
                cdel(id);
                f = 0;
            }
        }
        if (!f) {
            lc.nodes[n + i].val = w;
            cadd(i);
        }
        int last = -1;
        while (lc.odd == 0) {
            assert(!st.empty());
            last = st.rbegin()->second;
            cdel(last);
        }
        if (last != -1) cadd(last);
        ans.push_back(lc.odd == 0 ? st.rbegin()->first : -1);
    }
    return ans;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<pair<pair<int, int>, int> > ed(m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &ed[i].first.first, &ed[i].first.second, &ed[i].second);
            ed[i].first.first--;
            ed[i].first.second--;
        }
        print(fast(n, ed));
    }

    return 0;
}