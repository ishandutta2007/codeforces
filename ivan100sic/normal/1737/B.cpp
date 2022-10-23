// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll cnt(ll x) {
    if (x <= 10) {
        return R::count_if(array{1, 2, 3, 4, 6, 8, 9}, [&](int t) { return t <= x; });
    }

    auto rg = ra(1ll, ll(2e9));
    ll c1 = R::partition_point(rg, [&](ll t) { return t*t <= x; })
        - begin(rg);

    ll c2 = R::partition_point(rg, [&](ll t) { return t*(t+1) <= x; })
        - begin(rg);

    ll c3 = R::partition_point(rg, [&](ll t) { return t*(t+2) <= x; })
        - begin(rg);

    return c1 + c2 + c3;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;

        cout << cnt(r) - cnt(l-1) << '\n';
    }
}