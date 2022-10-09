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
        int lx = 0, ly = 0, rx = 0, ry = 0;
        while (n--) {
            int x, y;
            cin >> x >> y;
            lx = min(lx, x);
            ly = min(ly, y);
            rx = max(rx, x);
            ry = max(ry, y);

        }
        cout << 2*(rx+ry-lx-ly) << '\n';
    }
}