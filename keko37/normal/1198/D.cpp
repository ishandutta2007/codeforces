#include<bits/stdc++.h>

using namespace std;

const int MAXN = 55;

int n;
int a[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];

int get (int x1, int y1, int x2, int y2) {
    return a[x2][y2] - a[x1-1][y2] - a[x2][y1-1] + a[x1-1][y1-1];
}

int main () {
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            char c; cin >> c;
            a[i][j] = (c == '#');
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    for (int h = 1; h <= n; h++) {
        for (int w = 1; w <= n; w++) {
            for (int x1 = 1; x1 + h - 1 <= n; x1++) {
                for (int y1 = 1; y1 + w - 1 <= n; y1++) {
                    int x2 = x1 + h - 1, y2 = y1 + w - 1;
                    if (get(x1, y1, x2, y2) == 0) continue;
                    int res = max(x2 - x1, y2 - y1) + 1;
                    for (int k = x1; k < x2; k++) {
                        res = min(res, dp[x1][k][y1][y2] + dp[k+1][x2][y1][y2]);
                    }
                    for (int k = y1; k < y2; k++) {
                        res = min(res, dp[x1][x2][y1][k] + dp[x1][x2][k+1][y2]);
                    }
                    dp[x1][x2][y1][y2] = res;
                }
            }
        }
    }
    cout << dp[1][n][1][n];
    return 0;
}