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

    void update(int l, int r, const U& u) { update(l, r, u, 1, 0, maxn); }
    T operator() (int l, int r) { return get(l, r, 1, 0, maxn); }
};

struct Node {
    ll sum_a, sum_ab, sum_ab2, max_b;

    Node operator+(const Node& y) const {
        return {
            sum_a + y.sum_a,
            sum_ab + y.sum_ab,
            sum_ab2 + y.sum_ab2,
            max(max_b, y.max_b),
        };
    }

    Node operator+(ll x) const {
        return {
            sum_a,
            sum_ab + x * sum_a,
            sum_ab2 + 2*sum_ab*x + sum_a*x*x,
            max_b + x,
        };
    }
};

const Node neut = {0ll, 0ll, 0ll, (ll)-1e18};
const Node ground = {0ll, 0ll, 0ll, 0ll};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    segtreelazy stl(200005, plus<>{}, plus<>{}, plus<>{}, neut, 0ll, ground);
    string has(200005, 0);

    int q, d;
    cin >> q >> d;
    for (int i : ra(0, q)) {
        int x;
        cin >> x;
        int dir = has[x] ? -1 : 1;
        has[x] ^= 1;
        stl.update(x+1, x+d+1, dir);
        ll elb = stl(x, x+1).max_b;
        stl.set(x, {
            has[x],
            has[x] * elb,
            has[x] * elb * elb,
            elb
        });

        auto root = stl(0, 1e9);
        cout << (root.sum_ab2 - root.sum_ab) / 2 << '\n';
    }
}