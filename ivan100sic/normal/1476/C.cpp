// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[100005], b[100005], c[100005];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> c[i];
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];

    bool lastflip = false;
    for (int i=1; i<=n; i++) {
      if (lastflip) {
        a[i] = c[i-1] + 1 - a[i];
        b[i] = c[i-1] + 1 - b[i];
      }

      if (a[i] > b[i]) {
        swap(a[i], b[i]);
        lastflip = true;
      } else {
        lastflip = false;
      }
    }

    ll sol = -1e18, conn = -1e18;

    for (int i=1; i<=n; i++) {
      if (i > 1) {
        conn += 2 + c[i-1] - 1 - b[i] + a[i];
      }

      if (a[i] < b[i]) {
        conn = max(conn, 2ll + b[i] - a[i]);
      } else if (i > 1) {
        conn = 2 + b[i] - a[i];
      }

      if (i > 1) {
        // cerr << "candidate " << i << ' ' << conn << ' ' << conn + c[i] - 1 << '\n';
        sol = max(sol, conn + c[i] - 1);
      }
    }

    cout << sol << '\n';
  }
}

// l ... r
// (2 + b[l+1] - a[l+1]) + (2 + c[l+1] - b[l+2] + a[l+2]) + ... + (2 + c[r-1] - b[r] + a[r]) + c[r]
// s.t.
// l < r
// a[i] < b[i] forall i, l+2 <= i <= r