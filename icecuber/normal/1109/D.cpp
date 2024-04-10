#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;
ll fac[1000001], ifac[1000001];
ll npow[1000001], mpow[1000001];

int main() {
  fac[0] = fac[1] = ifac[0] = ifac[1] = npow[0] = mpow[0] = 1;
  ll n, m, A, B;
  cin >> n >> m >> A >> B;
  for (int i = 2; i <= m || i <= n; i++) {
    fac[i] = fac[i-1]*i%mod;
    int a = mod/i, b = mod%i;
    ifac[i] = -ifac[i-1]*a%mod *ifac[b]%mod *fac[b-1]%mod;
    assert((fac[i]*ifac[i]%mod+mod)%mod == 1);
  }
  for (int i = 1; i <= n; i++) {
    npow[i] = npow[i-1]*n%mod;
    mpow[i] = mpow[i-1]*m%mod;
  }
  ll ans = 0;
  for (ll k = 2; k <= n && k-1 <= m; k++) {
    (ans +=
     (k == n ? 1 : k * npow[n-k-1]) %mod *
     mpow[n-k] % mod *
     fac[m-1] % mod *
     ifac[m+1-k] % mod *
     fac[n-2] % mod *
     ifac[n-k] % mod *
     ifac[k-2]) %= mod;
  }
  cout << (ans%mod+mod)%mod << endl;
}