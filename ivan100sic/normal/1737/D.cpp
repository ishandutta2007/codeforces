// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<array<int, 3>> g(m);
        vector d(n, vector(n, n));

        for (int i : ra(0, m)) {
            int x, y, w;
            cin >> x >> y >> w;
            x--, y--;
            g[i] = {x, y, w};
            d[x][y] = min(d[x][y], 1);
            d[y][x] = min(d[y][x], 1);
        }

        for (int i : ra(0, n)) d[i][i] = 0;

        for (int i : ra(0, n)) {
            for (int j : ra(0, n)) {
                for (int k : ra(0, n)) {
                    d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
                }
            }
        }

        ll sol = 1e18;
        for (auto [x, y, w] : g) {
            for (int z : ra(0, n)) {
                // bifurcation point
                sol = min(sol, (d[z][0] + d[z][n-1] + min(d[x][z], d[y][z]) + 2ll) * w);
                
                // To each his own
                for (auto [p, q] : array{pair{x, y}, pair{y, x}}) {
                    sol = min(sol, (d[p][0] + d[q][n-1] + 1ll) * w);
                }
            }
        }

        cout << sol << "\n";
    }
}