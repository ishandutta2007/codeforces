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

template<class Tree>
struct hld {
    vector<int> p, h, d, r, pos;
    Tree& tree;

    hld(Tree& tree) : tree(tree) {}

    int dfs(vector<vector<int>>& e, int x) {
        int sz = 1, best = 0;
        for (int y : e[x]) {
            if (y == p[x])
                continue;
            p[y] = x;
            d[y] = d[x] + 1;
            int z = dfs(e, y);
            if (z > best) {
                best = z;
                h[x] = y;
            }
            sz += z;
        }
        return sz;
    }

    void init(vector<vector<int>>& e, int root = 0) {
        int n = e.size();
        p = h = d = r = pos = vector<int>(n, -1);
        d[root] = 0;
        dfs(e, root);
        int k = 0;
        for (int i=0; i<n; i++) {
            if (i == root || h[p[i]] != i) {
                for (int j=i; j!=-1; j=h[j]) {
                    r[j] = i;
                    pos[j] = k++;
                }
            }
        }
    }

    void set(int x, auto y) {
        tree.set(pos[x], y);
    }

    void path(int x, int y, auto op) {
        while (r[x] != r[y]) {
            if (d[r[x]] > d[r[y]])
                swap(x, y);
            op(pos[r[y]], pos[y]);
            y = p[r[y]];
        }
        if (d[x] > d[y])
            swap(x, y);
        if (x != y)
            op(pos[h[x]], pos[y]);
    }

    void update(int x, int y, auto v) {
        path(x, y, [this, &v](int l, int r) {
            tree.update(l, r+1, v);
        });
    }

    auto operator() (int x, int y) {
        auto v = tree.e;
        path(x, y, [this, &v](int l, int r) {
            v = tree.f(v, tree(l, r+1));
        });
        return v;
    }
};

struct stnode {
    ull ha, hb;
    ll sa, sb;
};

stnode add_ee(stnode u, stnode v) {
    return {
        u.ha + v.ha,
        u.hb + v.hb,
        u.sa + v.sa,
        u.sb + v.sb,
    };
}

stnode add_eu(stnode u, bool v) {
    if (!v) return u;
    return { u.hb, u.ha, u.sb, u.sa };
}

mt19937_64 eng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n;
vector<pair<int, int>> e[200005];
ull h[200005];

int pe[200005], par[2000005];
void dfs(int x, int p) {
    for (auto [y, i] : e[x]) {
        if (y == p) continue;
        pe[y] = i;
        par[y] = x;
        dfs(y, x);
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i : ra(1, n)) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        e[x].emplace_back(y, i);
        e[y].emplace_back(x, i);
    }

    generate(h, h+n, eng);
    dfs(0, 0);
    
    stnode neut{0, 0, 0, 0};
    segtreelazy stl(n, add_ee, bit_xor<bool>{}, add_eu, neut, false, neut);
    hld wtf(stl);
    vector<vector<int>> wtfe(n);
    for (int x : ra(0, n)) {
        for (auto [y, i] : e[x]) {
            wtfe[x].push_back(y);
        }
    }
    wtf.init(wtfe, 0);

    ull hashsum = h[0];

    while (1) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            x--;

            ull hu = h[x] + h[par[x]];
            wtf.set(x, stnode{0, hu, 0, pe[x]});
            wtf.update(0, x, true);
            hashsum += h[x];

            auto sum = stl(0, n);
            if (sum.ha != hashsum) {
                cout << "0\n" << flush;
            } else {
                cout << sum.sa << "\n" << flush;
            }

        } else if (t == 2) {

            auto sum = stl(0, 1e9);
            if (sum.ha != hashsum) {
                cout << "0\n" << flush;
                continue;
            }

            vector<int> sol;
            for (int x : ra(1, n)) {
                auto g = wtf(x, par[x]);
                if (g.sa > 0) {
                    sol.push_back(g.sa);
                }
            }
            cout << sol.size();
            R::sort(sol);
            for (int i : sol) cout << ' ' << i;
            cout << '\n' << flush;
        } else {
            return 0;
        }
    }
}