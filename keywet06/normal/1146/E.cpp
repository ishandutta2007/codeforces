#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

mt19937 rnd(228);

struct treap {
    int val, sz;
    treap *l, *r;
    treap(int val, treap *l, treap *r) : val(val), sz(1), l(l), r(r) {}
    treap() {}
};

const int N = 10 * 10000 * 100 + 7;
const int MAX_SZ = N - 1e5;

treap node[N];
int ptr = 0;

treap *new_treap(int val, treap *l, treap *r) {
    node[ptr].val = val;
    node[ptr].l = l;
    node[ptr].r = r;
    node[ptr].sz = 1;
    assert(ptr < N);
    return &node[ptr++];
}

int sz(treap *t) {
    if (!t) {
        return 0;
    } else {
        return t->sz;
    }
}

void recalc(treap *t) {
    if (!t) {
        return;
    } else {
        t->sz = sz(t->l) + 1 + sz(t->r);
    }
}

void zhfs(treap *t, vector<int> &a) {
    if (!t) {
        return;
    }
    zhfs(t->l, a);
    a.push_back(t->val);
    zhfs(t->r, a);
}

pair<treap *, treap *> split(treap *t, int x) {
    if (!t) {
        return {0, 0};
    }
    if (sz(t->l) >= x) {
        auto a = split(t->l, x);
        treap *l = a.first;
        treap *r = new_treap(t->val, a.second, t->r);
        recalc(r);
        return {l, r};
    } else {
        auto a = split(t->r, x - sz(t->l) - 1);
        treap *l = new_treap(t->val, t->l, a.first);
        treap *r = a.second;
        recalc(l);
        return {l, r};
    }
}

treap *merge(treap *a, treap *b) {
    if (!a) {
        return b;
    }
    if (!b) {
        return a;
    }
    if (rnd() % (a->sz + b->sz) < a->sz) {
        treap *ret = new_treap(a->val, a->l, merge(a->r, b));
        recalc(ret);
        return ret;
    } else {
        treap *ret = new_treap(b->val, merge(a, b->l), b->r);
        recalc(ret);
        return ret;
    }
}

struct q {
    int len, from, to;
    q(int len, int from, int to) : len(len), from(from), to(to) {}
    q() {}
};

void print(treap *t) {
    if (!t) {
        return;
    }
    print(t->l);
    printf("%d ", t->val);
    print(t->r);
}

treap *build(const vector<int> &a) {
    if (a.empty()) {
        return 0;
    }
    int mid = (int)a.size() / 2;
    vector<int> l, r;
    for (int i = 0; i < mid; i++) l.push_back(a[i]);
    for (int i = mid + 1; i < (int)a.size(); i++) r.push_back(a[i]);
    treap *go = new_treap(a[mid], build(l), build(r));
    recalc(go);
    return go;
}

treap *cur = 0, *rev = 0;

treap *get_segm(treap *t, int l, int r) {
    l++, r++;
    auto a = split(t, r);
    auto b = split(a.first, l - 1);
    return b.second;
}

treap *to_copy(treap *t, int l, int r, treap *go) {
    l++, r++;
    auto a = split(t, r);
    auto b = split(a.first, l - 1);
    return merge(b.first, merge(go, a.second));
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<char, int> > b;
    for (int i = 0; i < q; i++) {
        char c;
        cin >> c;
        int x;
        cin >> x;
        b.push_back({c, x});
    }
    vector<int> arr, brr;
    for (int x = -100000; x <= 100000; x++) {
        arr.push_back(x);
        // cur = merge(cur, new treap(x, 0, 0));
    }
    for (int x = 100000; x >= -100000; x--) {
        brr.push_back(x);
        //    rev = merge(rev, new treap(x, 0, 0));
    }
    cur = build(arr);
    rev = build(brr);
    for (int i = q - 1; i >= 0; i--) {
        if (ptr >= MAX_SZ) {
            vector<int> arr, brr;
            zhfs(cur, arr);
            zhfs(rev, brr);
            ptr = 0;
            cur = build(arr);
            rev = build(brr);
        }
        char c = b[i].first;
        int x = b[i].second;
        int l_a = -100000, r_a = x - 1;
        int l_b = -(x - 1), r_b = 100000;
        if (c == '>') {
            l_a = x + 1, r_a = 100000;
            l_b = -100000, r_b = -(x + 1);
        }
        if (l_a <= r_a) {
            l_a += 100000, r_a += 100000;
            l_b += 100000, r_b += 100000;
            treap *new_cur = to_copy(cur, l_a, r_a, get_segm(rev, l_a, r_a));
            treap *new_rev = to_copy(rev, l_b, r_b, get_segm(cur, l_b, r_b));
            cur = new_cur, rev = new_rev;
        }
    }
    vector<int> ret;
    zhfs(cur, ret);
    for (int i = 0; i < n; i++) {
        cout << ret[a[i] + 100000] << ' ';
    }
    cout << '\n';
}