#include <bits/stdc++.h>

using int64 = long long;

const int N = 3e5 + 7;

int n, k;
int x[N], y[N];
int dp[N][2];

int get(int la, int lb, int ca, int cb) {
    int ret = k + 1;
    if (la <= k) {
        int need = (cb + k - 1) / k;
        int64 maxPoss = 1LL * cb * k + k - la;
        if (need <= ca && ca <= maxPoss) ret = std::min(1LL * ret, std::max(1LL, k - maxPoss + ca));
    }
    if (lb <= k) {
        int64 maxPoss = 1LL * (ca - 1) * k + k - lb;
        int64 maxPoss2 = 1LL * (cb + 1) * k;
        if (cb <= maxPoss && ca <= maxPoss2) ret = std::min(1LL * ret, std::max(1LL, k - maxPoss2 + ca));
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &y[i]);
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = get(dp[i - 1][0], dp[i - 1][1], x[i], y[i]);
        dp[i][1] = get(dp[i - 1][1], dp[i - 1][0], y[i], x[i]);
    }
    puts((dp[n][0] <= k || dp[n][1] <= k) ? "YES" : "NO");
    return 0;
}