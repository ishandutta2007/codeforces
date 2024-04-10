#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

int n;
char S[2005], T[2005];
int dp[2005][2005];
int cntS[2005][30], cntT[2005][30];
int solve() {
    cin >> n >> S + 1 >> T + 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            dp[i][j] = n + 1;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            cntS[i][j] = cntS[i - 1][j];
            cntT[i][j] = cntT[i - 1][j];
        }
        ++cntS[i][S[i] - 'a'];
        ++cntT[i][T[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (cntS[n][i] != cntT[n][i]) return -1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (j < n && S[i + 1] == T[j + 1]) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            if (j < n) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            int c = S[i + 1] - 'a';
            if (i < j && cntT[j][c] - cntS[i][c] > 0) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        }
    }
    return dp[n][n];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf("%d\n", solve());
    return 0;
}