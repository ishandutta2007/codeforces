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
    int n, m, x;
    cin >> n >> m >> x;
    set<pair<int, int>> s;
    for (int i=1; i<=m; i++) {
      s.insert({0, i});
    }

    cout << "YES\n";
    for (int i=0; i<n; i++) {
      int h;
      cin >> h;
      auto lo = *s.begin();
      s.erase(s.begin());
      cout << lo.second << " \n"[i == n-1];
      lo.first += h;
      s.insert(lo);
    }
  }
}