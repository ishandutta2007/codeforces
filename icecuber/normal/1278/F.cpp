#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;

ll bin_pow(ll a, ll p) {
  ll r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

const int nax = 5001;
ll ifac[10000];
ll ncr[nax][nax];
ll powk[nax];

int main() {
  {
    ifac[0] = 1;
    for (int i = 1; i < 10000; i++)
      ifac[i] = ifac[i-1]*bin_pow(i, mod-2)%mod;

    for (int n = 0; n < nax; n++) {
      ncr[n][0] = 1;
      for (int k = 1; k <= n; k++) {
	ncr[n][k] = (ncr[n-1][k]+ncr[n-1][k-1])%mod;
      }
    }
    assert(ifac[4]*24%mod == 1);
    assert(ncr[6][2] == 15);
  }

  ios::sync_with_stdio(0); cin.tie(0);
  ll n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < nax; i++) {
    powk[i] = bin_pow(i, k);
  }
  ll ans = 0;
  for (int a = 1; a <= k && a <= n; a++) {
    ll v = bin_pow(m, mod-1-a);
    for (int i = 0; i < a; i++) {
      (v *= n-i) %= mod;
    }
    (v *= ifac[a]) %= mod;
    ll g = 0;
    for (int b = 0; b <= a; b++) {
      (g += ncr[a][b] * powk[a-b] * (b%2 ? -1 : 1)) %= mod;
    }
    (v *= g) %= mod;
    (ans += v) %= mod;
  }
  cout << (ans%mod+mod)%mod;
}