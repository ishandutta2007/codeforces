// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;

    if (x > y) swap(x, y);
    if (a > b) swap(a, b);

    if (a == b) {
      cout << min(x, y) / a << '\n';
      continue;
    }

    ll t = (a*y - b*x) / (a*a - b*b);
    t = max(t, 0ll);
    t = min({t, x, y});

    ll sol = 0;

    for (ll z=max(0ll, t-8); z<=t+8; z++) {
      ll xx = x - z*(a+b);
      ll yy = y - z*(a+b);
      if (xx >= 0 && yy >= 0) {
        // cerr << "rem " << xx << ' ' << yy << '\n';
        sol = max(sol, 2*z + min(xx / a, yy / b));
      }
    }

    cout << sol << '\n';
  }
}