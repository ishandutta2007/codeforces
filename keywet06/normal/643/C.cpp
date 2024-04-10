#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
using float96 = long double;

const int N = 200001;

int t[N], x[N];
int64 s[N];
float96 p[N], dp[N][51], y[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    s[0] = p[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", t + i);
        s[i] = s[i - 1] + t[i];
        p[i] = p[i - 1] + float96(1) / t[i];
    }
    for (int i = 1; i <= n; ++i) dp[i][0] = 1e+18;
    for (int i = 1; i <= k; ++i) {
        int l = 0, r = 1;
        x[0] = 0;
        y[0] = 0;
        for (int j = 1; j <= n; ++j) {
            while (l + 1 < r && dp[x[l + 1]][i - 1] - s[x[l + 1]] * p[j] <
                                    dp[x[l]][i - 1] - s[x[l]] * p[j]) {
                ++l;
            }
            dp[j][i] = dp[x[l]][i - 1] - s[x[l]] * p[j] + s[j] * p[j];
            while (l < r && dp[j][i - 1] - s[j] * y[r - 1] <
                                dp[x[r - 1]][i - 1] - s[x[r - 1]] * y[r - 1]) {
                --r;
            }
            x[r++] = j;
            if (r > 1) {
                y[r - 1] = (dp[x[r - 1]][i - 1] - dp[x[r - 2]][i - 1]) /
                           (s[x[r - 1]] - s[x[r - 2]]);
            }
        }
    }
    float96 ans = dp[n][k] - s[n] * p[n];
    for (int i = 1; i <= n; ++i) ans += (float96)s[i] / t[i];
    printf("%.12f\n", (double)ans);
    return 0;
}