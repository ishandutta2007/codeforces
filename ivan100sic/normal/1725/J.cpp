// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<class T, class D, class E, class G, class U, class F = plus<D>>
struct tree_dp {
    vector<T> a;
    D e;
    vector<D> up, dn, rt;
    F f;
    G g;
    U u;
    vector<pair<int, E>*> p;
    vector<vector<pair<int, E>>> h;

    // a : vertex array - typed T
    // b : array of edges - typed E
    // g : (D, T) -> D - extends the sum of subtrees with the root vertex
    // u : (D, E) -> D - extends a subtree with an edge
    // e : neutral element of D
    // f : (D, D) -> D - adds together two (extended) subtrees
    tree_dp(const vector<T>& a, const vector<tuple<int, int, E>>& b, G g, U u, D e = D(), F f = F()) :
        a(a), e(e), up(a.size()), dn(a.size()), f(f), g(g), u(u), p(a.size()), h(a.size())
    {
        for (auto [x, y, z] : b) {
            h[x].emplace_back(y, z);
            h[y].emplace_back(x, z);
        }
        dfs1(0, 0);
        dfs2(0);
        rt.resize(a.size());
        rt[0] = dn[0];
        for (int x=1; x<(int)a.size(); x++) {
            D d = u(up[x], p[x]->second);
            for (auto& hh : h[x]) {
                auto& [y, w] = hh;
                if (y != p[x]->first)
                    d = f(d, u(dn[y], w));
            }
            rt[x] = g(d, a[x]);
        }
    }

    D operator() (int x) { return rt[x]; }

    void dfs1(int x, int o) {
        D d = e;
        for (auto& hh : h[x]) {
            auto& [y, w] = hh;
            if (y == o) {
                p[x] = &hh;
                continue;
            }
            dfs1(y, x);
            d = f(d, u(dn[y], w));
        }
        dn[x] = g(d, a[x]);
    }

    void dfs2(int x) {
        D d = x ? u(up[x], p[x]->second) : e, t = e;
        int m = h[x].size() - !!x;
        vector<D> pref(m, e);
        int i = 0;
        for (auto& hh : h[x]) {
            auto& [y, w] = hh;
            if (p[x] && p[x]->first == y) continue;
            pref[i++] = t;
            t = f(t, u(dn[y], w));
        }
        for (int j=(int)h[x].size()-1; j>=0; j--) {
            auto& hh = h[x][j];
            auto& [y, w] = hh;
            if (p[x] && p[x]->first == y) continue;
            i--;
            up[y] = g(f(pref[i], d), a[x]);
            d = f(d, u(dn[y], w));
        }
        for (auto& hh : h[x]) {
            auto& [y, w] = hh;
            if (p[x] && p[x]->first == y) continue;
            dfs2(y);
        }
    }
};

struct state {
    ll depth[4], diam;
};

state add_edge(state s, int w) {
    state t;
    t.depth[0] = s.depth[0] + w;
    t.depth[1] = t.depth[2] = t.depth[3] = 0;
    t.diam = max(s.diam, t.depth[0]);

    return t;
}

state add_vertex(state s, int) {
    return s;
}

state add_states(state a, state b) {
    ll d[8];
    copy(a.depth, a.depth+4, d);
    copy(b.depth, b.depth+4, d+4);

    R::sort(d, greater<>{});

    state t;
    copy(d, d+4, t.depth);
    t.diam = max({a.diam, b.diam, a.depth[0] + b.depth[0]});
    return t;
}

ll solve_fast(const vector<tuple<int, int, int>>& e) {
    const int n = ssize(e) + 1;
    vector<int> a(n, 0);

    ll sum = 0, best = 0;
    for (auto [x, y, w] : e) {
        sum += w;
    }

    tree_dp dp(a, e, add_vertex, add_edge, state{0ll, 0ll}, add_states);

    for (int i : ra(1, n)) {
        ll val = dp.p[i]->second * 2ll;
        val += dp.dn[i].diam + dp.up[i].diam;
        best = max(val, best);
    }

    for (int i : ra(0, n)) {
        state st = dp(i);
        best = max(best, accumulate(st.depth, st.depth + 4, 0ll));
    }

    return 2*sum - best;
}

ll solve_brute(const vector<tuple<int, int, int>>& e) {
    const int n = ssize(e) + 1;
    vector<int> p(n);
    iota(begin(p), end(p), 0);

    vector d(n, vector(n, ll(1e18)));
    for (auto [x, y, w] : e) {
        d[x][y] = w;
        d[y][x] = w;
    }

    for (int i : ra(0, n)) {
        d[i][i] = 0;
    }

    for (int i : ra(0, n)) {
        for (int j : ra(0, n)) {
            for (int k : ra(0, n)) {
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }

    ll sol = 1e18;
    do {
        ll sum = 0, hi = 0;
        for (int i : ra(0, n-1)) {
            int u = p[i];
            int v = p[i+1];
            sum += d[u][v];
            hi = max(hi, d[u][v]);
        }

        sol = min(sol, sum - hi);
    } while (R::next_permutation(p).found);

    return sol;
}

struct union_find {
    vector<int> p;
    union_find(int n) : p(n) { iota(begin(p), end(p), 0); }
    bool operator() (int x, int y) { return e(x) == e(y); }
    int e(int x) {
        if (p[x] == x) return x;
        return p[x] = e(p[x]);
    }
    bool join(int x, int y) {
        x = e(x), y = e(y);
        if (x == y) return false;
        p[x] = y;
        return true;
    }
};

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
using uid = uniform_int_distribution<ll>;
using urd = uniform_real_distribution<double>;

void stress() {
    const int n = 8;

    ll ok = 0;
    while (1) {
        union_find uf(n);
        vector<tuple<int, int, int>> e;
        while (ssize(e) != n-1) {
            int x = uid(0, n-1)(eng);
            int y = uid(0, n-1)(eng);
            int w = uid(1, 9)(eng);

            if (uf.join(x, y)) {
                e.push_back({x, y, w});
            }
        }

        ll sf = solve_fast(e);
        ll sb = solve_brute(e);

        if (sf != sb) {
            cerr << sf << ' ' << sb << "\n";
            for (auto [x, y, w] : e) {
                cerr << x << ' ' << y << ' ' << w << '\n';
            }
            return;
        }

        ok++;
        if (ok % 1000 == 0) {
            cerr << ok << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

#ifdef LOCAL
    stress();
#endif

    int n;
    cin >> n;
    
    vector<tuple<int, int, int>> e(n-1);
    for (auto& [x, y, w] : e) {
        cin >> x >> y >> w;
        x--, y--;
    }

    cout << solve_fast(e) << '\n';
#ifdef LOCAL
    cout << solve_brute(e) << '\n';
#endif
}