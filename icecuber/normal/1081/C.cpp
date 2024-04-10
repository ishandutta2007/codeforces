#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;
ll fac(ll n) {
  return n <= 1 ? 1 : n*fac(n-1)%mod;
}
ll inv(ll a) {
  ll p = mod-2, r = 1;
  while (p) {
    if (p&1) r = (r*a)%mod;
    a = (a*a)%mod;
    p >>= 1;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, m, k;
  cin >> n >> m >> k;
  ll ans = m;
  for (int i = 0; i < k; i++)
    ans = ans*(m-1)%mod;
  ans = ans*fac(n-1)%mod*inv(fac(n-1-k)*fac(k)%mod)%mod;
  cout << ans << endl;
}