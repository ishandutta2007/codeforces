#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <cstdlib>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;
const int maxn = 100500;

struct node {
    int id;
    int x, y;

    i64 add, add_progr;
    i64 val;
    node *l, *r, *p;
    node(){}
    node(int id) : id(id), x(0), y(rand()), l(r=p=NULL) {
        add = add_progr = val = 0;
    }

    bool isl() const { return p && p->l == this; }
    bool isr() const { return p && p->r == this; }
};

inline node* push(node* t) {
    if (t) {
        t->val += t->add + t->add_progr * t->x;
        if (t->l) {
            t->l->add += t->add;
            t->l->add_progr += t->add_progr;
        }
        if (t->r) {
            t->r->add += t->add;
            t->r->add_progr += t->add_progr;
        }
        t->add = t->add_progr = 0;
    }
    return t;
}

inline node* norm(node* t) {
    if (t) {
        if (t->l) {
            t->l->p = t;
        }
        if (t->r) {
            t->r->p = t;
        }
    }
    return t;
}

void split(node* t, node *&l, node *&r, int x) {
    if (!t) return (void)(l=r=NULL);
    push(t);
    if (x < t->x)
        split(t->l, l, t->l, x), r = t;
    else
        split(t->r, t->r, r, x), l = t;
    t->p = NULL;
    norm(t);
}

node *merge(node *l, node *r) {
    if (!l) return r;
    if (!r) return l;
    push(l);
    push(r);
    if (r->y > l->y) {
        r->l = merge(l, r->l);
        return norm(r);
    } else {
        l->r = merge(l->r, r);
        return norm(l);
    }
}

void push_way_up(node* t) {
    if (t->p) {
        push_way_up(t->p);
    }
    push(t);
}

void split(node *t, node *&l, node *&r) {
    if (!t) return (void)(l=r=NULL);
    push_way_up(t);
    node *ll = t, *lr = t->r;
    if (lr) lr->p = NULL;
    t->r = NULL;
    norm(lr);
    norm(ll);
    bool lturn = true;
    while (t->p) {
        if (t->isl()) {
            t = t->p;
            if (lturn) {
                ll->p = NULL;
                t->l = lr;
            }
            lturn = 0;
            lr = t;
        } else {
            t = t->p;
            if (!lturn) {
                lr->p = NULL;
                t->r = ll;
            }
            lturn = 1;
            ll = t;
        }
        norm(t);
    }
    l = ll;
    r = lr;
}

int q;
node *nodes[maxn];
node *t;

struct query {
    int id;
    int t;
    int l, r;
    bool operator<(const query& q) const {
        return t < q.t;
    }
} queries[maxn];

set<query> curq;

struct event {
    int x;
    int t, id;
    bool operator<(const event& e) const {
        if (x != e.x) return x < e.x;
        return t < e.t;
    }
};

int n;
int st[maxn], reg[maxn], mx[maxn];

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d%d%d", &st[i], &mx[i], &reg[i]);
    scanf("%d", &q);
    forn(i, q) {
        int l, r, t;
        scanf("%d%d%d", &t, &l, &r);
        queries[i] = {i, t, l-1, r-1};
    }
}

void out(node *t) {
    if (t) {
        out(t->l);
        cout << t->id << ": " << t->x << endl;
        out(t->r);
    }
}

void push_all(node *t) {
    return;
    if (t) {
        push(t);
        push_all(t->l);
        push_all(t->r);
    }
}

void move_query(int id, int nx) {
//     cout << "move " << id << " from " << nodes[id]->x << " to " << nx << endl;
    push_all(t);
    if (nodes[id]->x != 0) {
        node *l, *r;
        split(nodes[id], l, r);
        nodes[id]->x = inf;
        split(l, l, nodes[id], inf-1);
        assert(nodes[id]->id == id);
        t = merge(l, r);
    }
    if (nx != 0) {
        nodes[id]->x = nx;
        node *l, *r;
        split(t, l, r, nx);
        t = merge(merge(l, nodes[id]), r);
    }
    push_all(t);
}

void add_query(int id) {
    auto it = curq.insert(queries[id]).first;
    assert(it != curq.begin());
    auto itp = it; ++itp;
    assert(itp != curq.end());
    if (itp->id != -1) {
        move_query(itp->id, itp->t - queries[id].t);
    }
    ----itp;
    move_query(id, queries[id].t - itp->t);
}

void remove_query(int id) {
    auto it = curq.lower_bound(queries[id]);
    assert(it != curq.begin() && it != curq.end() && it->id == id);
    move_query(id, 0);
    auto itp = it;
    ++itp;
    assert(itp != curq.end());
    auto itpp = itp;
    ----itpp;
    if (itp->id != -1) {
        move_query(itp->id, itp->t - itpp->t);
    }
    curq.erase(it);
}

void add_pony(int id) {
    if (curq.size() == 2u) return;

    // handle first
    int fq = next(curq.begin())->id;
    assert(nodes[fq]->x >= inf);
    nodes[fq]->val += min(st[id] + (i64)reg[id] * queries[fq].t, (i64)mx[id]) - mx[id];

    int max_alive = reg[id] ? mx[id] / reg[id] : (inf - 1);
    push_all(t);
    node *l, *r;
    split(t, l, r, max_alive);
    if (l) l->add_progr += reg[id];
    if (r) r->add += mx[id];
    push_all(l);
    push_all(r);
    t = merge(l, r);
}

void solve() {
    forn(i, q) {
        nodes[i] = new node(i);
    }

    vector<event> evs;
    forn(i, q) {
        evs.pb({queries[i].l, 0, queries[i].id});
        evs.pb({queries[i].r, 2, queries[i].id});
    }
    forn(i, n) {
        evs.pb({i, 1, 0});
    }

    sort(all(evs));

    curq.insert({-1,-inf,0,0});
    curq.insert({-1,inf,0,0});

    for (auto e: evs) {
        if (e.t == 0) {
            add_query(e.id);
        } else if (e.t == 2) {
            remove_query(e.id);
        } else {
            add_pony(e.x);
        }
    }

    forn(i, q) {
        push(nodes[i]);
        cout << nodes[i]->val << "\n";
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}