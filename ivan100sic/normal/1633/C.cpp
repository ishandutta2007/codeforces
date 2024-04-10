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
        ll hc0, dc0, hm, dm, k, w, a;
        cin >> hc0 >> dc0 >> hm >> dm >> k >> w >> a;

        string ans = "NO\n";
        for (ll i=0; i<=k; i++) {
            ll hc = hc0 + i*a;
            ll dc = dc0 + (k-i)*w;

            ll cm = (hm + dc - 1) / dc;
            ll mc = (hc + dm - 1) / dm;

            if (cm <= mc) {
                ans = "YES\n";
            }
        }

        cout << ans;
    }
}