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
        ll d;
        cin >> d;

        cout << *R::lower_bound(ra(0ll, 123123123ll), true, {}, [&](ll g) {
            ll a = g/3;
            ll b = 2*g/3 - a;
            ll c = g - a - b;

            return 2*(a*b+b*c+c*a) >= d;
        }) << '\n';
    }
}