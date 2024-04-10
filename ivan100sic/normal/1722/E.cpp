// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll a[1005][1005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        
        int n, q;
        cin >> n >> q;
        
        for (int i : ra(0, n)) {
            int x, y;
            cin >> x >> y;
            a[x][y] += x*y;
        }

        for (int i : ra(1, 1001)) {
            for (int j : ra(1, 1001)) {
                a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            }
        }

        for (int i : ra(0, q)) {
            int xl, yl, xr, yr;
            cin >> xl >> yl >> xr >> yr;

            xr--, yr--;

            cout << a[xr][yr] + a[xl][yl] - a[xl][yr] - a[xr][yl] << '\n';
        }
    }
}