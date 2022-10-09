// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
int u[305], v[305], w[305];

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

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--;
    }

    vector<int> g = {-1, (int)1e9};
    for (int i=0; i<m; i++) {
        g.push_back(w[i]);
        for (int j=i+1; j<m; j++) {
            int s = w[i] + w[j];
            if (s % 2 == 0) {
                g.push_back(s/2);
            } else {
                g.push_back(s/2);
                g.push_back(s/2 + 1);
            }
        }
    }

    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());

    vector<ll> mst(g.size());
    vector<int> idx(m);
    iota(begin(idx), end(idx), 0);

    for (int i : ra(0, ssize(g))) {
        R::sort(idx, {}, [&](int id) { return abs(w[id] - g[i]); });
        union_find uf(n);
        int c = 0;
        ll cost = 0;
        for (int j : idx) {
            if (uf.join(u[j], v[j])) {
                c++;
                cost += abs(w[j] - g[i]);
                if (c == n-1) {
                    break;
                }
            }
        }
        mst[i] = cost;
    }

    ll sol = 0;
    
    auto answer = [&](int q) {
        auto l = R::lower_bound(g, q) - begin(g);
        if (g[l] == q) {
            sol ^= mst[l];
        } else {
            ll y1 = mst[l-1], y2 = mst[l];
            ll x1 = g[l-1], x2 = g[l];

            ll y = (q*y1 - x2*y1 - q*y2 + x1*y2)/(x1 - x2);
            sol ^= y;
        }
    };

    {
        // queries
        int p, k, a, b, c;
        cin >> p >> k >> a >> b >> c;

        int last = 0;
        for (int i=0; i<p; i++) {
            cin >> last;
            answer(last);
        }

        for (int i=0; i<k-p; i++) {
            last = (last * 1ll * a + b) % c;
            answer(last);
        }
    }

    cout << sol << '\n';
}