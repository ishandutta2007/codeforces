#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll x, ll n) {
  ll r = 0;
  for (int l = 0; l < 62; l++) {
    if (n>>l == x) {
      r += (n&(1ll<<l)-1)+1;
    } else if (n>>l > x) {
      r += 1ll<<l;
    }
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, need;
  cin >> n >> need;
  /*for (int i = 1; i <= n; i++) {
    cout << i << ' ' << f(i, n) << endl;
  }
  return 0;*/
  ll ans = 1;
  for (int k = 0; k < 2; k++) {
    ll pass = 0, fail = 1e18+1;
    while (fail-pass > 1) {
      ll mid = pass+fail>>1;
      ll x = mid*2+k;
      if (f(x,n)+!k*f(x+1,n) >= need) {
	pass = mid;
	ans = max(ans, x);
      } else fail = mid;
    }
  }
  cout << ans << endl;
}