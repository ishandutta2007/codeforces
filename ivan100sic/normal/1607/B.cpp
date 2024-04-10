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
        ll x, n, d = 0;
        cin >> x >> n;

        switch (n % 4) {
            case 0: d = 0; break;
            case 1: d = -n; break;
            case 2: d = 1; break;
            case 3: d = n+1; break;
        }

        if (x % 2) {
            d = -d;
        }

        cout << x + d << '\n';
    }
}