#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << 0 << endl;
    return 0;
  }
  n = 1<<n;
  vector<int> cnt(n*2);
  vector<vector<int>> dp(n, vector<int>(4, -1e9));

  for (int i = 0; i < k; i++) {
    int a;
    cin >> a;
    a--;
    cnt[n+a]++;
  }
  for (int i = n-1; i; i--)
    cnt[i] = cnt[i*2]+cnt[i*2+1];

  for (int i = n/2; i < n; i++) {
    int c = cnt[i];
    dp[i][0] = !!c;
    if (c >= 1) dp[i][1] = 1;
    if (c >= 1) dp[i][2] = 1;
    if (c >= 2) dp[i][3] = 1;
  }

  for (int i = n/2-1; i > 0; i--) {
    for (int a = 0; a < 4; a++) {
      for (int b = 0; b < 4; b++) {
	for (int c = 0; c < 4; c++) {
	  if (c%2 > a%2+b%2 || c%2+c/2 > a%2+a/2+b%2+b/2) continue;
	  int get = (a/2 || b/2) + (a%2 || b%2) + (c/2);
	  dp[i][c] = max(dp[i][c], dp[i*2][a]+dp[i*2+1][b] + get);
	}
      }
    }
  }

  cout << max({dp[1][0], dp[1][1], dp[1][2], dp[1][3]})+1 << endl;
  /*int ans = 1;
  for (int i = 0; i < n/2; i++) {
    if (cnt[n/2+i]) ans++;
  }
  for (int i = n/2-1; i > 0; i--) {
    int c = cnt[i];
    if (c == 1) ans += 2;
    else if (c >= 2) ans += 3;
  }
  cout << ans << endl;*/
}