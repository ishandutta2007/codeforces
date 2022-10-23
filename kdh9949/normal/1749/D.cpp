#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  ll n, m;
  cin >> n >> m;

  const ll mod = 998244353;
  ll tot = 1, cur = 1, b = 1, ans = 0;
  for(ll i = 1; i <= n; ++i) {
    if(b != 0) {
      int prime = (i >= 2);
      for(ll j = 2; j * j <= i; ++j) if(i % j == 0) { prime = 0; break; }
      if(prime) b *= i;
      if(b > m) b = cur = 0;
      else cur = cur * (m / b % mod) % mod;
    }
    tot = tot * (m % mod) % mod;
    ans = (ans + tot - cur + mod) % mod;
  }
  
  cout << ans << '\n';
  return 0;
}