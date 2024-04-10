#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;
ll f(ll n) {
  ll step = 1;
  ll side = 0;
  ll base[2] = {1,2};
  ll ans = 0;
  while (n) {
    step = min(n, step);
    ans += (base[side]+step-1)%mod*(step%mod);
    ans %= mod;
    (base[side] += step*2) %= mod;
    n -= step;
    step *= 2;
    side ^= 1;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll l, r;
  cin >> l >> r;
  cout << ((f(r)-f(l-1))%mod+mod)%mod << endl;
}