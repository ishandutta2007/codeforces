#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MOD = 998244353;

int main(void) {
  string s, t;
  cin >> s >> t;
  int n = s.length();
  int m = t.length();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1));
  for (int i = 1; i <= n; i++) {
    char sChar = s[i - 1];
    for (int j = 0; j <= m; j++) {
      dp[i][j] = 0;
      if (j == m) {
        dp[i][j] = (2 * dp[i - 1][j]) % MOD;
      } else {
        char tChar = t[j];
        if (sChar == tChar) {
          dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
        }
        if (j + i > m || sChar == t[j + i - 1]) {
          dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
        }
      }
    }
  }

  int result = 0;
  for (int i = m; i <= n; i++) {
    result = (result + dp[i][0]) % MOD;
  }
  cout << result << "\n";
}