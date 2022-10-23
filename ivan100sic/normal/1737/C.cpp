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
        int n, r[3], c[3];
        cin >> n;

        int kx[4] = {1, 1, n, n}, ky[4] = {1, n, 1, n}; 
        for (int i : ra(0, 3)) cin >> r[i] >> c[i];

        int x, y;
        string s = "NO\n";
        cin >> x >> y;
        for (int i : ra(0, 3)) {
            if (r[i] % 2 == x % 2 && c[i] % 2 == y % 2) {
                s = "YES\n";

                // Exception
                for (int i : ra(0, 4)) {
                    int dt = 0;
                    for (int j : ra(0, 3)) {
                        dt += abs(r[j] - kx[i]) + abs(c[j] - ky[i]);
                    }

                    if (dt == 2 && x != kx[i] && y != ky[i]) {
                        s = "NO\n";
                    }
                }
            }
        }
        cout << s;
    }
}