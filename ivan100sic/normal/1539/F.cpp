// Retired?
#include <bits/stdc++.h>
using namespace std;

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

template<class T = int, class F = plus<T>>
struct fenwick {
    vector<T> a;
    T e;
    F f;

    fenwick(int n, T e = T(), F f = F()) : a(n, e), e(e), f(f) {}

    void add(int p, const T& v) {
        for (p++; p <= (int)a.size(); p += p & -p)
            a[p-1] = f(a[p-1], v);
    }

    T operator() (int p) const {
        T v = e;
        for (; p; p -= p & -p)
            v = f(v, a[p-1]);
        return v;
    }
};

struct loc {
    int p, v;

    // max
    loc operator+ (const loc& b) const {
        return v > b.v ? *this : b;
    }

    // min
    loc operator* (const loc& b) const {
        return v < b.v ? *this : b;
    }
};

struct val {
    loc hi = {-5, -123123123};
    loc lo = {-5, +123123123};

    val operator+ (const val& o) const {
        return {hi + o.hi, lo * o.lo};
    }
};

struct node {
    val r[2];

    node operator+ (const node& b) const {
        return {{r[0] + b.r[0], r[1] + b.r[1]}};
    }
};

const int H = 262144;

int n;
int a[200005], ans[200005];
basic_string<int> e[200005];
segtreelazy stl(H, plus<node>(), plus<int>(), [](node n, int i) {
    n.r[0].lo.v += i;
    n.r[0].hi.v += i;
    n.r[1].lo.v += i;
    n.r[1].hi.v += i;
    return n;
}, node{}, int(0), node{});

fenwick fen(200005);

int sol[200005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        e[x] += i;
    }

    for (int i=0; i<=n; i++) {
        node nd;
        nd.r[i%2].hi = nd.r[i%2].lo = {i, i};
        stl.set(i, nd);
    }

    for (int i=1; i<=n; i++) {
        auto task = [&](int minus) {
            for (int j : e[i]) {
                vector<int> cl, cr;
                auto gr = stl(j, n+1);
                auto gl = stl(0, j);
                cr.push_back(gr.r[0].hi.p);
                cr.push_back(gr.r[1].hi.p);
                cr.push_back(gr.r[0].lo.p);
                cr.push_back(gr.r[1].lo.p);
                
                cl.push_back(gl.r[0].hi.p);
                cl.push_back(gl.r[1].hi.p);
                cl.push_back(gl.r[0].lo.p);
                cl.push_back(gl.r[1].lo.p);
                
                for (int l : cl) {
                    l++;
                    for (int r : cr) {
                        if (l < 1 || r < 1) continue;
                        int c = fen(r+1) - fen(l) + l - minus;
                        int mp = (l+r+1) / 2;
                        // cerr << "new sol " << j << ' ' << mp << ' ' << c << " with l,r =  " << l << ' ' << r << " minus = " << minus << "\n";
                        sol[j] = max(sol[j], abs(c - mp));
                    }
                }
            }
        };

        // svi su veci od mene
        task(0);

        // svi su manji od mene
        for (int j : e[i]) {
            fen.add(j, 1);
            stl.update(j, n+1, -2);
        }
        task(1);
    }

    for (int i=1; i<=n; i++) {
        cout << sol[i] << " \n"[i == n];
    }
}