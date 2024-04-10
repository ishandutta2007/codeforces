#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  const int mod = 1e9 + 7;
  int q;
  cin >> q;
  while (q--)
  {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1));
    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j)
        vis[i + 1][j + 1] = s.substr(i, j - i + 1) == t;
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, inf));
    vector<vector<int>> f(n + 2, vector<int>(n + 2));
    vector<vector<int>> c(n + 2, vector<int>(n + 2));
    function<int(int, int)> C = [&](int n, int m)
    {
      if (m == 0 || m == n)
        return 1;
      if (m == 1)
        return n;
      if (c[n][m])
        return c[n][m];
      return c[n][m] = (C(n - 1, m - 1) + C(n - 1, m)) % mod;
    };
    function<void(int, int)> Dp = [&](int l, int r)
    {
      if (r - l + 1 < t.size())
      {
        dp[l][r] = 0;
        f[l][r] = 1;
        return;
      }
      if (dp[l][r] != inf)
        return;
      bool flag = true;
      for (int i = l; i + t.size() - 1 <= r; ++i)
        if (vis[i][i + t.size() - 1])
        {
          flag = false;
          Dp(l, i - 1);
          Dp(i + t.size(), r);
          if (1 + dp[l][i - 1] + dp[i + t.size()][r] < dp[l][r])
          {
            dp[l][r] = 1 + dp[l][i - 1] + dp[i + t.size()][r];
            f[l][r] = 1ll * C(dp[l][i - 1] + dp[i + t.size()][r], dp[l][i - 1]) * f[l][i - 1] % mod * f[i + t.size()][r] % mod;
          }
          else if (1 + dp[l][i - 1] + dp[i + t.size()][r] == dp[l][r])
          {
            f[l][r] = (f[l][r] + 1ll * C(dp[l][i - 1] + dp[i + t.size()][r], dp[l][i - 1]) * f[l][i - 1] % mod * f[i + t.size()][r] % mod) % mod;
          }
        }
      if (flag)
      {
        dp[l][r] = 0;
        f[l][r] = 1;
      }
    };
    Dp(1, n);
    int ans = f[1][n];
    vector<int> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= dp[1][n]; ++i)
    {
      inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
      ans = 1ll * ans * inv[i] % mod;
    }
    cout << dp[1][n] << ' ' << ans << '\n';
  }
}