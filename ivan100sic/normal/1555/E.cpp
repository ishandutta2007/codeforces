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

struct seg {
    int l, r, w;

    bool operator< (const seg& b) const {
        return w < b.w;
    }
};

int n, m;
seg a[300005];
segtreelazy st(2000005, [](int x, int y) { return min(x, y); }, plus<int>(), plus<int>(), int(1e9), 0, 0);

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].w;
        a[i].l *= 2;
        a[i].r *= 2;
        a[i].r++;
    }

    sort(a, a+n);
    int sol = 1e9;
    for (int l=0, r=0; l<n; l++) {
        while (r < n && st(2, 2*m+1) == 0) {
            st.update(a[r].l, a[r].r, 1);
            r++;
        }

        if (st(2, 2*m+1) > 0) {
            sol = min(sol, a[r-1].w - a[l].w);
        }

        st.update(a[l].l, a[l].r, -1);
    }

    cout << sol << '\n';
}