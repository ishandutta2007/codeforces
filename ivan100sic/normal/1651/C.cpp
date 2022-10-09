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
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (ll& x : a) cin >> x;
        for (ll& x : b) cin >> x;
    
        ll sol = 1e18;

        auto g = [&](int r, int c) {
            return (r ? b : a)[c];
        };

        array<ll, 16> vals;
        R::fill(vals, 1e18);

        auto dp = vals;
        dp[0] = 0;

        for (int corner : ra(0, 4)) {
            int row = corner / 2;
            int mask = 1 << corner;
            ll base = g(row, corner & 1 ? n-1 : 0);
            for (int i : ra(0, n)) {
                int imask = mask;
                if (i == 0) imask |= 1 << (2*(1-row));
                else if (i == n-1) imask |= 1 << (2*(1-row) + 1);

                vals[imask] = min(vals[imask], abs(base - g(1-row, i)));
            }
        }

        for (int i : ra(0, 16)) {
            auto nu = dp;
            for (int j : ra(0, 16)) {
                nu[i|j] = min(nu[i|j], dp[i] + vals[j]);
            }
            swap(nu, dp);
        }

        cout << dp[15] << '\n';
    }
}