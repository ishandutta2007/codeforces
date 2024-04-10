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
        int n, m;
        cin >> n >> m;
        vector lo(n, vector(m, 0));
        vector hi(n, vector(m, 0));

        for (int i : ra(0, n)) {
            for (int j : ra(0, m)) {
                int x;
                cin >> x;
                lo[i][j] = 1e9;
                hi[i][j] = -1e9;
                if (i > 0) {
                    lo[i][j] = min(lo[i][j], lo[i-1][j]);
                    hi[i][j] = max(hi[i][j], hi[i-1][j]);
                }

                if (j > 0) {
                    lo[i][j] = min(lo[i][j], lo[i][j-1]);
                    hi[i][j] = max(hi[i][j], hi[i][j-1]);
                }

                if (i == 0 && j == 0) {
                    lo[i][j] = 0;
                    hi[i][j] = 0;
                }

                lo[i][j] += x;
                hi[i][j] += x;
            }
        }

        if ((n+m) % 2 == 1 && lo[n-1][m-1] <= 0 && hi[n-1][m-1] >= 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}