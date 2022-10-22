#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[5001][5001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int na, nb;
  cin >> na >> nb;
  string a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = 0; i <= na; i++) {
    for (int j = 0; j <= nb; j++) {
      ans = max(ans, dp[i][j]);
      //Both
      if (i < na && j < nb) {
        dp[i+1][j+1] = max(dp[i+1][j+1], max(dp[i][j],0)+(a[i]==b[j])*4-2);
      }
      //Skip a
      if (i < na) {
        dp[i+1][j] = max(dp[i+1][j], max(dp[i][j],0)-1);
      }
      //Skip b
      if (j < nb) {
        dp[i][j+1] = max(dp[i][j+1], max(dp[i][j],0)-1);
      }
    }
  }
  cout << ans << endl;
}