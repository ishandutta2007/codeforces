#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll l, r, m;
    cin >> l >> r >> m;
    for (ll a = l; a <= r; a++) {
      ll n = max(1ll, (m*2+a)/(a*2));
      ll bc = n*a-m;
      if (abs(bc) <= r-l) {
	ll b = max(-bc, 0ll)+l;
	ll c = max( bc, 0ll)+l;
	cout << a << ' ' << b << ' ' << c << endl;
	assert(n*a+b-c == m);
	break;
      }
    }
  }
}