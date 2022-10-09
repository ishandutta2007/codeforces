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
        vector<array<int, 3>> e(n-1);
        vector<vector<array<int, 2>>> g(n);
        for (int i : ra(0, n-1)) {
            int x, y, w;
            cin >> x >> y >> w;
            x--, y--;
            e[i] = {x, y, w};
            if (w != -1) {
                int p = popcount((unsigned)w) % 2;
                g[x].push_back({y, p});
                g[y].push_back({x, p});
            }
        }
        for (int i : ra(0, m)) {
            int x, y, p;
            cin >> x >> y >> p;
            x--, y--;
            g[x].push_back({y, p});
            g[y].push_back({x, p});
        }

        bool ok = 1;
        vector<int> col(n, -1);
        for (int x0 : ra(0, n)) {
            if (col[x0] != -1) continue;
            queue<int> q;
            q.push(x0);
            col[x0] = 0;
            while (q.size()) {
                int x = q.front(); q.pop();
                for (auto [y, p] : g[x]) {
                    if (col[y] == -1) {
                        col[y] = col[x] ^ p;
                        q.push(y); 
                    } else if (col[y] != (col[x] ^ p)) {
                        ok = false;
                    }
                }
            }
        }

        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (auto [x, y, w] : e) {
                cout << x+1 << ' ' << y+1 << ' ';
                if (w == -1) w = col[x] ^ col[y];
                cout << w << '\n';
            }
        }
    }
    
}