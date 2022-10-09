// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

void ans(bool x) {
  cout << (x ? "Yes\n" : "No\n");
  exit(0);
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  ll k, l, r, t, x, y;
  cin >> k >> l >> r >> t >> x >> y;

  if (x >= y) {
    if (k + y <= r) {
      k += y;
    }
    k -= x;
    if ((t-1.)*(x-y) > 4e18) ans(0);
    k -= (t-1)*(x-y);
    ans(k >= l);
  } else {
    set<ll> seen;
    seen.insert(k);
    while (t > 0) {
      ll g = (r-x-k) / (y-x);
      if (g > 0) {
        k += g*(y-x);
        t -= g;
      } else {
        g = (k-r+y-1) / x;
        if (g <= 0) g = 1;
        k -= g*x;
        t -= g;
      }

      if (k < l) ans(0);
      if (seen.count(k)) {
        ans(1);
      } else {
        seen.insert(k);
      }
    }
    ans(1);
  }
}