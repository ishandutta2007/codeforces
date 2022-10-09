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
    bool black_here;
    bool black_right_below;
    bool black_anywhere_below;
    bool near_black_seen;
    int num_blacks_seen;
    bool good;
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;
    vector<char> c(n);
    for (auto& x : c) {
        int y;
        cin >> y;
        x = y;
    }

    vector<tuple<int, int, int>> e(n-1);
    for (auto& [x, y, z] : e) {
        cin >> x >> y;
        x--, y--;
        z = 0;
    }

    auto g = [&](state s, char r) -> state {
        return {
            (bool)r,
            s.black_right_below,
            s.black_anywhere_below,
            false,
            0,
            s.good || (s.black_anywhere_below && r) || (s.num_blacks_seen >= 2 && s.near_black_seen)
        };
    };

    auto u = [&](state s, int _) -> state {
        return {
            false,
            s.black_here,
            s.black_anywhere_below || s.black_here,
            s.black_here,
            s.black_anywhere_below || s.black_here,
            s.good
        };
    };

    state neut = {
        false,
        false,
        false,
        false,
        0,
        false
    };

    auto add = [&](state a, state b) -> state {
        return {
            false,
            a.black_right_below || b.black_right_below,
            a.black_anywhere_below || b.black_anywhere_below,
            a.near_black_seen || b.near_black_seen,
            a.num_blacks_seen + b.num_blacks_seen,
            a.good || b.good
        };
    };

    tree_dp dp(c, e, g, u, neut, add);
    for (int i : ra(0, n)) {
        cout << (int)(dp(i).good || c[i]) << ' ';
    }
    cout << "\n";
}