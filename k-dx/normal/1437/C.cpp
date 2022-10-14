#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+5;
int main () {
    int ttt;
    scanf("%d", &ttt);
    while(ttt--) {
        int n;
        scanf("%d", &n);
        vector<int> t(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &t[i]);
            t[i]--;
        }

        sort(t.begin(), t.end());

        vector<vector<int>> dp(n + 1, vector<int>(2 * n, INF));

        dp[0][0] = 0;
        for (int i = 0; i < n+1; i++) {
            for (int j = 0; j < 2*n-1; j++) {
                if (dp[i][j] < INF) {
                    if (i < n) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(t[i] - j));

                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
                }

            }
        }
        printf("%d\n", dp[n][2 * n - 1]);
    }
}