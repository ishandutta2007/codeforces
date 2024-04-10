#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, mod;
  cin >> n >> mod;
  vector<ll> fac(n+1);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i-1]*i%mod;
  ll ans = 0;
  for (int k = 1; k <= n; k++) {
    (ans += fac[n-k+1] * (n-k+1) % mod * fac[k]) %= mod;
  }
  cout << ans << endl;
}