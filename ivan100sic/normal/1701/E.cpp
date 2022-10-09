// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const uint16_t inf = 16000;
uint16_t dp[5005][5005][3];

void mn(uint16_t& x, uint16_t y) {
    x = min(x, y);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;

        R::reverse(a);
        R::reverse(b);

        for (int i : ra(0, n+1)) {
            for (int j : ra(0, m+1)) {
                R::fill(dp[i][j], inf);
            }
        }

        dp[0][0][0] = 0;
        for (int i : ra(0, n+1)) {
            int i2 = i + 1;
            for (int j : ra(0, m+1)) {
                // in-place jump to higher mode
                for (int mode : {0, 1}) {
                    mn(dp[i][j][mode+1], dp[i][j][mode]);
                }

                if (i == n) continue;

                // stay in mode
                for (int mode : {0, 1, 2}) {
                    for (int take : {0, 1}) {
                        int j2 = j + take;
                        // cannot take if we've already taken everything
                        if (j2 > m) continue;

                        // cannot take different letters
                        if (take && a[i] != b[j]) {
                            continue;
                        }

                        // must take in travel mode
                        if (!take && mode == 1) {
                            continue;
                        }

                        {
                            int cost;
                            if (mode == 0) {
                                cost = 1;
                            } else if (mode == 1) {
                                cost = 0;
                            } else if (mode == 2) {
                                cost = 1 + !take;
                            }
                            mn(dp[i2][j2][mode], dp[i][j][mode] + cost);
                        }
                    }
                }
            }
        }

        uint16_t sol = inf;
        mn(sol, dp[n][m][0]);
        mn(sol, dp[n][m][1]);

        // Mode-2 can finish only at the end, added cost of 1
        mn(sol, dp[n][m][2] + 1);

        if (sol == inf) {
            cout << "-1\n";
        } else {
            cout << sol << '\n';
        }
    }
}