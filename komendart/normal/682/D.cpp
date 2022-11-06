#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;
const int maxk = 11;

int dp[maxn][maxn][maxk];
int lcp[maxn][maxn];
int n, m, k;
string s, t;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> k;
    cin >> s >> t;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s[i] == t[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int num = 0; num <= k; num++) {
                int tmp = dp[i][j][num];
                if (i != n) dp[i + 1][j][num] = max(dp[i + 1][j][num], tmp);
                if (j != m) dp[i][j + 1][num] = max(dp[i][j + 1][num], tmp);
                int len = lcp[i][j];
                for (int it = 0; len - it > 0 && num + 1 + it <= k; it++) {
                    int x = dp[i + len - it][j + len - it][num + 1 + it];
                    dp[i + len - it][j + len - it][num + 1 + it] = max(x, tmp + len - it);
                }
            }
        }
    }

    cout << dp[n][m][k] << '\n';
}