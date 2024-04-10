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
        int n;
        cin >> n;
        ll d[2] = {0, 0};
        vector<ll> a(n);
        for (ll& x : a) cin >> x;

        for (int i : ra(0, n)) {
            d[i%2] = gcd(d[i%2], a[i]);
        }

        ll ans = 0;
        for (int i : {0, 1}) {
            bool ok = 1;
            for (int j=1-i; j<n; j+=2) {
                if (a[j] % d[i] == 0) {
                    ok = 0;
                }
            }
            if (ok) {
                ans = d[i];
            }
        }

        cout << ans << '\n';
    }
    
}