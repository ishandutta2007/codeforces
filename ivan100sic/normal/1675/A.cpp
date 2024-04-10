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
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;

        x -= min(x, a);
        y -= min(y, b);

        if (x + y <= c) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
}