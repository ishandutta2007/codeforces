#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
ll fac[6000], ifac[6000];

ll mypow(ll a, ll p) {
  if (p == -1) p = mod-2;
  ll r = 1;
  while (p) {
    if (p&1) r = (r*a)%mod;
    a = (a*a)%mod;
    p >>= 1;
  }
  return r;
}
ll inv(ll a) {return mypow(a,-1);}
ll ncr_mem[6000][101];
ll ncr(ll n, ll k) {
  if (k==n) return 1;
  if (n < k || k < 0) return 0;
  return ncr_mem[n][k];
}

inline ll f(ll s, ll m, ll n) {
  //if (n == 0) return !s;
  ll ans = 0;
  for (int k = 0; k <= n; k++)
    ans = (ans+(k%2?-1:1)*ncr(n,k)*ncr(s-k*m+n-1,n-1))%mod;
  return ans;
}

int main() {
  ifac[0] = fac[0] = 1;
  for (int i = 1; i < 6000; i++) {
    fac[i] = (fac[i-1]*i)%mod;
    ifac[i] = inv(fac[i]);
  }
  //cout << inv(fac[1000]*fac[2000]%mod) << ' ' << (ifac[1000]*ifac[2000])%mod << endl;

  for (int n = 0; n < 6000; n++)
    for (int k = 0; k < 101 && k <= n; k++)
      ncr_mem[n][k] = fac[n]*ifac[n-k]%mod*ifac[k]%mod;

  int p, s, r;
  cin >> p >> s >> r;
  ll ans = 0;
  for (int k = r; k <= s; k++) {
    for (int m = 1; m <= p; m++) {
      ans = (ans+f(s-m*k,k,p-m)*inv(m)%mod*ncr(p-1,m-1))%mod;
    }
  }
  //cout << ncr(s-r+p-1,p-1) << endl;
  ans = ans*inv(ncr(s-r+p-1,p-1))%mod;
  cout << (ans%mod+mod)%mod << endl;
}