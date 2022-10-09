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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) {
      int x;
      cin >> x;
      (i < l ? a : b)[x-1]++;
    }

    int z = 0, d = r-l, q = 0;
    for (int i=0; i<n; i++) {
      int k = min(a[i], b[i]);
      a[i] -= k;
      b[i] -= k;
      if (d > 0 && b[i] > 0) {
        k = min(d / 2, b[i] / 2);
        z += k;
        d -= 2*k;
        b[i] -= 2*k;
      } else if (d < 0 && a[i] > 0) {
        k = min(-d / 2, a[i] / 2);
        z += k;
        d += 2*k;
        a[i] -= 2*k;
      }

      q += a[i] + b[i];
    }

    cout << z + q/2 + abs(d)/2 << '\n';
  }
}