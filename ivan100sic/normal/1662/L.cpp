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

    ll n, v;
    cin >> n >> v;

    vector<ll> a(n), b(n);
    vector<pair<ll, ll>> u;
    for (ll& x : a) cin >> x;
    for (ll& x : b) cin >> x;
    
    for (int i : ra(0, n)) {
        ll p = a[i] * v;
        ll q = b[i];

        ll x = q + p;
        ll y = p - q;

        if (x >= 0 && y >= 0) {
            u.emplace_back(x, y);
        }
    }

    R::sort(u);

    vector<ll> d;
    for (auto [x, y] : u) {
        auto it = R::upper_bound(d, y);
        if (it == d.end()) {
            d.push_back(y);
        } else {
            *it = y;
        }
    }

    cout << d.size() << '\n';
}