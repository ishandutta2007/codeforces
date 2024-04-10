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

    // Screw it
    for (int _t : ra(0, t)) {
        int n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for (int i : ra(0, n)) {
            cin >> a[i];
        }

        ll z = 0, bz = 1e18;

        vector<ll> lz(n+1), hz(n+1);

        for (int i : ra(1, n)) {
            ll d = abs(a[i] - a[i-1]);
            z += d;
            lz[i] = abs(1-a[i]) + abs(1-a[i-1]) - d;
            hz[i] = abs(x-a[i]) + abs(x-a[i-1]) - d;
            bz = min(bz, abs(a[i-1]-1) + abs(1-x) + abs(x-a[i]) - d);
            bz = min(bz, abs(a[i-1]-x) + abs(x-1) + abs(1-a[i]) - d);
        }

        lz[0] = abs(a[0]-1);
        lz[n] = abs(a[n-1]-1);

        hz[0] = abs(a[0]-x);
        hz[n] = abs(a[n-1]-x);

        bz = min(bz, abs(a[0]-1) + abs(1-x));
        bz = min(bz, abs(a[0]-x) + abs(x-1));
        bz = min(bz, abs(a[n-1]-1) + abs(1-x));
        bz = min(bz, abs(a[n-1]-x) + abs(x-1));

        ll qz = 1e18, sz = 1e18;
        for (int i : ra(0, n+1)) {
            sz = min(sz, qz + hz[i]);
            qz = min(qz, lz[i]);
        }

        qz = 1e18;
        for (int i : ra(0, n+1)) {
            sz = min(sz, qz + lz[i]);
            qz = min(qz, hz[i]);
        }

        if (x == 1) {
            sz = *R::min_element(lz);
        }

        ll sol = z + min(sz, bz);
        cout << sol << '\n';
    }
}