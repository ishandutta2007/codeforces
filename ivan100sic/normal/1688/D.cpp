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
        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<ll> z(n+1);
        for (int i : ra(0, n)) z[i+1] = z[i] + a[i];

        int l = min(k, n);
        ll sol = 0;
        for (int i=0; i+l<=n; i++) {
            sol = max(sol, z[i+l] - z[i] + 1ll*k*l - l*(l+1ll)/2);
        }

        cout << sol << '\n';
    }
    
}