#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[4000][4000];
int b[4000];
int pos[1000001], upd[1000001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> b[i];
  int ans = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (upd[b[i]] == i+1) dp[j][i] = dp[pos[b[i]]][j]+1;
      else dp[j][i] = 2;
      ans = max(ans, dp[j][i]);
      pos[b[j]] = j;
      upd[b[j]] = i+1;
    }
  }
  cout << ans << endl;
}