#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;
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
ll inv(ll a) {return bin_pow(a, mod-2);}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  /*for (int a = 1; a < n; a++)
    for (int b = 1; b < n; b++)
    (ans += bin_pow(k, max(__gcd(a,b), (a+b)-n))) %= mod;*/

  vector<ll> kpow = {bin_pow(k,-n)};
  for (int i = 1; i < n*2; i++)
    kpow.push_back(kpow.back()*k%mod);
  vector<int> mu(n,1),isprime(n,1);
  for (ll i = 2; i < n; i++) {
    if (!isprime[i]) continue;
    for (ll j = 0; j < n; j += i) mu[j] *= -1, isprime[j] = 0;
    for (ll j = 0; j < n; j += i*i) mu[j] = 0;
  }

  for (int s = 2; s < n*2; s++) {
    (ans += kpow[s]*min(s-1, n*2-s-1)) %= mod;
  }

  for (int g = 1; g < n; g++) {
    for (int d = 1; d <= n/(2*g)+1; d++) {
      for (int s = 2; s <= (n+g-1)/(g*d); s++) {
	(ans += mu[d]*(kpow[g+n]-kpow[d*g*s])*(s-1)) %= mod;
      }
    }
  }
  cout << (ans*bin_pow(k, mod-1-n)%mod+mod)%mod << endl;
}