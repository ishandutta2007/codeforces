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
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<ll> b(n);
    ll x = -4e18, y = 0;
    for (int i=0; i<n; i++) {
      b[i] = x;
      cin >> a[i];
      y += a[i];
      x = max(x, y);
    }

    auto w = [&](ll k) {
      if (k < n) {
        return b[k];
      }

      ll q = k / n;
      ll r = k % n;

      if (y <= 0) {
        return b[n-1];
      } else {
        ld w1 = 1.0 * y * (q-1) + x;
        ld w2 = 1.0 * y * q + b[r];

        w2 = max(w1, w2);
        if (w2 > 8e18) {
          return ll(8e18);
        }

        return max(y * (q-1) + x, y * q + b[r]);
      }
    };

    while (m--) {
      int x;
      cin >> x;
      ll l = 0, r = 4e18, o = -1;
      while (l <= r) {
        ll m = (l+r) / 2;
        if (w(m) >= x) {
          o = m;
          r = m - 1;
        } else {
          l = m + 1;
        }
      }

      if (o == -1) {
        cout << "-1 ";
      } else {
        cout << o - 1 << ' ';
      }
    }

    cout << '\n';
  }
}