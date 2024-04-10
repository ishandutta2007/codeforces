#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 4e3+10;
ll fac[nax], ifac[nax], inv[nax];
ll mod = 998244853;

ll ncr(int n, int k) {
  if (n < 0 || k < 0 || k > n) return 0;
  return fac[n]*ifac[k]%mod*ifac[n-k]%mod;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < nax; i++) {
    inv[i] = i == 1 ? 1 : mod-mod/i*inv[mod%i]%mod;
    fac[i] = fac[i-1]*i%mod;
    ifac[i] = ifac[i-1]*inv[i]%mod;
    assert(fac[i]*ifac[i]%mod == 1);
  }
  int n, m;
  cin >> n >> m;
  ll ans = 0;
  for (int k = 1; k <= n+m; k++) {
    int a = n-k, b = m+k;
    if (n-m >= k) a = n, b = m;
    (ans += ncr(a+b,a)) %= mod;
  }
  cout << ans << endl;
}