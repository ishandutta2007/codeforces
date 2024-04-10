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
        int n, x;
        cin >> n >> x;
        ll z = 0, l = 0;
        for (int i : ra(0, n)) {
            int b;
            cin >> b;
            z += b;
            l += (b + x - 1) / x;
        }

        cout << (z + x - 1) / x << ' ' << l << '\n';
    }
    
}