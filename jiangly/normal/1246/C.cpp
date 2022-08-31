#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 2E3 + 5, MOD = 1E9 + 7;
int n, m;
string s[MAX_N];
int dp[MAX_N][MAX_N][2];
vector<int> row[MAX_N], col[MAX_N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    if (n == 1) {
        cout << (count(s[0].begin(), s[0].end(), 'R') == 0) << endl;
        return 0;
    }
    if (m == 1) {
        cout << (count(s, s + n, "R") == 0) << endl;
        return 0;
    }
    dp[1][1][0] = 1;
    dp[1][1][1] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = j = m - 1; j >= 0; --j)
            if (s[i][j] == 'R')
                row[i + 1].push_back(j + 1);
    for (int i = 0; i < m; ++i)
        for (int j = n - 1; j >= 0; --j)
            if (s[j][i] == 'R')
                col[i + 1].push_back(j + 1);
    for (int i = 2; i <= m; ++i) {
        if (row[1].size() <= m - i)
            dp[1][i][0] = dp[1][i - 1][1];
        else
            dp[1][i][0] = (dp[1][i - 1][1] - dp[1][row[1][m - i] - 1][1] + MOD) % MOD;
        dp[1][i][1] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        if (col[1].size() <= n - i)
            dp[i][1][1] = dp[i - 1][1][0];
        else
            dp[i][1][1] = (dp[i - 1][1][0] - dp[col[1][n - i] - 1][1][0] + MOD) % MOD;
        dp[i][1][0] = 1;
    }
    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= m; ++j) {
            if (row[i].size() <= m - j)
                dp[i][j][0] = dp[i][j - 1][1];
            else
                dp[i][j][0] = (dp[i][j - 1][1] - dp[i][row[i][m - j] - 1][1] + MOD) % MOD;
            if (col[j].size() <= n - i)
                dp[i][j][1] = dp[i - 1][j][0];
            else
                dp[i][j][1] = (dp[i - 1][j][0] - dp[col[j][n - i] - 1][j][0] + MOD) % MOD;
            if (i != n || j != m) {
                dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][0]) % MOD;
                dp[i][j][1] = (dp[i][j][1] + dp[i][j - 1][1]) % MOD;
            }
        }
    cout << (dp[n][m][0] + dp[n][m][1]) % MOD << endl;
    return 0;
}