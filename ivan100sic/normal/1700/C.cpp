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
        vector<ll> a(n), b(n);
        for (int i : ra(0, n)) {
            cin >> a[i];
        }
        b[0] = a[0];
        for (int i : ra(1, n)) {
            b[i] = a[i] - a[i-1];
        }

        ll sol = 0;
        for (int i : ra(1, n)) {
            if (b[i] < 0) {
                ll x = -b[i];
                b[i] = 0;
                b[0] -= x;
                sol += x;
            } else if (b[i] > 0) {
                sol += b[i];
                b[i] = 0;
            }
        }

        sol += abs(b[0]);
        cout << sol << '\n';
    }
    
}