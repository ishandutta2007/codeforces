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
    vector<int> a(n), b, c;
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }

    for (int i=0; i<n; i++) {
      int x;
      cin >> x;
      if (x == 1) {
        b.push_back(a[i]);
      } else {
        c.push_back(a[i]);
      }
    }

    sort(begin(b), end(b), greater<int>());
    sort(begin(c), end(c), greater<int>());

    int nb = b.size(), nc = c.size();

    int s=0, l=0;
    while (s < m && l < nc) {
      s += c[l++];
    }

    int sol = 1e9;

    if (s >= m) {
      sol = 2*l;
    }

    for (int i=1; i<=nb; i++) {
      s += b[i-1];
      while (l > 0 && s-c[l-1] >= m) {
        s -= c[--l];
      }
      if (s >= m) {
        sol = min(sol, 2*l + i);
      }
    }

    if (sol > 5e8) sol = -1;

    cout << sol << '\n';
  }
}