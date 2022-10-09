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
        ll n;
        cin >> n;
        for (ll x=2;; x++) {
            if (gcd(n-1-x, x) == 1) {
                cout << n-1-x << ' ' << x << " 1\n";
                break;
            }
        }
    }
}