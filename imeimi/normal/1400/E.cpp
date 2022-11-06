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
int A[5001];
int dp[5001][5001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    memset(dp, 0x1f, sizeof(dp));
    dp[0][0] = n;
    for (int i = 1; i <= n; ++i) {
        int mn = 1e8;
        for (int j = 0; j <= min(n, A[i]); ++j) {
            mn = min(mn + 1, dp[i - 1][j]);
            dp[i][j] = mn;
        }
        if (A[i] <= n) --dp[i][A[i]];
        for (int j = min(n, A[i]); j > 0; --j) {
            dp[i][j - 1] = min(dp[i][j - 1], dp[i][j]);
        }
    }
    printf("%d\n", dp[n][0]);
    return 0;
}