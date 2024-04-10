// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll pw(ll x, int y) {
    if (y == 0) return 1;
    ll z = pw(x, y>>1);
    z *= z;
    if (y & 1) z *= x;
    return z;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        k++;
        ll x = 0;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        for (int i=0; i<n-1; i++) {
            ll d = min(k, pw(10ll, a[i+1] - a[i]) - 1);
            x += pw(10, a[i]) * d;
            k -= d;
        }

        x += pw(10, a[n-1]) * k;

        cout << x << '\n';
    }
    
}