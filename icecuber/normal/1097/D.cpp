#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;
ll pow(ll a, ll p = mod-2) {
  ll r = 1;
  while (p) {
    if(p&1) r = (r*a)%mod;
    a = (a*a)%mod;
    p >>= 1;
  }
  return r;
}


ll dp[10001][100];

int main() {
  ll n, k;
  cin >> n >> k;

  map<ll,ll> m;
  for (ll i = 2; i < 1e8; i++) {
    if (n%i==0) {
      while (n%i==0) m[i]++, n /= i;
    }
  }
  if (n > 1) m[n]++;
  ll ans = 1;
  for (auto q : m) {
    ll p = q.first, a = q.second;
    dp[0][a] = 1;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j <= a; j++) dp[i+1][j] = 0;
      for (int j = 0; j <= a; j++) {
	ll ij = pow(j+1);
	for (int l = 0; l <= j; l++)
	  dp[i+1][l] = (dp[i+1][l]+dp[i][j]*ij)%mod;
      }
    }
    dp[0][a] = 0;
    //cout << dp[0][0] << ' ' << dp[0][1] << endl;
    //cout << dp[1][0] << ' ' << dp[1][1] << endl;
    ll po = 1, e = 0;
    for (int i = 0; i <= a; i++) {
      e = (e+dp[k][i]*po)%mod;
      po = po*p%mod;
    }
    //cout << e << endl;
    ans = (ans*e)%mod;
  }
  cout << (ans%mod+mod)%mod << endl;
}