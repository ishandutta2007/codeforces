// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T, class U, class F, class G, class H>
struct segtreelazy {
    struct node { T v; U u; };
    int maxn;
    vector<node> a;
    T e; U eu;
    F f; G g; H h;
    // Add two elements
    // Add two updaters
    // Add an element and an update
    // Neutral element
    // Neutral update
    // Bottom level element
    segtreelazy(int n, F f, G g, H h, T e = T(), U eu = U(), T v = T()) :
        e(e), eu(eu), f(f), g(g), h(h)
    {
        maxn = 1;
        while (maxn < n)
            maxn <<= 1;
        a.assign(2*maxn, node{v, eu});
        for (int i=maxn-1; i; i--)
            a[i].v = f(a[2*i].v, a[2*i+1].v);
    }

    void push(int x) {
        a[x].v = h(a[x].v, a[x].u);
        if (x < maxn) {
            a[2*x  ].u = g(a[2*x  ].u, a[x].u);
            a[2*x+1].u = g(a[2*x+1].u, a[x].u);
        }
        a[x].u = eu;
    }

    void set(int p, const T& v) {
        int x = 1, xl = 0, xr = maxn;
        while (xr-xl > 1) {
            push(x);
            int xm = (xl+xr) >> 1;
            (p < xm ? xr : xl) = xm;
            x = 2*x + (p >= xm);
        }
        a[x] = {v, eu};
        do {
            push(x^1);
            x >>= 1;
            a[x].v = f(a[2*x].v, a[2*x+1].v);
        } while (x > 1);
    }

    void update(int l, int r, const U& u, int x, int xl, int xr) {
        if (r <= xl || xr <= l)
            return push(x);
        if (l <= xl && xr <= r)
            return a[x].u = g(a[x].u, u), push(x);
        push(x);
        int xm = (xl+xr) >> 1;
        update(l, r, u, 2*x  , xl, xm);
        update(l, r, u, 2*x+1, xm, xr);
        a[x].v = f(a[2*x].v, a[2*x+1].v);
    }

    T get(int l, int r, int x, int xl, int xr) {
        push(x);
        if (r <= xl || xr <= l)
            return e;
        if (l <= xl && xr <= r)
            return a[x].v;
        int xm = (xl+xr) >> 1;
        return f(get(l, r, 2*x, xl, xm), get(l, r, 2*x+1, xm, xr));
    }

    bool seek_right(int l, int x, int xl, int xr, int& zw, T& zv, auto c) {
        push(x);
        if (xr <= l)
            return true;
        if (l <= xl && !c(f(zv, a[x].v))) {
            zw += xr-xl;
            zv = f(zv, a[x].v);
            return true;
        }
        if (xr-xl == 1)
            return false;
        int xm = (xl+xr) >> 1;
        if (seek_right(l, 2*x, xl, xm, zw, zv, c))
            return seek_right(l, 2*x+1, xm, xr, zw, zv, c);
        return false;
    }

    int seek_right(int l, auto c) {
        int zw = 0;
        T zv = e;
        if (seek_right(l, 1, 0, maxn, zw, zv, c))
            return -1;
        return zw + 1;
    }

    void update(int l, int r, const U& u) { update(l, r, u, 1, 0, maxn); }
    T operator() (int l, int r) { return get(l, r, 1, 0, maxn); }
};

template<class T = int>
decltype(auto) range_add_sum(int n) {
    struct node {
        T s; int l;
        node operator+ (const node& b) const { return {s + b.s, l + b.l}; }
        T operator() () const { return s; }
    };
    return segtreelazy(n, plus<node>(), plus<T>(), [](node n, T v) {
        return node{n.s + v * n.l, n.l}; }, node{T(), 0}, T(), node{T(), 1});
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    auto stl = range_add_sum<int>(222222);

    auto add = [&](int x) {
        int r = stl.seek_right(x, [&](auto s) { return s.s != s.l; }) + x - 1;

        stl.update(x, r, -1);
        stl.update(r, r+1, 1);
    };

    auto rem = [&](int x) {
        int r = stl.seek_right(x, [&](auto s) { return s.s != 0; }) + x - 1;

        stl.update(x, r, 1);
        stl.update(r, r+1, -1);
    };

    auto val = [&] {
        return *R::lower_bound(ra(0, stl.maxn), true, {}, [&](int m) {
            return stl(m, stl.maxn).s == 0;
        }) - 1;
    };

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i : ra(0, n)) {
        int x;
        cin >> x;
        add(x);
        a[i] = x;
    }

    while (q--) {
        int p, x;
        cin >> p >> x;
        p--;
        rem(a[p]);
        a[p] = x;
        add(a[p]);
        cout << val() << '\n';
    }
}