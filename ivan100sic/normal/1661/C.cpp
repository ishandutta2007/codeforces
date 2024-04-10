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

        R::sort(a, greater<int>{});

        ll sol = 1e18;
        for (ll target : {a[0], a[0] + 1, a[0] + 2}) {
            ll z = 0, odd = 0;
            for (int x : a) {
                z += target - x;
                if ((target - x) % 2) {
                    odd++;
                }
            }

            sol = min(sol, max(2*odd-1, z/3*2 + z%3));
        }

        cout << sol << '\n';
    }
}