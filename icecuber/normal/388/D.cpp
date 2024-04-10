#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ncr[30][30];
int f(int n, int k) {
  int ans = 0;
  for (int i = k; i <= n; i += 2)
    ans += ncr[n][i];
  return ans;
}

int main() {
  ll mod = 1e9+7;
  for (int n = 0; n < 30; n++) {
    ncr[n][0] = 1;
    for (int k = 1; k <= n; k++) {
      ncr[n][k] = ncr[n-1][k]+ncr[n-1][k-1];
    }
  }
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  n++;
  ll ans = 0;
  for (int i = 0; i < 30; i++) {
    if ((n>>29-i&1) == 0) continue;
    vector<ll> dp(30,0);
    dp[0] = 1;
    int m = n-(1<<29-i);
    for (int j = 0; j < 30; j++) {
      vector<ll> ndp(30,0);
      if (j > i) {
	for (int k = 1; k < 30; k++) {
	  (ndp[k] += dp[k-1]+f(k,1)*dp[k]) %= mod;
	}
	for (int k = 0; k < 30; k++) {
	  (ndp[k] += f(k,0)*dp[k]) %= mod;
	}
      } else if ((m>>29-j&1) == 1) {
	for (int k = 1; k < 30; k++) {
	  (ndp[k] += dp[k-1]+f(k,1)*dp[k]) %= mod;
	}
      } else {
	for (int k = 0; k < 30; k++) {
	  (ndp[k] += f(k,0)*dp[k]) %= mod;
	}
      }
      dp = ndp;
    }
    for (int k = 0; k < 30; k++)
      (ans += dp[k]) %= mod;
  }
  cout << ans << endl;
}