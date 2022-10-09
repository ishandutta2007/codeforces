// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));
  cout << setprecision(14) << fixed;

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), ainv(n+1);
    for (int i=1; i<=n; i++) {
      cin >> a[i];
      ainv[a[i]] = i;
    }

    int crit = 1;
    for (int i=2; i<=n; i++) {
      if (ainv[i] != i) {
        crit = i;
      }
    }

    double z = 1;

    while (m--) {
      int r;
      double p;
      cin >> r >> p;
      if (r >= crit) {
        z *= 1-p;
      }
    }

    if (crit == 1) {
      z = 0;
    }

    cout << 1-z << '\n';
  }
}