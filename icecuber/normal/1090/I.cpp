#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll b[20000001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, l, r, x, y, z;
    cin >> n >> l >> r >> x >> y >> z >> b[0] >> b[1];
    for (int i = 2; i < n; i++)
      b[i] = (b[i-2]*x+b[i-1]*y+z)&(1LL<<32)-1;

    ll ans = 5e18, mi = 5e18;
    for (int i = 0; i < n; i++) {
      ll a = b[i]%(r-l+1)+l;
      if (a >= 0 && mi < a)
	ans = min(ans, a*mi);
      mi = min(mi, a);
    }
    ll ma = -5e18;
    for (int i = n-1; i >= 0; i--) {
      ll a = b[i]%(r-l+1)+l;
      if (a < 0 && ma > a)
	ans = min(ans, a*ma);
      ma = max(ma, a);
    }
    if (ans == 5e18)
      cout << "IMPOSSIBLE" << endl;
    else
      cout << ans << '\n';
  }
}