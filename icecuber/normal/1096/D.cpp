#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[100001][5], a[100001];
int main() {
  ios::sync_with_stdio(0);
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  string hard = "hard";
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 4; j++) {
      if (s[i-1] == hard[j]) {
	dp[i][j] = min(j ? dp[i-1][j-1] : 1ll<<60, dp[i-1][j]+a[i-1]);
      } else {
	dp[i][j] = dp[i-1][j];
      }
    }
  }
  cout << dp[n][3] << endl;
}