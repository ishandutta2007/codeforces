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
    int n, sol = 1e9;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    for (int l=1; l<=n; l++) {
      int q = accumulate(begin(a), begin(a) + l, 0);
      int c = 0, k = 1, s = 0;
      for (int j=0; j<n; j++) {
        s += a[j];
        if (s == q) {
          c++;
          s = 0;
        } else if (s > q) {
          k = 0;
        }
      }

      if (k && s == 0) {
        sol = min(sol, n-c);
      }
    }

    cout << sol << '\n';
  }
}