// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T = string, class F = plus<T>>
struct link_cut_noncommutative {
    // Credits: https://codeforces.com/blog/entry/75885
    // 1-based

    struct node {
        T v, s, r;
        int c[2] = {0, 0}, p = 0, q = 0;
        bool f = false;
    };

    vector<node> a;
    F f;

    link_cut_noncommutative(int n, T e = T(), F f = F(), T v = T()) : a(n+1), f(f) {
        for (int i=1; i<=n; i++) {
            a[i].v = a[i].s = a[i].r = v;
        }
        a[0].v = a[0].s = a[0].r = e;
    }

    int dir(int x, int y) { return a[x].c[1] == y; }

    void sch(int x, int d, int y) {
        if (x) a[x].c[d] = y, pull(x);
        if (y) a[y].p = x;
    }

    const T& rdval(int x, int d) {
        return (a[x].f ^ d) ? a[x].r : a[x].s;
    }

    void pull(int x) {
        if (!x) return;
        a[x].s = f(rdval(a[x].c[0], 0), f(a[x].v, rdval(a[x].c[1], 0)));
        a[x].r = f(rdval(a[x].c[1], 1), f(a[x].v, rdval(a[x].c[0], 1)));
    }

    void push(int x) {
        if (!x || !a[x].f) return;
        swap(a[x].s, a[x].r);
        int& l = a[x].c[0];
        int& r = a[x].c[1];
        a[l].f ^= 1;
        a[r].f ^= 1;
        swap(l, r);
        a[x].f = 0;
    }

    void rotate(int x, int d) {
        int y = a[x].p, z = a[y].p, w = a[x].c[d];
        swap(a[x].q, a[y].q);
        sch(y, !d, w);
        sch(x, d, y);
        sch(z, dir(z, y), x);
    }

    void splay(int x) {
        for (push(x); a[x].p;) {
            int y = a[x].p, z = a[y].p;
            push(z);
            push(y);
            push(x);
            int dx = dir(y, x), dy = dir(z, y);
            if (!z) {
                rotate(x, !dx);
            } else if (dx == dy) {
                rotate(y, !dx);
                rotate(x, !dx);
            } else {
                rotate(x, dy);
                rotate(x, dx);
            }
        }
    }

    void make_root(int u) {
        access(u);
        int l = a[u].c[0];
        a[l].f ^= 1;
        swap(a[l].p, a[l].q);
        sch(u, 0, 0);
    }

    void access(int w) {
        for (int v=0, u=w; u; u=a[v=u].q) {
            splay(u);
            splay(v);
            int r = a[u].c[1];
            a[v].q = 0;
            swap(a[r].p, a[r].q);
            sch(u, 1, v);
        }
        splay(w);
    }

    void link(int u, int v) {
        make_root(v);
        a[v].q = u;
    }

    void cut(int u, int v) {
        make_root(u);
        access(u);
        splay(v);
        a[v].q = 0;
    }

    bool connected(int u, int v) {
        if (u == v) return true;
        make_root(u);
        access(v);
        splay(u);
        return a[v].p == u || a[a[v].p].p == u;
    }

    void update(int x, const T& v) {
        make_root(x);
        access(x);
        a[x].v = a[x].s = v;
    }

    T operator()(int u, int v) {
        make_root(u);
        access(v);
        return a[v].f ? a[v].r : a[v].s;
    }
};

struct path {
    bool neut;
    ll first, last, sum;

    path() : neut(true) {}

    path(ll x) {
        first = last = x;
        sum = 0;
        neut = false;
    }

    path operator+ (const path& b) const {
        if (neut) return b;
        if (b.neut) return *this;
        path result;
        result.neut = false;
        result.first = first;
        result.last = b.last;
        result.sum = sum + b.sum + max(abs(last + b.first), abs(last - b.first));
        return result;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, q;
    cin >> n >> q;

    link_cut_noncommutative<path> lct(n);

    for (int i : ra(1, n+1)) {
        int x;
        cin >> x;
        lct.update(i, x);
    }

    for (int i : ra(1, n)) {
        int x, y;
        cin >> x >> y;
        lct.link(x, y);
    }

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1) {
            lct.update(y, z);
        } else {
            cout << lct(y, z).sum << '\n';
        }
    }
}