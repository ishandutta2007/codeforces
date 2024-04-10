#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

ll dp[105][105][2][2];

ll solve(int a, int b, int c, int d) {
    if (dp[a][b][c][d] != -1) return dp[a][b][c][d];
    if (a == 0 && b == 0) {
        if (d == 0) return dp[a][b][c][d] = (c == 0);
        else return dp[a][b][c][d] = (c != 0);
    }
    if (d) {
        bool win = 0;
        if (a && solve(a - 1, b, c, 0) == 0) win = 1;
        if (b && solve(a, b - 1, c, 0) == 0) win = 1;
        return dp[a][b][c][d] = win;
    } else {
        bool win = 0;
        if (a && solve(a - 1, b, c, 1) == 0) win = 1;
        if (b && solve(a, b - 1, c ^ 1, 1) == 0) win = 1;
        return dp[a][b][c][d] = win;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof dp);
        int n;
        cin >> n;
        int c0 = 0, c1 = 0;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            if (tmp & 1) c1++;
            else c0++;
        }
        if (solve(c0, c1, 0, 0)) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
}