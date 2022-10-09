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
    vector<pair<int, int>> a;
    vector<int> l, r;
    for (int i=0; i<n; i++) {
      int x, y;
      cin >> x >> y;
      a.emplace_back(x, y);
      l.emplace_back(x);
      r.emplace_back(y);
    }

    sort(begin(l), end(l));
    sort(begin(r), end(r));

    int sol = n;

    for (auto [u, v] : a) {
      int f1 = lower_bound(begin(r), end(r), u) - begin(r);
      int f2 = end(l) - upper_bound(begin(l), end(l), v);

      sol = min(sol, f1+f2);
    }

    cout << sol << '\n';
  }
}