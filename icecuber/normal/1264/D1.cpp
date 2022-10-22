#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;

vector<vector<ll>> f(string s) {
  int n = s.size();
  vector<vector<ll>> r;
  vector<ll> dp(n+1, 0);
  dp[0] = 1;

  r.push_back(dp);
  for (char c : s) {
    vector<ll> ndp(n+1,0);
    if (c == '(') {
      for (int j = 1; j <= n; j++)
	ndp[j] = dp[j-1];
    } else if (c == ')') {
      ndp = dp;
    } else if (c == '?') {
      for (int j = 0; j <= n; j++)
	ndp[j] = ((j?dp[j-1]:0)+dp[j])%mod;
    } else assert(0);
    dp = ndp;
    r.push_back(dp);
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<ll>> a = f(s);
  reverse(s.begin(), s.end());
  for (int i = 0; i < n; i++) {
    if (s[i] != '?')
      s[i] ^= '('^')';
  }
  vector<vector<ll>> b = f(s);
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      (ans += a[i][j]*b[n-i][j]%mod*j) %= mod;
    }
    /*for (int j = 0; j <= n; j++) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
    for (int j = 0; j <= n; j++) {
      cout << b[n-i][j] << ' ';
    }
    cout << endl << endl;*/
  }
  cout << ans << endl;
}