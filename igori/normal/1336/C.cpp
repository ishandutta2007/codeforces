#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m, ans;
string s, t;
int get(int i, int j) {return 0 <= i && i < n && 0 <= j && j < n && (s[i] == t[j] || t[j] == '?');}
signed main()
{
    cin >> s >> t;
    n = s.size(), m = t.size();
    t += string(n - m, '?');
    vector<int> dp(n);
    for (int i = 0; i < n; i++) if (get(0, i)) dp[i] = 2;
    if (0 >= m - 1) ans = dp[0];
    for (int i = 1; i < n; i++)
    {
        vector<int> dp2(n);
        for (int r = i - 1; r < n; r++)
        {
            int l = r - i + 1;
            if (get(i, l - 1)) dp2[r] = (dp2[r] + dp[r]) % MOD;
            if (get(i, r + 1)) dp2[r + 1] = (dp2[r + 1] + dp[r]) % MOD;
        }
        if (i >= m - 1) ans = (ans + dp2[i]) % MOD;
        dp = dp2;
    }
    cout << ans << "\n";
}