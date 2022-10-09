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
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for (auto& x : a) cin >> x, x--;
        R::sort(a);

        vector<ll> z(n+1);
        for (int i : ra(0, n)) z[i+1] = z[i] + a[i];

        ll passed = 0, sol = 0;
        for (int i=n; i>=1; i--) {
            // z[i] + (passed + d) * i <= x
            ll d = (x - z[i]) / i - passed;
            d = max(d, 0ll);
            passed += d;
            sol += i*d;
        }

        cout << sol << '\n';
    }
    
}