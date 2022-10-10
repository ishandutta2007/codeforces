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
        ll x;
        cin >> x;
        ll y = 1;
        while (y * 10 <= x) {
            y *= 10;
        }
        cout << x-y << '\n';
    }
    
}