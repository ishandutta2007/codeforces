#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;
ll fac[5001], ifac[5001], pow2[5001];

ll inv(ll a) {
  ll p = mod-2, r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k, l;
  cin >> n >> k >> l;
  fac[0] = ifac[0] = pow2[0] = 1;
  for (int i = 1; i <= 5000; i++) {
    fac[i] = fac[i-1]*i%mod;
    ifac[i] = inv(fac[i]);
    pow2[i] = pow2[i-1]*2%mod;
  }
  ll ans = 0;
  for (int i = k; i <= n; i++) {
    for (int s = i; s <= n; s++) {
      ans +=
	((s-i)%2 ? -1 : 1) * pow2[s] * fac[s]%mod * fac[s]%mod * fac[n]%mod *
	ifac[n-s]%mod * ifac[2*s+1]%mod * ifac[i]%mod * ifac[s-i]%mod;
      ans %= mod;
    }
  }
  cout << (ans*l%mod+mod)%mod << endl;
}