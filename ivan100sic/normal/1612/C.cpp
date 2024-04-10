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
        ll k, x;
        cin >> k >> x;
        ll y = *R::lower_bound(ra(1ll, 2*k-1), true, {}, [&](ll m) {
            if (m <= k) {
                return m*(m+1) / 2 >= x;
            } else {
                ll w = 2*k-1-m;
                return k*k - w*(w+1) / 2 >= x;
            }
        });

        cout << y << '\n';
    }
    
}