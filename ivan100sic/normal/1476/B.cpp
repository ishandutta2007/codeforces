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
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n);
    for (int i=0; i<n; i++) {
      cin >> p[i];
    }

    ll l = 0, r = 1e12, o = 1e13;
    while (l <= r) {
      bool ok = 1;
      ll m = (l+r) / 2;
      ll t = p[0] + m;
      for (int i=1; i<n; i++) {
        if (p[i] * 100 > k * t) {
          ok = 0;
          break;
        }
        t += p[i];
      }

      if (ok) {
        o = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    cout << o << '\n';
  }
}