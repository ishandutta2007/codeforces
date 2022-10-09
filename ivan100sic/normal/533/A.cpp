// Retired?
#include <bits/stdc++.h>

using namespace std;
using namespace placeholders;
namespace R = ranges;

const int INF = 1'123'123'123;

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

    template<class P>
    pair<int, T> seek_suffix(int r, int x, int xl, int xr, T w, const P& p) {
        push(x);
        int xm = (xl+xr) >> 1;
        if (xr <= r) {
            auto xw = f(a[x].v, w);
            if (!p(xw)) return {-1, a[x].v};
            if (xr-xl == 1) return {xl, e};
            auto [zri, zrw] = seek_suffix(r, 2*x+1, xm, xr, w, p);
            if (zri != -1) return {zri, e};
            auto [zli, zlw] = seek_suffix(r, 2*x, xl, xm, f(zrw, w), p);
            return {zli, f(zlw, zrw)};
        } else if (xl >= r) {
            return {-1, e};
        } else {
            auto [zri, zrw] = seek_suffix(r, 2*x+1, xm, xr, w, p);
            if (zri != -1) return {zri, e};
            auto [zli, zlw] = seek_suffix(r, 2*x, xl, xm, f(zrw, w), p);
            return {zli, f(zlw, zrw)};
        }
    }

    void update(int l, int r, const U& u) { update(l, r, u, 1, 0, maxn); }
    T operator() (int l, int r) { return get(l, r, 1, 0, maxn); }
    
    template<class P>
    pair<int, T> seek_suffix(int r, const P& p) { return seek_suffix(r, 1, 0, maxn, e, p); }
};

template<class T = int>
decltype(auto) range_add_min(int n) {
    return segtreelazy(n, [](T x, T y) { return min(x, y); }, plus<T>(), plus<T>(),
        numeric_limits<T>::max(), T(), T());
}

int n, k;
int a[500005], b[500005];
vector<int> e[500005];

int tp[500005];
int minabove[500005];
vector<int> e_tp[500005];
void dfs1(const int x, const int p) {
    if (x == p) {
        tp[x] = -1;
        minabove[x] = INF;
    } else {
        int q = p;
        while (q != -1) {
            if (a[q] < a[x]) {
                break;
            }
            q = tp[q];
        }
        tp[x] = q;
        minabove[x] = min(minabove[p], a[p]);
    }

    for (int y : e[x]) {
        if (y != p) {
            dfs1(y, x);
        }
    }
}

int dc[2];
int sts[500005];
void dfs2(int x, int d = 0) {
    if (d < 2) dc[d] = x;
    if (d >= 1) sts[dc[1]]++;
    for (int y : e_tp[x]) dfs2(y, d+1);
}

struct group {
    int cnt, lim;

    bool operator< (const group& o) const {
        return lim < o.lim;  
    }
};

struct tree {
    vector<group> groups;
    int root;
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i : ra(0, n)) cin >> a[i];
    for (int i : ra(1, n)) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    cin >> k;
    for (int i : ra(0, k)) cin >> b[i];

    dfs1(0, 0);

    for (int i : ra(0, n)) {
        if (tp[i] != -1) {
            e_tp[tp[i]].push_back(i);
        }
    }

    vector<tree> trees;
    for (int i : ra(0, n)) {
        if (tp[i] == -1) {
            dfs2(i);
            trees.emplace_back();
            auto& t = trees.back();
            for (int j : e_tp[i]) {
                t.groups.push_back({sts[j], a[j]});
            }
            t.groups.push_back({1, minabove[i]});
            R::sort(t.groups, less<group>{});
            t.root = a[i];
        }
    }

    sort(b, b+k);
    auto st = range_add_min(k);
    for (int i : ra(0, k)) {
        st.set(i, i-k);
    }

    auto st_pos = [&](int r) {
        return upper_bound(b, b+k, r) - b;
    };

    auto st_change = [&](int r, int v) {
        // cerr << "updating add " << st_pos(r) << ' ' << v << '\n';
        st.update(0, st_pos(r), v);
    };

    // create default system
    for (auto& t : trees) {
        int z = 0;
        for (auto g : t.groups) z += g.cnt;
        st_change(t.root, z);
    }

    // cerr << "debug 1 " << st(0, 1) << '\n';
    // cerr << "debug 2 " << st(1, 2) << '\n';
    // cerr << "debug 3 " << st(2, 3) << '\n';

    // maybe it's 0?
    if (st(0, k) >= 0) {
        cout << "0\n";
        return 0;
    }

    // cerr << '\n';
    int sol = INF;
    // solve each tree
    for (auto& t : trees) {
        int gk = ssize(t.groups);
        vector<int> ps(gk + 1);
        for (int i : ra(0, gk)) {
            ps[i+1] = ps[i] + t.groups[i].cnt;
        }

        int last = t.root;
        bool br = 0;
        for (int i : ra(0, gk)) {
            auto& g = t.groups[i];
            // adjust up
            int amt = ps[gk] - ps[i];
            st_change(last, -amt);
            st_change(g.lim, amt);
            if (st(0, k) >= 0) {
                // good? we need to find the exact limit
                int pref = st.seek_suffix(st_pos(g.lim), [&](int v) {
                    return v < amt;
                }).first;

                // cerr << "sol update " << pref << ' ' << st_pos(g.lim) << ' ' << b[pref] << ' ' << t.root << ' ' << b[pref] - t.root << '\n';
                // for (int i : ra(0, st_pos(g.lim))) {
                //     cerr << "debug pref " << i << ' ' << st(i, st_pos(g.lim)) << ' ' << amt << '\n';
                // }

                sol = min(sol, b[pref] - t.root);

                // unwind changes
                int z = 0;
                for (auto [cnt, lim] : t.groups) {
                    st_change(min(lim, g.lim), -cnt);
                    z += cnt;
                }
                st_change(t.root, z);
                br = 1;
                break;
            }
            last = g.lim;
        }

        if (!br) {
            // unwind changes
            int z = 0;
            for (auto [cnt, lim] : t.groups) {
                st_change(lim, -cnt);
                z += cnt;
            }
            st_change(t.root, z);
        }
        // cerr << '\n';
    }

    if (sol == INF) sol = -1;
    cout << sol << '\n';
}