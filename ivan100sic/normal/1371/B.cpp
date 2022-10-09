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
        ll n, r;
        cin >> n >> r;

        // 1 <= x <= r
        // x >= n, one way only, always
        // x < n, x ways

        ll c = clamp(r-n+1, 0ll, 1ll);
        
        ll k = min(n-1, r);
        c += k*(k+1) / 2;

        cout << c << '\n';
    }
}