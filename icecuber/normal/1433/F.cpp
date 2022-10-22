#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void self_max(int&a, int b) {
  a = max(a, b);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w, k;
  cin >> h >> w >> k;

  vector<int> DP(k, -1e9);
  DP[0] = 0;
  for (int i = 0; i < h; i++) {
    vector<int> a(w);
    vector<vector<int>> dp(w/2+1, vector<int>(k, -1e9));
    for (int r = 0; r < k; r++)
      dp[0][r] = DP[r];

    for (int j = 0; j < w; j++) {
      cin >> a[j];

      auto ndp = dp;
      for (int r = 0; r < k; r++)
	for (int u = 0; u < w/2; u++) {
	  self_max(ndp[u+1][(r+a[j])%k], dp[u][r]+a[j]);
	}
      dp = ndp;
    }
    fill_n(DP.begin(), k, -(int)1e9);
    for (int u = 0; u <= w/2; u++) {
      for (int r = 0; r < k; r++)
	DP[r] = max(DP[r], dp[u][r]);
    }
  }
  cout << DP[0] << endl;
}