#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s[2];
    cin >> s[0] >> s[1];

    int n = s[0].size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(2, -1000)));
    dp[0][1][1] = 0;
    auto maxa = [](int& x, int y) { x = max(x, y); };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 1; k++) {
                int a = s[0][i] == 'X';
                int b = s[1][i] == 'X';
                maxa(dp[i+1][a][b], dp[i][j][k]);
                if (j == 0 && k == 0) {
                    if (a == 0)
                        maxa(dp[i+1][1][b], dp[i][j][k] + 1);
                    if (b == 0)
                        maxa(dp[i+1][a][1], dp[i][j][k] + 1);
                }
                if (a == 0 && b == 0) {
                    if (j == 0 || k == 0)
                        maxa(dp[i+1][1][1], dp[i][j][k] + 1);
                }
            }
        }
    }

    int m = 0;
    for (int j = 0; j <= 1; j++) {
        for (int k = 0; k <= 1; k++) {
            maxa(m, dp[n][j][k]);
        }
    }
    cout << m << '\n';
}