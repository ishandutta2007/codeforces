#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[501][501];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> c(m);
  vector<vector<int>> pos(n);
  for (int i = 0; i < m; i++) {
    cin >> c[i];
    c[i]--;
    pos[c[i]].push_back(i);
  }
  for (int i = 0; i <= m; i++)
    dp[i][i] = 1;
  ll mod = 998244353;
  for (int k = n-1; k >= 0; k--) {
    int a = pos[k][0], b = pos[k].back()+1;
    for (int i = a; i < b; i++)
      if (c[i] < k) {
	cout << 0 << endl;
	return 0;
      }
    ll ways = 1;
    for (int i = 0; i+1 < pos[k].size(); i++)
      (ways *= dp[pos[k][i]+1][pos[k][i+1]]) %= mod;

    int s = a, e = b;
    while (s && c[s-1] > k) s--;
    while (e < m && c[e] > k) e++;

    vector<ll> left(m+1,0), right(m+1,0);
    for (int l = s; l <= a; l++) {
      for (int m = l; m <= a; m++) {
	(left[l] += dp[l][m]*dp[m][a]) %= mod;
      }
    }
    for (int r = b; r <= e; r++) {
      for (int m = b; m <= r; m++) {
	(right[r] += dp[b][m]*dp[m][r]) %= mod;
      }
    }

    for (int l = s; l <= a; l++) {
      for (int r = b; r <= e; r++) {
	dp[l][r] = ways * left[l] % mod * right[r] % mod;
      }
    }
  }
  /*for (int l = 0; l < m; l++)
    for (int r = 0; r <= m; r++)
    cout << l << ' ' << r << ' ' << dp[l][r] << endl;*/
  cout << dp[0][m] << endl;
}