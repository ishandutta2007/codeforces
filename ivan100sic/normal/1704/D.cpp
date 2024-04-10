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
        int n, m;
        cin >> n >> m;

        vector<ll> b(n);
        for (int i : ra(0, n)) {
            ll& z = b[i];
            for (int j : ra(0, m)) {
                ll x;
                cin >> x;
                z += j*x;
            }
        }

        vector c(begin(b), begin(b) + 3);
        R::sort(c);
        ll val = c[1];

        for (int i : ra(0, n)) {
            if (b[i] != val) {
                cout << i+1 << ' ' << b[i]-val << '\n';
            }
        }
    }
}