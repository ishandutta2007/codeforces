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
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        x--, y--;
        vector<string> a(n);
        for (auto& s : a) cin >> s;

        int z = 3;
        for (int i : ra(0, n)) {
            for (int j : ra(0, m)) {
                if (a[i][j] == 'B') {
                    z = min(z, 2);
                    if (i == x || j == y)
                        z = min(z, 1);
                    if (i == x && j == y)
                        z = min(z, 0);
                }
            }
        }
        if (z == 3) z = -1;
        cout << z << '\n';
    }
}