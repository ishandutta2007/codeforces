#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;

const int nax = 2e5;
ll w[nax], like[nax];
ll dp[3001][3001];

ll inv(ll a, ll p = mod-2) {
  ll r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> like[i];
  ll likew = 0, notlikew = 0;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    if (like[i]) likew += w[i];
    else notlikew += w[i];
  }

  ll totw = likew + notlikew;
  vector<ll> precomp;
  for (int i = -m; i <= m; i++)
    precomp.push_back(inv(totw+i));

  dp[0][0] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      (dp[i+1][j] += dp[i][j] * (i+likew) %mod *precomp[i-j+m]) %= mod;
      (dp[i][j+1] += dp[i][j] * (notlikew-j) %mod *precomp[i-j+m]) %= mod;
    }
  }
  ll likef = 0, notlikef = 0;
  for (int j = 0; j <= m; j++) {
    (likef += dp[j][m-j]*j) %= mod;
    (notlikef += dp[m-j][j]*j) %= mod;
  }
  (likef = 1+likef*inv(likew) %mod) %= mod;
  (notlikef = 1-notlikef*inv(notlikew) %mod) %= mod;
  for (int i = 0; i < n; i++) {
    ll p = (like[i] ? likef : notlikef) * w[i] %mod;
    cout << (p%mod+mod)%mod << '\n';
  }
}