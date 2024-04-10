#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;

ll bin_pow(ll a, ll p) {
  p = (p%(mod-1)+mod-1)%(mod-1);
  ll r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

const int nax = 5e5;
ll fac[nax], ifac[nax], inv[nax];
ll ncr(int n, int k) {
  if (n < 0 || k < 0 || k > n) return 0;
  return fac[n]*ifac[k]%mod*ifac[n-k]%mod;
}
//ll ncr[2001][2001];

ll slowF(ll B, ll x, ll k) {
  assert(0);
  ll F = 0;
  for (int a = 0; a < x; a++) {
    (F += bin_pow(k-2, B-a)%mod*ncr(B, a)%mod) %= mod;
  }
  return F;
}

int main() {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < nax; i++) {
    inv[i] = i==1 ? 1 : mod-mod/i*inv[mod%i]%mod;
    fac[i] = i*fac[i-1]%mod;
    ifac[i] = inv[i]*ifac[i-1]%mod;
    assert(fac[i]*ifac[i]%mod == 1);
  }
  /*for (int n = 0; n < 2001; n++) {
    ncr[n][0] = 1;
    for (int k = 1; k <= n; k++) {
      ncr[n][k] = ncr[n-1][k-1]+ncr[n-1][k];
      if (ncr[n][k] >= mod)
	ncr[n][k] -= mod;
    }
  }
  assert(ncr[6][2] == 15);*/
  assert(ncr(6, 2) == 15);
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; i++)
    cin >> h[i];
  int d = 0;
  ll keq = 1;
  for (int i = 0; i < n; i++) {
    if (h[i] != h[(i+1)%n]) {
      d++;
    } else {
      keq = keq*k%mod;
    }
  }

  if (k == 1) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 0;
  int x0 = 0;
  int B0 = 0;
  ll f = 0;
  for (int b = d; b >= 0; b--) {
    int x = min(b, d-b+1);
    int B = d-b;
    while (x0 < x) {
      (f += bin_pow(k-2, B0-x0)*ncr(B0, x0)%mod) %= mod;
      x0++;
    }
    while (x0 > x) {
      x0--;
      (f -= bin_pow(k-2, B0-x0)*ncr(B0, x0)) %= mod;
    }
    while (B0 < B) {
      ll f0 = f;
      (f -= bin_pow(k-2, B0-(x0-1))*ncr(B0, x0-1)) %= mod;
      f = (f0*(k-2)+f)%mod;
      B0++;
    }
    assert(B == B0);
    assert(x == x0);
    /*assert(slowF(B0,x0,k) == (f+mod)%mod);
    f = slowF(B,x,k);
    x0 = x;
    B0 = B;*/
    (ans += keq*ncr(d, b)%mod * f) %= mod;
  }
  cout << (ans%mod+mod)%mod << endl;
}