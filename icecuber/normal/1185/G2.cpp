#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;
ll dp[51][51][51][3];
ll ways01[51][51][2501], ways2[51][2501];
ll fac[51];

void self_add(ll&a, ll b) {
  a += b;
  if (a >= mod)
    a -= mod;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, T;
  cin >> n >> T;
  vector<int> v[3];
  for (int i = 0; i < n; i++) {
    int ti, g;
    cin >> ti >> g;
    g--;
    v[g].push_back(ti);
  }
  int na = v[0].size(), nb = v[1].size(), nc = v[2].size();
  dp[0][0][0][0] = dp[0][0][0][1] = dp[0][0][0][2] = (mod+1)/2;
  for (int i = 0; i <= na; i++)
    for (int j = 0; j <= nb; j++)
      for (int k = 0; k <= nc; k++)
	for (int l = 0; l < 3; l++) {
	  if (l != 0) self_add(dp[i+1][j][k][0], dp[i][j][k][l]);
	  if (l != 1) self_add(dp[i][j+1][k][1], dp[i][j][k][l]);
	  if (l != 2) self_add(dp[i][j][k+1][2], dp[i][j][k][l]);
	}

  ways01[0][0][0] = 1;
  for (int k : v[0])
    for (int j = T-k; j >= 0; j--)
      for (int l = 0; l < v[0].size(); l++)
	self_add(ways01[l+1][0][j+k], ways01[l][0][j]);
  for (int k : v[1])
    for (int j = T-k; j >= 0; j--)
      for (int l = 0; l <= v[0].size(); l++)
	for (int m = 0; m < v[1].size(); m++)
	  self_add(ways01[l][m+1][j+k], ways01[l][m][j]);

  ways2[0][0] = 1;
  for (int k : v[2])
    for (int j = T-k; j >= 0; j--)
      for (int l = 0; l < v[2].size(); l++)
	self_add(ways2[l+1][j+k], ways2[l][j]);

  fac[0] = 1;
  for (int i = 1; i <= na || i <= nb || i <= nc; i++)
    fac[i] = fac[i-1]*i%mod;

  ll ans = 0;
  for (int a = 0; a <= na; a++) {
    for (int b = 0; b <= nb; b++) {
      for (int c = 0; c <= nc; c++) {
	ll mul = (dp[a][b][c][0]+dp[a][b][c][1]+dp[a][b][c][2])*
	  fac[a]%mod * fac[b]%mod *fac[c]%mod;
	for (int i = 0; i <= T; i++) {
	  int j = T-i;
	  (ans += ways01[a][b][i]*ways2[c][j]%mod * mul) %= mod;
	}
      }
    }
  }
  cout << ans << endl;
}