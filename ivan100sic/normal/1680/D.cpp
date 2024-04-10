// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll n, k;
ll a[3005];

ll z0[3005], zs[3005];

ll solve() {
    ll w = -2;
    for (int i : ra(0, n)) {
        z0[i+1] = z0[i] + (a[i] == 0);
        zs[i+1] = zs[i] + a[i];
    }

    for (int l : ra(0, n+1)) {
        for (int r : ra(l, n+1)) {
            ll sum_lo = zs[l] + (zs[n] - zs[r]);
            ll sum_hi = zs[r] - zs[l];

            ll c_lo = z0[l] + (z0[n] - z0[r]);
            ll c_hi = z0[r] - z0[l];

            // sum_lo + sum_hi + x_lo + x_hi = 0
            // |x_lo| <= k c_lo
            // |x_hi| <= k c_hi

            if (abs(sum_lo + sum_hi) > k*(c_lo + c_hi)) {
                continue;
            }

            // either x_lo or x_hi is maxed out
            ll x_hi = k*c_hi;
            ll x_lo = -(sum_lo + sum_hi + x_hi);

            if (abs(x_lo) <= k*c_lo) {
                w = max(w, sum_hi + x_hi);
            }

            x_lo = -k*c_lo;
            x_hi = -(sum_lo + sum_hi + x_lo);

            if (abs(x_hi) <= k*c_hi) {
                w = max(w, sum_hi + x_hi);
            }
        }
    }

    return w;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> k;
    for (int i : ra(0, n)) {
        cin >> a[i];
    }

    ll w = solve();
    reverse(a, a+n);
    for (int i : ra(0, n)) {
        a[i] *= -1;
    }
    w = max(w, solve());

    cout << w+1 << '\n';
}