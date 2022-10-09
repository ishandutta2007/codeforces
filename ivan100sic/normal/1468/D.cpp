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
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int g = abs(a-b);
    int w = a < b ? a-1 : n-a;
    int tc = g + w;

    vector<int> e(m);
    for (int i=0; i<m; i++) cin >> e[i];
    sort(begin(e), end(e));

    int l = 1, r = m, o = 0;
    while (l <= r) {
      int mid = (l+r) / 2;

      bool ok = true;
      if (mid >= g) ok = false;

      for (int i=0; i<mid && ok; i++) {
        int te = e[mid-1-i] + i + 1;
        if (te > tc) {
          ok = false;
        }
      }

      if (ok) {
        o = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    cout << o << '\n';
  }
}