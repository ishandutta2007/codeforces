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
    int n;
    cin >> n;
    vector<int> c(2*n), a, b;

    for (int i=0; i<n; i++) {
      int x;
      cin >> x;
      x--;
      c[x] = 1;
    }

    for (int i=0; i<2*n; i++) {
      (c[i] ? b : a).push_back(i);
    }

    int l=0, r=n, om=0, ov=0;
    // manji
    while (l <= r) {
      int m = (l+r) / 2;

      bool ok = 1;
      for (int i=0; i<m; i++) {
        if (a[i] > b[i+n-m]) {
          ok = 0;
        }
      }

      if (ok) {
        om = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    // veci
    l = 0, r = n;

    while (l <= r) {
      int m = (l+r) / 2;

      bool ok = 1;
      for (int i=0; i<m; i++) {
        if (b[i] > a[i+n-m]) {
          ok = 0;
        }
      }

      if (ok) {
        ov = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    int ans = 0;
    for (int i=0; i<=n; i++) {
      if (i <= om && n-i <= ov) {
        ans++;
      }
    }

    cout << ans << '\n';
  }
}