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
        int x;
        cin >> x;
        if (x % 7 == 0) {
            cout << x << '\n';
            continue;
        }

        for (int y=1; y<=7; y++) {
            int z = x / 10 * 10 + y;
            if (z % 7 == 0) {
                cout << z << '\n';
                break;
            }
        }
    }
}