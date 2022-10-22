#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bin_pow(ll a, ll p, ll mod) {
  ll r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll x, n;
  cin >> x >> n;
  vector<ll> prime;
  for (ll i = 2; i*i <= x; i++) {
    if (x%i) continue;
    prime.push_back(i);
    while (x%i == 0) x /= i;
  }
  if (x > 1) prime.push_back(x);

  ll mod = 1e9+7;
  ll ans = 1;
  for (ll p : prime) {
    ll m = n;
    ll e = 0;
    while (m) {
      m /= p;
      e += m;
    }
    (ans *= bin_pow(p, e, mod)) %= mod;
  }
  cout << ans << endl;
}