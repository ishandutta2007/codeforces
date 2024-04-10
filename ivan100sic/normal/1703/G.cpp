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
        int n, k;
        cin >> n >> k;

        vector a(n, 0);
        for (int i : ra(0, n)) {
            cin >> a[i];
        }

        ll sumgood = 0, sol = -1e18;
        for (int g : ra(0, n+1)) {
            ll sumbad = 0, quot = 1;
            for (int j : ra(g, n)) {
                quot <<= 1;
                ll q = a[j] / quot;
                if (quot > 1e10) break;
                sumbad += q;
            }
            sol = max(sol, sumgood + sumbad - 1ll*k*g);
            if (g < n) sumgood += a[g];
        }

        cout << sol << '\n';
    }
    
}