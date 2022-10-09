// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
vector<pair<int, int>> e[100005];
vector<pair<int, int>> f[100005];
ll d[2][100005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i : ra(0, m)) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        e[u].emplace_back(v, w);
        f[v].emplace_back(u, w);
    }

    memset(d, 63, sizeof(d));
    d[0][0] = 0;
    set<array<ll, 3>> pq;
    pq.insert({0, 0, 0});

    while (pq.size()) {
        auto [xdist, xcat, x] = *pq.begin();
        pq.erase(pq.begin());

        for (int cat : ra(xcat, 2)) {
            for (auto [y, w] : (cat ? f[x] : e[x])) {
                ll d2 = xdist + w;
                if (d2 < d[cat][y]) {
                    pq.erase({d[cat][y], cat, y});
                    d[cat][y] = d2;
                    pq.insert({d[cat][y], cat, y});
                }
            }
        }
    }

    for (int i : ra(1, n)) {
        ll w = min(d[0][i], d[1][i]);
        if (w > 1e17) w = -1;
        cout << w << " \n"[i == n-1];
    }
}