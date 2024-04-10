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

const int inf = 1e9;
int n;
char S[200005];
int dp[200005][3][3][3][3];

void set_min(int &x, int y) {
    if (x > y) x = y;
}

int solve() {
    cin >> n >> S + 1;
    if (n == 3) {
        if (S[1] == S[2] && S[2] == S[3]) return 1;
        return 0;
    }
    for (int i = 0; i <= n; ++i) {
        memset(dp[i], 0x3f, sizeof(dp[i]));
    }
    dp[0][0][0][0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) for (int k = 0; k < 3; ++k) for (int l = 0; l < 3; ++l) for (int m = 0; m < 3; ++m) {
            int val = dp[i - 1][j][k][l][m] + (S[i] != 'L');
            if (val > inf) continue;
            int nj = j + (i <= 2 && !k);
            int nk = k;
            int nl = l + 1;
            int nm = 0;
            if (nj < 3 && nl < 3) set_min(dp[i][nj][nk][nl][nm], val);
            val = dp[i - 1][j][k][l][m] + (S[i] != 'R');
            nj = j;
            nk = k + (i <= 2 && !j);
            nl = 0;
            nm = m + 1;
            if (nk < 3 && nm < 3) set_min(dp[i][nj][nk][nl][nm], val);
        }
    }
    int ans = inf;
    for (int j = 0; j < 3; ++j) for (int k = 0; k < 3; ++k) for (int l = 0; l < 3; ++l) for (int m = 0; m < 3; ++m) {
        if (j + l > 2 || k + m > 2) continue;
        set_min(ans, dp[n][j][k][l][m]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf("%d\n", solve());
    return 0;
}