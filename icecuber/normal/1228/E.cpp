#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;
ll bin_pow(ll a, ll p) {
  ll r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

ll ncr[300][300];
int main() {
  for (int n = 0; n < 300; n++) {
    ncr[n][0] = 1;
    for (int k = 1; k <= n; k++) {
      ncr[n][k] = ncr[n-1][k-1]+ncr[n-1][k];
      if (ncr[n][k] >= mod)
	ncr[n][k] -= mod;
    }
  }
  assert(ncr[4][2] = 6);
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  for (int a = 0; a <= n; a++) {
    for (int b = 0; b <= n; b++) {
      (ans += (a+b&1 ? -1 : 1)*bin_pow(k, a*b)*bin_pow(k-1, n*n-a*b) %mod * ncr[n][a] % mod * ncr[n][b]) %= mod;
    }
  }
  cout << (ans%mod+mod)%mod << endl;
}