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
        string a[8];
        for (auto& s : a) cin >> s;

        char sol = 0;
        for (int i : ra(0, 8)) {
            if (R::count(a[i], 'R') == 8) {
                sol = 'R';
            }

            int b = 0;
            for (int j : ra(0, 8)) {
                b += a[j][i] == 'B';
            }

            if (b == 8) {
                sol = 'B';
            }
        }

        cout << sol << '\n';
    }
}