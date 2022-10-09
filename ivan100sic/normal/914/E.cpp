// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

constexpr auto make_pals() {
    array<int, 21> a{};
    a[0] = 0;
    for (int i=0; i<20; i++) {
        a[i+1] = 1 << i;
    }
    return a;
}

constexpr auto pals = make_pals();

namespace fast_map {
    vector<int> a;
    int b[1 << 20];

    void add(int x, int w = 1) {
        a.push_back(x);
        b[x] += w;
    }

    int get(int x) {
        return b[x];
    }

    void reset() {
        for (int x : a) b[x] = 0;
        a = {};
    }
}

struct lazy_vals {
    vector<ll> a, b;
    vector<int> c;

    lazy_vals(int n) : a(n), b(n) {}

    void add(int x, ll y) {
        c.emplace_back(x);
        b[x] += y;
    }

    ll get(int x) {
        return b[x];
    }

    ll get_final(int x) {
        return a[x];
    }

    void commit() {
        for (auto x : c) {
            a[x] += b[x];
            b[x] = 0;
        }
        c = {};
    }
};

struct centroid_decomposition {
    vector<vector<int>> e;
    string b;
    vector<int> s;

    // added data
    string w;
    vector<ll> sol;
    lazy_vals lv;

    centroid_decomposition(const vector<pair<int, int>>& g, const string& w) : lv(g.size() + 1) {
        int n = g.size() + 1;
        e.resize(n);
        s.resize(n);
        b = string(n, 0);

        this->w = w;
        sol.resize(n);

        for (auto l : g) {
            int x, y;
            tie(x, y) = l;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        solve(0);
    }

    void dfs_size(int x, int p) {
        s[x] = 1;
        for (int y : e[x]) {
            if (y == p || b[y]) continue;
            dfs_size(y, x);
            s[x] += s[y];
        }
    }

    void dfs_centroid(int x, int p, int w, int& c) {
        bool ok = 1;
        for (int y : e[x]) {
            if (y == p || b[y]) continue;
            dfs_centroid(y, x, w, c);
            if (2*s[y] > w) ok = false;
        }
        if (x != p && 2*(w-s[x]) > w) ok = false;
        if (ok) c = x;
    }

    void solve(int x) {
        dfs_size(x, x);
        int c = x;
        dfs_centroid(x, x, s[x], c);
        b[c] = 1;

        const int val_root = 1 << (w[c] - 'a');

        // Prepare for dfs
        fast_map::reset();
        vector<vector<pair<int, int>>> vv;

        for (int y : e[c]) {
            if (b[y]) continue;

            // Gather subtree info
            vector<pair<int, int>> vals;
            dfs1(y, c, vals, 0);

            // Process info
            for (auto [x, i] : vals) {
                fast_map::add(x);
            }

            vv.emplace_back(move(vals));
        }

        for (auto& v : vv) {
            // tmp remove
            for (auto [x, i] : v) {
                fast_map::add(x, -1);
            }

            // detect
            for (auto [x, i] : v) {
                int c = 0;
                for (int pal : pals) {
                    c += fast_map::get(pal ^ val_root ^ x);
                }
                lv.add(i, c);
            }

            // tmp add back
            for (auto [x, i] : v) {
                fast_map::add(x, 1);
            }
        }

        // Propagate up
        for (int y : e[c]) {
            if (b[y]) continue;
            dfs2(y, c);
            lv.add(c, lv.get(y));
        }

        lv.add(c, -lv.get(c) / 2);
        lv.commit();

        // Root only
        ll rootc = 0;
        for (auto& v : vv) {
            // detect
            for (auto [x, i] : v) {
                int c = 0;
                for (int pal : pals) {
                    if ((pal ^ val_root ^ x) == 0) {
                        c++;
                        rootc++;
                    }
                }
                lv.add(i, c);
            }
        }

        // Propagate up
        for (int y : e[c]) {
            if (b[y]) continue;
            dfs2(y, c);
        }

        lv.add(c, rootc);
        lv.commit();

        for (int y : e[c]) {
            if (!b[y]) solve(y);
        }
    }

    void dfs1(int x, int p, vector<pair<int, int>>& vals, int acc) {
        // Enter node
        acc ^= 1 << (w[x] - 'a');
        vals.emplace_back(acc, x);
        for (int y : e[x]) {
            if (b[y] || y == p) continue;
            // Process and recurse
            dfs1(y, x, vals, acc); 
        }
    }

    void dfs2(int x, int p) {
        // Enter node
        for (int y : e[x]) {
            if (b[y] || y == p) continue;
            // Process and recurse
            dfs2(y, x);
            lv.add(x, lv.get(y));
        }
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;
    vector<pair<int, int>> g(n-1);
    for (int i : ra(0, n-1)) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[i] = {x, y};
    }
    string w;
    cin >> w;

    centroid_decomposition cd(g, w);
    for (int i : ra(0, n)) {
        cout << cd.lv.get_final(i) + 1 << ' ';
    }
    cout << '\n';
}