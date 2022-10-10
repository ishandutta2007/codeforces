// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct dsu {
  vector<int> p;
  int cc;

  dsu(int n) : p(n), cc(n) {
    iota(begin(p), end(p), 0);
  }

  int e(int x) {
    if (x == p[x]) return x;
    return p[x] = e(p[x]);
  }

  void spoji(int x, int y) {
    x = e(x);
    y = e(y);
    if (x == y) return;
    cc--;
    p[x] = y;
  }
};

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    vector<tuple<int, int, int>> a;
    cin >> n >> m >> k;
    for (int i=0; i<m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      x--, y--;
      a.emplace_back(z, x, y);
    }

    ll sol = 1e18;

    sort(begin(a), end(a));
    dsu e(n);

    // svi <= k, odnazad
    int hi = -1;
    for (int i=m-1; i>=0; i--) {
      auto [z, x, y] = a[i];
      if (z <= k) {
        hi = max(hi, z);
        e.spoji(x, y);
      }
    }

    if (e.cc == 1) {
      sol = min(sol, (ll)k - hi);
    }

    ll cost = 0;
    // sad dodajes >k dok se ne poveze
    for (int i=0; i<m; i++) {
      auto [z, x, y] = a[i];

      if (e.cc == 1 && z > k && cost == 0) {
        sol = min(sol, (ll)z - k);
      }

      if (z > k && e.e(x) != e.e(y)) {
        cost += z - k;
        e.spoji(x, y);
        if (e.cc == 1) {
          sol = min(sol, cost);
        }
      }
    }

    cout << sol << '\n';
  }
}