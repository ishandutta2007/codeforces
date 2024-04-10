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
        ll n, h;
        cin >> n >> h;
        vector<ll> a(n);
        for (ll& x : a) cin >> x;

        cout << *R::lower_bound(ra(0ll, ll(2e18)), true, {}, [&](ll m) {
            ll dmg = 0, last = a[0];
            for (ll i : ra(0ll, n)) {
                ll nx = i == n-1 ? ll(2e18) : a[i+1];
                dmg += min(nx - a[i], m);
            }
            
            return dmg >= h;
        }) << '\n';
    }
    
}