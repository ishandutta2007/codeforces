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
        int x[6], y[6];
        for (int i : ra(0, 3)) {
            cin >> x[i] >> y[i];
        }
        copy(x, x+3, x+3);
        copy(y, y+3, y+3);

        int sol = 0;
        for (int j : ra(0, 3)) {
            if (y[j] == y[j+1] && y[j+2] < y[j]) {
                sol = abs(x[j+1] - x[j]);
            }
        }

        cout << sol << '\n';
    }
}