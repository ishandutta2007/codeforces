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
        ll n, l, r, k;
        cin >> n >> l >> r >> k;
        vector<ll> a;
        for (int i=0; i<n; i++) {
            ll x;
            cin >> x;
            if (clamp(x, l, r) == x) {
                a.push_back(x);
            }
        }

        R::sort(a);
        ll tot = 0, sol = 0;
        for (ll x : a) {
            if (x + tot <= k) {
                tot += x;
                sol += 1;
            }
        }

        cout << sol << '\n';
    }
    
}