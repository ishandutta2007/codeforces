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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll& x : a) cin >> x;

        ll sum = accumulate(begin(a), end(a), 0ll);
        vector<ll> b(n);
        bool ok = 1;
        ll q = n*(n+1) / 2, r = q * n;
        for (int i : ra(0, n)) {
            b[i] = sum + q * (a[(i+n-1)%n] - a[i]);
            if (b[i] % r || b[i] <= 0) {
                ok = 0;
            } else {
                b[i] /= r;
            }
        }
        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (ll x : b) cout << x << ' ';
            cout << '\n';
        }
    }
    
}