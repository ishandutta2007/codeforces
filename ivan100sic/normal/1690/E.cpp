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
        int n, k;
        cin >> n >> k;
        ll sol = 0;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
            sol += x / k;
            x %= k;
        }

        R::sort(a);

        int l = 0, r = n/2, o = 0;
        while (l <= r) {
            int m = (l+r) / 2;
            bool ok = 1;
            for (int i = 0; i < m; i++) {
                if (a[n-1-i] + a[n-2*m+i] < k) {
                    ok = 0;
                }
            }
            if (ok) {
                o = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        cout << o + sol << '\n';
    }
}