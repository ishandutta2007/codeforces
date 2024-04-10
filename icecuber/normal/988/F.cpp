#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[2005][2005];
int rain[2005];
int w[2005];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int a, n, m;
  cin >> a >> n >> m;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    for (int j = l; j < r; j++) rain[j] = 1;
  }

  fill_n(w, a+1, 1e9);

  for (int i = 0; i < m; i++) {
    int x, p;
    cin >> x >> p;
    w[x] = min(w[x], p);
  }

  fill_n((int*)dp, 2005*2005, 1e9);
  dp[0][2001] = 0;
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= a; j++) {
      dp[i][2001] = min(dp[i][2001], dp[i][j]);
    }
    dp[i][i] = min(dp[i][i], dp[i][2001]);
    for (int j = 0; j <= a; j++) {
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]+w[j]);
    }
    if (!rain[i])
      dp[i+1][2001] = min(dp[i+1][2001], dp[i][2001]);
  }
  int ans = dp[a][2001];
  if (ans == 1e9) ans = -1;
  cout << ans << endl;
}