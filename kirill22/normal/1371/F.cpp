#include<bits/stdc++.h>

using namespace std;

struct node {
    int ans = 0, l = 0, r = 0, sz = 0;
    int tl, tr;
    node() {};
};

string s;
vector<node> t, t2;
vector<int> d;

node merge(node a, node b) {
    if (a.sz == 0) return b;
    if (b.sz == 0) return a;
    node res;
    res.sz = a.sz + b.sz;
    res.tl = a.tl;
    res.tr = b.tr;
    res.l = a.l;
    res.r = b.r;
    if (a.l == a.sz && !(a.tr == 0 && b.tl == 1)) {
        res.l = max(res.l, a.sz + b.l);
    }
    if (b.r == b.sz && !(b.tl == 1 && a.tr == 0)) {
        res.r = max(res.r, b.sz + a.r);
    }
    res.ans = max({res.l, res.r, a.ans, b.ans});
    if (!(a.tr == 0 && b.tl == 1)) {
        res.ans = max(res.ans, a.r + b.l);
    }
    return res;
}

void build(int v, int l, int r) {
    if (l + 1 == r) {
        t[v].ans = t[v].l = t[v].r = t[v].sz = 1;
        t2[v].ans = t2[v].l = t2[v].r = t2[v].sz = 1;
        if (s[l] == '>') t[v].tr = 1, t[v].tl = 1, t2[v].tr = t2[v].tl = 0;
        else t[v].tr = t[v].tl = 0, t2[v].tr = t2[v].tl = 1;
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
    t2[v] = merge(t2[v * 2 + 1], t2[v * 2 + 2]);
}

void push(int v, int l, int r) {
    if (d[v] == 0) return;
    if (l + 1 != r) {
        d[v * 2 + 1] ^= 1;
        d[v * 2 + 2] ^= 1;
    }
    swap(t[v], t2[v]);
    d[v] = 0;
}

node get(int v, int l, int r, int l1, int r1) {
    push(v, l, r);
    if (l >= r1 || l1 >= r) return node();
    if (l1 <= l && r <= r1) return t[v];
    int m = (l + r) / 2;
    return merge(get(v * 2 + 1, l, m, l1, r1), get(v * 2 + 2, m, r, l1, r1));
}

void upd(int v, int l, int r, int l1, int r1) {
    push(v, l, r);
    if (l >= r1 || l1 >= r) return;
    if (l1 <= l && r <= r1) {
        d[v] ^= 1;
        push(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(v * 2 + 1, l, m, l1, r1);
    upd(v * 2 + 2, m, r, l1, r1);
    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
    t2[v] = merge(t2[v * 2 + 1], t2[v * 2 + 2]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    cin >> s;
    t.resize(4 * n);
    t2.resize(4 * n);
    d.resize(4 * n, 0);
    build(0, 0, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        upd(0, 0, n, l, r + 1);
        node res = get(0, 0, n, l, r + 1);
        int ans = res.ans;
        cout << ans << '\n';
    }
}