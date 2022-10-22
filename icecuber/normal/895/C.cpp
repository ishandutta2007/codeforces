#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 71;
int primes = 0;
int isprime[nax], prime[nax];

ll mod = 1e9+7;
const int fnax = 1e5+10;
ll fac[fnax], ifac[fnax], inv[fnax];
ll ncr(ll n, ll k) {
  if (n < 0 || k < 0 || k > n) return 0;
  return fac[n]*ifac[k]%mod*ifac[n-k]%mod;
}
ll ncr_even(ll n) {
  ll ans = 0;
  for (int k = 0; k <= n; k += 2) {
    (ans += ncr(n,k)) %= mod;
  }
  return ans;
}
ll ncr_odd(ll n) {
  ll ans = 0;
  for (int k = 1; k <= n; k += 2) {
    (ans += ncr(n,k)) %= mod;
  }
  return ans;
}

int mask[nax];
int main() {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < fnax; i++) {
    inv[i] = i == 1 ? 1 : mod-mod/i*inv[mod%i]%mod;
    fac[i] = fac[i-1]*i%mod;
    ifac[i] = ifac[i-1]*inv[i]%mod;
    assert(fac[i]*ifac[i]%mod == 1);
  }

  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 2; i < nax; i++) isprime[i] = 1;
  for (int i = 2; i < nax; i++) {
    if (!isprime[i]) continue;
    prime[primes++] = i;
    for (int j = i*2; j < nax; j += i)
      isprime[j] = 0;
  }

  for (int i = 1; i < nax; i++) {
    int cp = i;
    for (int j = 0; j < primes; j++) {
      while (cp%prime[j]==0) {
	mask[i] ^= 1<<j;
	cp /= prime[j];
      }
    }
  }

  int n;
  cin >> n;
  vector<int> count(nax, 0);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    count[a]++;
  }

  vector<ll> dp(1<<primes,0);
  dp[0] = 1;
  for (int a = 1; a < nax; a++) {
    vector<ll> ndp(1<<primes,0);
    ll even = ncr_even(count[a]);
    ll odd = ncr_odd(count[a]);
    for (int j = 0; j < 1<<primes; j++) {
      ndp[j] = (dp[j]*even+dp[j^mask[a]]*odd)%mod;
    }
    swap(ndp,dp);
  }
  cout << ((dp[0]-1)%mod+mod)%mod << endl;
}