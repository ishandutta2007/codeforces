#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#pragma GCC optimize("O2")
using namespace std;
#define td typedef
td long long ll;

ll n, m;
vector<int> sc;
vector<int> s;
ll ans = 0;
const long long MOD = 1e9 + 7;
const long long MOD2 = 1e15;

inline bool ok(int l, int r)
{
    int x = 0;
    if (r - l + 1 < 4)
        return 1;
    if (r - l + 1 > 4)
        return 0;
    if (r - l + 1 == 4)
    {
        for (int i = l; i <= r; i++)
        {
            x = 2 * x + s[i];
        }
        if (x == 15)
            return 0;
        if (x == 7)
            return 0;
        if (x == 12)
            return 0;
        if (x == 10)
            return 0;
        return 1;
    }
}

inline int degenerate()
{
    int z[3001];
    z[0] = s.size();
    int L = 0, R = 0;
    int xp = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (s.size() - i < xp)
            return xp;
        z[i] = max(0, min(R - i, z[i - L]));
        while (i + z[i] < s.size() && s[z[i]] == s[z[i] + i]) z[i]++;
        if (i + z[i] > R)
        {
            R = i + z[i];
            L = i;
        }
        xp = max(xp, z[i]);
    }
    return xp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    scanf("%d ", &m);
    for (int i = 0; i < m; i++)
    {
        int c;
        scanf("%d ", &c);
        sc.push_back(c);
        s.resize(0);
        for (int j = 0; j <= i; j++)
        {
            s.push_back(sc[j]);
        }
        reverse(s.begin(), s.end());
        vector<long long> dp(s.size() + 1);
        dp[0] = 1;
        for (int j = 1; j <= s.size(); j++)
        {
            if (j >= 1) dp[j] += dp[j - 1] * ok(j - 1, j - 1);
            if (j >= 2) dp[j] += dp[j - 2] * ok(j - 2, j - 1);
            if (j >= 3) dp[j] += dp[j - 3] * ok(j - 3, j - 1);
            if (j >= 4) dp[j] += dp[j - 4] * ok(j - 4, j - 1);
            if (dp[j] >= MOD2) dp[j] %= MOD;
        }
        int l = degenerate();
        for (int j = l + 1; j <= s.size(); j++)
        {
            ans += dp[j];
        }
        if (ans >= MOD)
            ans %= MOD;
        printf("%d ", ans);
    }
}