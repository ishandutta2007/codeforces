// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

bool dp[45][45][45][90];
pair<int, bool> pr[45][45][45][90];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;

        memset(dp, 0, sizeof(dp));
        dp[0][0][0][45] = 1;

        for (int i : ra(0, n)) {
            int c = s[i] - '0';
            for (int x : ra(0, a)) {
                for (int y : ra(0, b)) {
                    for (int d : ra(0, 90)) {
                        if (!dp[i][x][y][d]) continue;

                        dp[i+1][(10*x + c) % a][y][d+1] = 1;
                        pr[i+1][(10*x + c) % a][y][d+1] = {x, 0};

                        dp[i+1][x][(10*y + c) % b][d-1] = 1;
                        pr[i+1][x][(10*y + c) % b][d-1] = {y, 1};
                    }
                }
            }
        }

        int sol = 123123, di = -1;
        for (int d : ra(0, 90)) {
            int q = abs(d - 45);
            if (q != n && dp[n][0][0][d] && q < sol) {
                sol = q;
                di = d;
            }
        }

        if (di == -1) {
            cout << "-1\n";
            continue;
        }

        int ar = 0, br = 0;
        string st(n, 0);
        for (int i=n; i>0; i--) {
            auto [xy, f] = pr[i][ar][br][di];
            if (f == 0) {
                st[i-1] = 'R';
                ar = xy;
                di -= 1;
            } else {
                st[i-1] = 'B';
                br = xy;
                di += 1;
            }
        }

        cout << st << '\n';
    }
}