#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5+10;
ll mod = 1e9+7;
ll inv[nax], fac[nax], ifac[nax];

ll ncr(int n, int k) {
  if (n < 0 || k < 0 || k > n) return 0;
  return fac[n]*ifac[k]%mod*ifac[n-k]%mod;
}

//sum_{i<=k} ncr(n,i) * 0.5^n
ll ncr_sum1(int n, int k) {
  ll ans = 0;
  for (int i = 0; i <= k; i++)
    (ans += ncr(n,i)) %= mod;
  for (int i = 0; i < n; i++)
    ans = ans*((mod+1)/2)%mod;
  return ans;
}

ll last_n = 0, last_k = 0, last_ans = 1, pow_half = 1;
ll ncr_sum2(int n, int k) {
  assert(k >= 0 && k <= n);
  assert(last_n <= n);
  while (last_n < n) {
    (pow_half *= (mod+1>>1)) %= mod;
    (last_ans -= ncr(last_n,last_k)*pow_half) %= mod;
    last_n++;
  }
  while (last_k < k) {
    last_k++;
    (last_ans += ncr(last_n,last_k)*pow_half) %= mod;
  }
  while (last_k > k) {
    (last_ans -= ncr(last_n,last_k)*pow_half) %= mod;
    last_k--;
  }
  //assert((last_ans+mod)%mod == ncr_sum1(last_n,last_k));
  return last_ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  ll T;
  cin >> n >> T;
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < nax; i++) {
    inv[i] = i==1 ? 1 : mod-mod/i*inv[mod%i]%mod;
    fac[i] = fac[i-1]*i%mod;
    ifac[i] = ifac[i-1]*inv[i]%mod;
    assert(fac[i]*ifac[i]%mod == 1);
  }
  ll mi = 0;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ll t;
    cin >> t;
    mi += t;
    ll slack = T-mi;
    if (slack < 0) break;
    if (slack > i) {
      (ans += 1) %= mod;
    } else {
      ll prob = ncr_sum2(i, slack);
      (ans += prob) %= mod;
    }
  }
  cout << (ans+mod)%mod << endl;
}