#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;
const int nax = 1e6+10;
ll fac[nax], ifac[nax], inv[nax];
ll ncr(int n, int k) {
  if (n < 0 || k < 0 || k > n) return 0;
  return fac[n]*ifac[k]%mod *ifac[n-k]%mod;
}

int main() {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < nax; i++) {
    inv[i] = i == 1 ? 1 : mod-mod/i*inv[mod%i]%mod;
    fac[i] = fac[i-1]*i%mod;
    ifac[i] = ifac[i-1]*inv[i]%mod;
    assert(fac[i]*ifac[i]%mod == 1);
  }
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  int lp = 0, rp = count(s.begin(), s.end(), ')');
  int lq = 0, rq = count(s.begin(), s.end(), '?');

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    (ans += ncr(lq+rq, rq-lp+rp)*lp + ncr(lq+rq-1, rq-1-lp+rp)*lq) %= mod;
    if (s[i] == '(') lp++;
    else if (s[i] == ')') rp--;
    else if (s[i] == '?') lq++, rq--;
    else assert(0);
  }
  cout << ans << endl;
}