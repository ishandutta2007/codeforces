#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    
    int MOD = 1e8;
    int dp[2][101][101][11];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 101; j++) {
            for (int k = 0; k < 101; k++) {
                for (int a = 0; a < 11; a++) {
                    dp[i][j][k][a] = 0;
                }
            }
        }
    }

    dp[0][0][0][0] = 1;

    for (int number = 1; number <= n1 + n2; number++) {
        for (int foot = 0; foot <= min(n1, number-1); foot++) {
            int horse = number - 1 - foot;
            if (horse < 0 || horse > n2) continue;

            for (int row = 0; row < 10; row++) {
                if (foot < n1 && row < k1)
                    dp[0][foot+1][horse][row+1] = (dp[0][foot][horse][row] + dp[0][foot+1][horse][row+1]) % MOD;
                if (horse < n2 && row < k2)
                    dp[1][foot][horse+1][row+1] = (dp[1][foot][horse+1][row+1] + dp[1][foot][horse][row]) % MOD;
            }

            for (int row = 0; row < 11; row++) {
                if (foot < n1)
                    dp[0][foot+1][horse][1] = (dp[0][foot+1][horse][1] + dp[1][foot][horse][row]) % MOD;
                if (horse < n2)
                    dp[1][foot][horse+1][1] = (dp[1][foot][horse+1][1] + dp[0][foot][horse][row]) % MOD;
            }
        }
    }

    int total = 0;
    for (int last = 0; last < 2; last++) {
        for (int row = 1; row < 11; row++) {
            total = (total + dp[last][n1][n2][row]) % MOD;
        }
    }

    cout << total << endl;

    return 0;
}