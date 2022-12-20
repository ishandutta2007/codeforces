#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 1;
const int K = 101;
const int mod = 998244353;

int pr[N][K], a[N];
long long dp[N][K], mdf[K], mdf1[K], uk[K];

int main() {
   int i, j, n, k, l, p, a1, b1, len;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k >> len;
    if (len == 1) {
        cout << 0;
        return 0;
    }
    --len;
    --len;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        for (j = 1; j <= k; ++j)
            pr[i][j] = pr[i - 1][j];
        if (a[i] > 0)
            ++pr[i][a[i]];
    }
    for (j = 1; j <= k; ++j)
        uk[j] = 0;
    for (i = 1; i <= n; ++i) {
        long long sum = 0;
        if (i == 1)
            ++sum;
        for (j = 1; j <= k; ++j) {
            mdf1[j] = 0;
            sum += mdf[j];
        }
        sum %= mod;
        for (j = 1; j <= k; ++j) {
            if (uk[j] < i)
                if (a[i] > 0 && a[i] != j)
                    continue;
                else
                    uk[j] = i;
            while (uk[j] < i + len && uk[j] < n && (a[uk[j] + 1] < 0 || a[uk[j] + 1] == j))
                ++uk[j];
            mdf1[j] = (mdf1[j] + sum - mdf[j] + mod) % mod;
            dp[uk[j] + 1][j] = (dp[uk[j] + 1][j] + sum - mdf[j] + mod) % mod;
        }
        for (j = 1; j <= k; ++j)
            mdf[j] = (mdf[j] + mdf1[j] - dp[i][j] + mod) % mod;
    }
    long long ans = 0;
    for (j = 1; j <= k; ++j)
        ans += mdf[j];
    cout << ans % mod;

}