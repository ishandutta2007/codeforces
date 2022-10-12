#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;
long long n, l, r;
long long dp[500000][3];
long long cnt[3];
const int mod = 1000000007;

signed main()
{
    cin >> n >> l >> r;
    while (l % 3 != 0 && l < r)
    {
        cnt[l % 3]++;
        l++;
    }
    while (r % 3 != 2 && r > l)
    {
        cnt[r % 3]++;
        r--;
    }
    if (l != r)
    {
        cnt[0] += (r - l + 1) / 3;
        cnt[1] += (r - l + 1) / 3;
        cnt[2] += (r - l + 1) / 3;
    }
    if (l == r)
    {
        cnt[l % 3]++;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = (dp[i - 1][0] * cnt[0] + dp[i - 1][1] * cnt[2] + dp[i - 1][2] * cnt[1]) % mod;
        dp[i][1] = (dp[i - 1][1] * cnt[0] + dp[i - 1][2] * cnt[2] + dp[i - 1][0] * cnt[1]) % mod;
        dp[i][2] = (dp[i - 1][2] * cnt[0] + dp[i - 1][0] * cnt[2] + dp[i - 1][1] * cnt[1]) % mod;
    }
    cout << dp[n][0];
}