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
        ll t, x, y;
        cin >> t >> x >> y;

        t -= x + y;
        if (t < 0) {
            cout << "NO\n";
            continue;
        }
        
        static ll a[121][121];

        memset(a, 0, sizeof(a));
        a[0][0] = t;

        for (int i : ra(0, 120)) {
            for (int j : ra(0, 120)) {
                ll x = a[i][j];
                a[i+1][j] += x >> 1;
                a[i][j+1] += x - (x >> 1);
            }
        }

        int u = 0, v = 0;
        for (int i : ra(0, x+y)) {
            (a[u][v] % 2 ? u : v)++;
            if (max(u, v) == 120) break;
        }

        cout << (tie(u, v) == tie(x, y) ? "YES\n" : "NO\n");
    }
}