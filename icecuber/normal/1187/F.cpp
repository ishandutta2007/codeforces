#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;

ll inv(ll a) {
  ll p = mod-2, r = 1;
  while (p) {
    if (p%2) r = r*a%mod;
    a = a*a%mod;
    p /= 2;
  }
  return r;
}

ll l[200001], r[200001], y[200001], z[200001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> l[i];
  for (int i = 1; i <= n; i++) cin >> r[i], r[i]++;
  ll ans = 0;
  ll y_sum = 0;
  for (int i = 1; i <= n; i++) {
    ll ma = min(r[i-1],r[i]), mi = max(l[i-1],l[i]);
    y[i] = (1-max(ma-mi,0ll)*inv((r[i]-l[i])*(r[i-1]-l[i-1])%mod)) % mod;
    (y_sum += y[i]) %= mod;
    (ans -= y[i]*y[i]) %= mod;
  }
  for (int i = 1; i <= n-1; i++) {
    ll ma = min({r[i-1],r[i],r[i+1]}), mi = max({l[i-1],l[i],l[i+1]});
    z[i] = (y[i]+y[i+1]-1+max(ma-mi,0ll)*inv((r[i]-l[i])*(r[i-1]-l[i-1])%mod*(r[i+1]-l[i+1])%mod)) % mod;
    (ans += 2*z[i]) %= mod;
    (ans -= 2*y[i]*y[i+1]) %= mod;
  }
  (ans += y_sum+y_sum*y_sum) %= mod;
  cout << (ans+mod)%mod << endl;
}