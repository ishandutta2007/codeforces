// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

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

struct edge {
    int x, y, w;

    bool operator< (const edge& o) const {
        return w < o.w;
    }
};

int n, m;
vector<int> e[200005];
vector<edge> g;
int comp[200005];

void inv_dfs(int x, set<int>& unv) {
    vector<int> to_visit;
    for (auto it = unv.begin(); it != unv.end();) {
        int y = *it;
        auto eit = lower_bound(begin(e[x]), end(e[x]), y);
        if (eit != end(e[x]) && *eit == y) {
            // ima, preskoci
            ++it;
        } else {
            it = unv.erase(it);
            to_visit.push_back(y);
        }
    }

    for (int y : to_visit) {
        comp[y] = comp[x];
        inv_dfs(y, unv);
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    g.resize(m);
    ll xorr = 0;
    for (int i=0; i<m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[i] = {x, y, w};
        xorr ^= w;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    for (int i=1; i<=n; i++) {
        sort(begin(e[i]), end(e[i]));
    }

    set<int> unv;
    for (int i=1; i<=n; i++) unv.insert(i);
    
    int brk = 0;
    while (unv.size()) {
        int x = *unv.begin();
        unv.erase(unv.begin());
        comp[x] = ++brk;        
        inv_dfs(x, unv);
    }

    ll z = 0;
    sort(begin(g), end(g));

    // ako ima redundanse u komplementu, to je to, inace dodaj
    ll ce = n*(n-1ll) / 2 - m;
    if (n - ce == brk) {
        vector<edge> to_test;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<i; j++) {
                auto it = lower_bound(begin(e[i]), end(e[i]), j);
                if (it == end(e[i]) || *it != j) {
                    to_test.push_back({i, j, -1});
                }
            }
        }

        ll sol = 1e18;

        for (auto [x, y, _w] : to_test) {
            union_find uf(n+1);
            ll z = 0;

            for (auto [x1, y1, _w1] : to_test) {
                if (x != x1 || y != y1) {
                    uf.join(x1, y1);
                }
            }

            bool dod = false;
            for (auto [xg, yg, wg] : g) {
                if (!dod && wg >= xorr) {
                    dod = true;
                    if (!uf(x, y)) {
                        uf.join(x, y);
                        z += xorr;
                    }
                }

                if (!uf(xg, yg)) {
                    uf.join(xg, yg);
                    z += wg;
                }
            }

            sol = min(sol, z);
        }

        z = sol;

    } else {
        union_find uf(n+1);
        vector<int> seen(n+1);
        for (int i=1; i<=n; i++) {
            int& j = seen[comp[i]];
            if (j) {
                uf.join(i, j);
            }
            j = i;
        }

        // dodaj redom cc grane
        for (auto [x, y, w] : g) {
            if (!uf(x, y)) {
                uf.join(x, y);
                z += w;
            }
        }
    }

    cout << z << '\n';
}