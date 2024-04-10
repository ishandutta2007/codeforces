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
        int n, x, y;
        cin >> n >> x >> y;
        if (x > y) swap(x, y);
        if (x > 0 || (y == 0 || (n-1) % y != 0)) {
            cout << "-1\n";
            continue;
        }

        for (int i : ra(0, n-1)) {
            cout << i/y*y + 2 << " \n"[i == n-2];
        }
    }
}