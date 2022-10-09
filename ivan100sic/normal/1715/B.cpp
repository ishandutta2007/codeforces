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
        ll n, k, b, s;
        cin >> n >> k >> b >> s;

        ll slo = b*k;
        ll shi = slo + n*(k-1);

        if (s < slo || s > shi) {
            cout << "-1\n";
            continue;
        }

        for (int i : ra(0, n)) {
            ll rm = min(k-1, s-slo);
            ll qt = i == 0 ? b : 0;
            cout << k*qt + rm << " \n"[i == n-1];
            s -= rm;
        }
    }
}