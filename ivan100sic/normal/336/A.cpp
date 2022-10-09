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

    ll x, y;
    cin >> x >> y;

    ll w = abs(x) + abs(y);
    if (x > 0 && y > 0) {
        cout << "0 " << w << ' ' << w << " 0\n";
    } else if (x < 0 && y > 0) {
        cout << -w << " 0 0 " << w << '\n';
    } else if (x > 0 && y < 0) {
        cout << "0 " << -w << ' ' << w << " 0\n";
    } else {
        cout << -w << " 0 0 " << -w << '\n';
    }
}