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
        ll x, y;
        cin >> x >> y;
        if (x < y) {
            ll q = y/x*x;
            cout << (q+y)/2 << '\n';
        } else if (x > y) {
            cout << x+y << '\n';
        } else {
            cout << x << '\n';
        }
    }
    
}