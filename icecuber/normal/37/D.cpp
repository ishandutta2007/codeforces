#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[100], y[100];
ll mod = 1e9+7;

ll ncr[1001][1001];
int main() {
  ncr[0][0] = 1;
  for (int n = 1; n <= 1000; n++) {
    ncr[n][0] = 1;
    for (int k = 1; k <= 1000; k++) {
      ncr[n][k] = ncr[n-1][k]+ncr[n-1][k-1];
      if (ncr[n][k] >= mod)
	ncr[n][k] -= mod;
    }
  }
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int k = 0;
  for (int i = 0; i < n; i++) cin >> x[i], k += x[i];
  for (int i = 0; i < n; i++) cin >> y[i];

  //dp[i][j] = number of ways up to room i, with j people unassigned
  vector<ll> dp(k+1,0);
  dp[0] = 1;
  ll mul = 1, left = k;
  for (int i = 0; i < n; i++) {
    (mul *= ncr[left][x[i]]) %= mod;
    left -= x[i];
    vector<ll> ndp(k+1,0);
    for (int j = 0; j <= k-x[i]; j++) {
      // Leaving l people
      for (int l = 0; l <= j+x[i] && l <= y[i]; l++) {
	(ndp[j+x[i]-l] += dp[j]*ncr[j+x[i]][l]) %=mod;
      }
    }
    swap(dp,ndp);
  }
  cout << (dp[0]*mul)%mod << endl;
}