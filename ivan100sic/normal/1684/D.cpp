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
        vector<int> a(n), w(n);
        for (int& x : a) cin >> x;

        for (int i : ra(0, n)) {
            w[i] = n-1-i-a[i];
        }
        R::sort(w);
        vector<ll> wz(n+1);
        for (int i : ra(0, n)) {
            wz[i+1] = wz[i] + w[i];
        }
        ll sum = accumulate(begin(a), end(a), 0ll);
        ll sol = sum;
        for (int l : ra(0, k+1)) {
            sol = min(sol, sum + wz[l] - l*(l-1ll)/2);
        }
        cout << sol << '\n';
    }
}