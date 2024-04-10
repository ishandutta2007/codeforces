// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T>
struct compressor {
    vector<T*> v;
    void operator+=(T& x) { v.push_back(&x); }
    ~compressor() { (*this)(); }

    T operator() (T init = T()) {
        sort(v.begin(), v.end(), [](int* x, int* y) { return *x < *y; });
        T last = 0, q = 0;
        for (size_t i=0; i<v.size(); i++) {
            if (!i || *v[i] != last) q++;
            last = *v[i];
            *v[i] = q - 1 + init;
        }
        return q;
    }
};

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

struct entry {
    int val, row;
};

entry mx(entry x, entry y) {
    return x.val > y.val ? x : y;
}

const entry neut = {0, 0};

struct seg {
    int l, r;
    entry e;
};

int n, m;
vector<seg> a[300005];
segtreelazy stl(600005, mx, mx, mx, neut, neut, neut);
int d[300005], p[300005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int x, l, r;
        cin >> x >> l >> r;
        a[x].push_back({l, r, neut});
    }

    {
        compressor<int> comp;
        for (int i=1; i<=n; i++) {
            for (seg& s : a[i]) {
                comp += s.l;
                comp += s.r;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        int m = a[i].size();
        entry maxval = neut;
        for (int j=0; j<m; j++) {
            a[i][j].e = stl(a[i][j].l, a[i][j].r+1);
            a[i][j].e.val += 1;
            maxval = mx(maxval, a[i][j].e);
        }

        d[i] = maxval.val;
        p[i] = maxval.row;

        for (int j=0; j<m; j++) {
            stl.update(a[i][j].l, a[i][j].r+1, entry{d[i], i});
        }
    }

    int q = max_element(d+1, d+n+1) - d;
    cout << n - d[q] << '\n';
    vector<int> alive(n+1);
    iota(begin(alive), end(alive), 1);
    for (; q; q=p[q]) alive[q] = 0;
    for (int i=1; i<=n; i++) {
        if (alive[i]) cout << i << ' ';
    }
    cout << '\n';
}