#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const short inf = 10000;
void self_min(short&a, short b) {
  a = min(a, b);
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    vector<vector<array<short,3>>> dp(n+1, vector<array<short,3>>(m+1, array<short,3>{inf,inf,inf}));
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (i == 0 && j == 0) {
          dp[i][j] = {1,0,0};
        }
        self_min(dp[i][j][1], dp[i][j][0]);
        self_min(dp[i][j][2], dp[i][j][1]);
        if (i < n && j < m && a[i] == b[j]) {
          self_min(dp[i+1][j+1][0], dp[i][j][0]+1);
          self_min(dp[i+1][j+1][1], dp[i][j][1]);
          self_min(dp[i+1][j+1][2], dp[i][j][2]+1);
        }
        if (i < n) {
          self_min(dp[i+1][j][0], dp[i][j][0]+2);
          self_min(dp[i+1][j][2], dp[i][j][2]+1);
        }
      }
    }
    if (dp[n][m][2] == inf) {
      cout << -1 << endl;
    } else {
      cout << dp[n][m][2] << endl;
    }
  }
}