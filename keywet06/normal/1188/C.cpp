#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

int dp[1005][1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int lim = 100000 / (k - 1);
    vector<int> sum(lim + 1);
    for (int x = 1; x <= lim; ++x) {
        for (int i = 0; i < n; ++i) {
            memset(dp[i], 0, (k + 1) * sizeof(int));
        }
        int p = 1;
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                for (int j = 1; j <= k; ++j) {
                    dp[i][j] += dp[i - 1][j];
                    if (dp[i][j] >= P) {
                        dp[i][j] -= P;
                    }
                }
            }
            sum[x] += dp[i][k];
            if (sum[x] >= P) {
                sum[x] -= P;
            }
            while (p < n && a[p] - a[i] < x) {
                ++p;
            }
            if (p == n) {
                continue;
            }
            for (int j = 1; j < k; ++j) {
                dp[p][j + 1] += dp[i][j] + (j == 1);
                if (dp[p][j + 1] >= P) {
                    dp[p][j + 1] -= P;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < lim; ++i) {
        sum[i] -= sum[i + 1];
        if (sum[i] < 0) {
            sum[i] += P;
        }
        ans = (ans + 1ll * sum[i] * i) % P;
    }
    ans = (ans + 1ll * sum[lim] * lim) % P;
    cout << ans << endl;
    return 0;
}