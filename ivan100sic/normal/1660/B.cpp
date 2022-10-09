// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

void prl(bool x) {
    cout << (x ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (ll& x : a) cin >> x;

        R::sort(a);

        if (n == 1) {
            prl(a[0] == 1);
        } else {
            prl(a[n-1] - a[n-2] <= 1);
        }
    }
}