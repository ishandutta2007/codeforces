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
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> a(n+1);
        for (int i : ra(1, n+1)) cin >> a[i];

        // cost to conquer all cities to the right, with capital in i
        vector<ll> sp(n+1);
        for (int i=n-1; i>=0; i--) {
            sp[i] = sp[i+1] + (n-i)*ll(a[i+1] - a[i]);
        }

        ll sol = 8e18;
        for (int i : ra(0, n)) {
            sol = min(sol, a[i] * ll(x+y) + sp[i]*1ll*y);
        }

        cout << sol << '\n';
    }
}