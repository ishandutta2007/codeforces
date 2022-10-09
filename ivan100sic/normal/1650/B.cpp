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
        ll l, r, a;
        cin >> l >> r >> a;
        
        ll z = r/a + r%a;
        ll x = r/a*a-1;
        if (x >= l) {
            z = max(z, x/a + x%a);
        }
        cout << z << '\n';
    }
}