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
        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<ll> b(n+1);
        b[0] = a[0];
        for (int i : ra(1, n)) {
            b[i] = lcm<ll>(a[i-1], a[i]);
        }
        b[n] = a[n-1];

        bool ok = 1;
        for (int i : ra(0, n)) if (a[i] != gcd(b[i], b[i+1])) ok = 0;

        cout << (!ok ? "NO\n" : "YES\n");
    }
}