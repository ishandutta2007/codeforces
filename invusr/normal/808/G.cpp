#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  s = ' ' + s;
  t = ' ' + t;
  vector<int> fail(m + 1);
  for (int i = 2, j = 0; i <= m; ++i) {
    while (j && t[j + 1] != t[i]) {
      j = fail[j];
    }
    fail[i] = j += t[j + 1] == t[i];
  }
  vector<vector<int> > dp(n + 1, vector<int>(2, 0));
  for (int i = m; i <= n; ++i) {
    bool can = true;
    for (int j = 1; j <= m; ++j) {
      int k = i - m + j;
      if (s[k] != '?' && s[k] != t[j]) {
        can = false;
        break;
      }
    }
    dp[i][0] = dp[i - 1][0];
    if (can) {
      dp[i][1] = dp[i - m][0];
      for (int j = m; j; j = fail[j]) {
        dp[i][1] = max(dp[i][1], dp[i - m + j][1]);
      }
      dp[i][0] = max(dp[i][0], ++dp[i][1]);
    }
  }
  cout << dp[n][0] << '\n';

  return 0;
}