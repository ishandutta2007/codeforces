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
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;

        // above?
        if ((sx-d > 1 && sy+d < m) || (sx+d < n && sy-d > 1)) {
            cout << n+m-2 << '\n';
        } else {
            cout << "-1\n";
        }
    }
}