// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

void ans(bool x) {
    if (x) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;

        vector<ll> a(k);
        for (int i : ra(0, k)) {
            cin >> a[i];
        }

        R::sort(a, greater<>{});
        
        auto can = [&](ll n, ll m) {
            ll q = 0;
            bool odd = 0;
            for (ll x : a) {
                if (x >= 2*n) {
                    q += x/n;
                }

                if (x >= 3*n) {
                    odd = 1;
                }
            }

            return q >= m && (odd == 1 || m % 2 == 0);
        };

        ans(can(n, m) || can(m, n));
    }
}