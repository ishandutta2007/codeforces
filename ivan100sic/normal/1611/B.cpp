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
        ll x, y, z;
        cin >> x >> y;
        if (3*x <= y) {
            z = x;
        } else if (3*y <= x) {
            z = y;
        } else {
            z = (x+y) / 4;
        }

        cout << z << '\n';
    }
    
}