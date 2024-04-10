// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
int dp[2][255][255];
int z[255];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i : ra(0, n)) {
        int x;
        cin >> x;
        z[i+1] = z[i] + x;
    }

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    memset(dp, 63, sizeof(dp));

    int h = m;

    for (int x : ra(0, h+1)) {
        dp[1][0][x] = abs(x - z[1]);
    }

    for (int i : ra(1, n)) {
        auto ol = dp[i%2];
        auto nu = dp[1-i%2];
        memset(nu, 63, sizeof(dp[0]));
        for (int x : ra((i-1)*m/n, m+1)) {
            for (int y : ra(x, m+1)) {
                for (int t : ra(0, h+1)) {
                    if (t <= y-x) {
                        nu[y][y+t] = min(nu[y][y+t], ol[x][y] + abs(y+t - z[i+1]));
                    }
                }
            }
        }
    }

    int sol = 1e9;
    for (int i : ra(0, m+1)) {
        sol = min(sol, dp[n%2][i][m]);
    }

    cout << sol << '\n';
}