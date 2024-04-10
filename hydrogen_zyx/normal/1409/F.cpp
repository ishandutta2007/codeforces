#include <bits/stdc++.h>
using namespace std;
int dp[205][205][205];
int a[205];
char c[205];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    cin >> c + 1;
    char c1, c2;
    cin >> c1 >> c2;
    for (int i = 0; i < 205; i++) {
        for (int j = 0; j < 205; j++) {
            for (int l = 0; l < 205; l++) {
                dp[i][j][l] = -0x3f3f3f3f;
            }
        }
    }
    int a1, a2;
    if (c1 == c2)
        a1 = a2 = 1;
    else
        a1 = 1, a2 = 2;
    for (int i = 1; i <= n; i++) {
        if (c[i] == c2) a[i] = a2;
        if (c[i] == c1) a[i] = a1;
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int p = 0; p <= n; p++) {
                for (int l = 0; l < 3; l++) {
                    if (j - (l != a[i]) >= 0 && p - (l == 1) >= 0)
                        dp[i][j][p] =
                            max(dp[i][j][p],
                                dp[i - 1][j - (l != a[i])][p - (l == 1)] +
                                    (l == a2 ? (p - (l == 1)) : 0));
                }
            }
        }
    }
    int mmax = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            mmax = max(mmax, dp[n][i][j]);
        }
    }
    cout << mmax;
}