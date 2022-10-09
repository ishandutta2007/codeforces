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
        vector<string> a(n);

        for (int i : ra(0, n)) cin >> a[i];

        bool ok = 1;

        for (int i : ra(0, n)) {
            for (int j : ra(0, m)) {
                if (a[i][j] == '*') {
                    int xl = i, xr = i, yl = j, yr = j, cnt = 1;
                    a[i][j] = '-';
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while (q.size()) {
                        auto [x, y] = q.front(); q.pop();
                        for (int x2 : ra(x-1, x+2)) {
                            for (int y2 : ra(y-1, y+2)) {
                                if (clamp(x2, 0, n-1) == x2 && clamp(y2, 0, m-1) == y2) {
                                    if (a[x2][y2] == '*') {
                                        a[x2][y2] = '-';
                                        xl = min(xl, x2);
                                        xr = max(xr, x2);
                                        yl = min(yl, y2);
                                        yr = max(yr, y2);
                                        cnt++;
                                        q.push({x2, y2});
                                    }
                                }
                            }
                        }
                    }

                    if (cnt != 3 || xr-xl != 1 || yr-yl != 1) {
                        ok = 0;
                    }
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}