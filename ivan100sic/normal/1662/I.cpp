// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const ll G = 1600;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    ll n, m, sol = 0;
    cin >> n >> m;

    vector<ll> a(n), b(m), z(n+1);
    for (ll& x : a) cin >> x;
    for (ll& x : b) cin >> x;

    R::sort(b);
    for (ll& x : b) x *= 16;
    for (int i : ra(0, n)) {
        z[i+1] = z[i] + a[i];
    }

    auto hutd = [&](ll i) {
        ll p = i * G;
        auto it = R::lower_bound(b, p);

        ll d = 1e18;
        if (it != b.end()) d = min(d, abs(*it - p));
        if (it != b.begin()) d = min(d, abs(*prev(it) - p));

        return d;
    };

    for (int l : ra(0, n)) {
        // find distance to closest from l
        ll d = hutd(l);

        // put your stand d-1 to the right of him
        ll my = l * G + d-1;

        auto first_bad = *R::lower_bound(ra(l, n), true, {}, [&](int r) {
            // Fail?
            if (r == n) return true;

            ll old = hutd(r);
            ll nu = abs(r * G - my);

            return !(nu < old);
        });

        sol = max(sol, z[first_bad] - z[l]);
    }

    cout << sol << '\n';
}