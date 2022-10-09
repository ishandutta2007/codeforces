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
        if (n <= 19) {
            cout << "YES\n";
            ll x = 1;
            for (ll i : ra(0ll, n)) {
                cout << x << ' ';
                x *= 3;
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}