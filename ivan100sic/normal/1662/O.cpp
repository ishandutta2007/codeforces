// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

char a[44][720];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));

        int n;
        cin >> n;
        for (int i : ra(0, n)) {
            char tp;
            int u, v, w;
            cin >> tp >> u >> v >> w;

            if (tp == 'C') {
                for (int i=2*v; i!=2*w; i=(i+1) % 720) {
                    a[2*u][i] = 1;
                }
                a[2*u][2*w] = 1;
            } else {
                for (int i=2*u; i<=2*v; i++) {
                    a[i][2*w] = 1;
                }
            }
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        while (q.size()) {
            auto go = [&](int x2, int y2) {
                if (x2 > 42 || x2 < 0) return;
                if (a[x2][y2] != 0) return;
                a[x2][y2] = 2;
                q.push({x2, y2});
            };

            auto [x, y] = q.front(); q.pop();

            go(x, (y+721) % 720);
            go(x, (y+719) % 720);
            go(x-1, y);
            go(x+1, y);
        }

        cout << (a[42][0] == 2 ? "YES\n" : "NO\n");
    }
}