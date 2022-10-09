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

struct val {
    ll p, c;
};

val v_ex(val v, char) {
    return {v.p + v.c + 1, v.c + 1};
}

val e_ex(val v, char) {
    return v;
}

const val neut = {0, 0};

val d_add(val a, val b) {
    return {a.p + b.p, a.c + b.c};
}

ll the_dp(auto a, int n) {
    map<int, int> freq;
    for (int x : a) {
        freq[x]++;
    }

    vector<int> d(n/2 + 2, 0);
    d[0] = 1;
    for (auto [k, v] : freq) {
        for (int i=n/2+1 - k*(v+1); i>=0; i--) {
            d[i + k*(v+1)] -= d[i];
        }

        for (int i=k; i<n/2+2; i++) d[i] += d[i-k];
        for (int& x : d) x = !!x;
    }

    for (int i=n/2; i>=0; i--) {
        if (d[i]) {
            cerr << "found " << i << '\n';
            return (i+1ll) * (n-i);
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;
    vector<char> a(n);
    vector<tuple<int, int, char>> b(n-1);
    vector<vector<int>> e(n);
    vector<int> parent(n, -1);

    for (int i : ra(1, n)) {
        int p;
        cin >> p;
        p--;
        b[i-1] = {i, p, 0};
        parent[i] = p;
        e[i].push_back(p);
        e[p].push_back(i);
    }

    tree_dp eng(a, b, v_ex, e_ex, neut, d_add);
    ll sol = 0;

    for (int i : ra(1, n)) {
        vector<val> d;
        for (int j : e[i]) {
            if (parent[j] == i) {
                d.emplace_back(eng.dn[j]);
            } else {
                d.emplace_back(eng.up[i]);
            }
        }

        auto it = R::find_if(d, [&](val v) { return 2 * v.c >= n; });
        if (it != d.end()) {
            // No need to do dp
            ll tot = 0;
            for (val v : d) tot += v.p;
            tot += (it->c + 1) * (n - it->c);
            sol = max(sol, tot);
        } else {
            // Dp needed (Done at most twice)
            ll tot = 0;
            for (val v : d) tot += v.p;
            tot += the_dp(R::transform_view(d, [](val v) { return v.c; }), n);
            sol = max(sol, tot);
        }
    }

    cout << sol << '\n';
}