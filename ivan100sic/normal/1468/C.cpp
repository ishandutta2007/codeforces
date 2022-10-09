// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int q, idx = 0;
  set<tuple<int, int, int>> a, b;
  cin >> q;
  for (int i=0; i<q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      a.insert({i, x, ++idx});
      b.insert({-x, i, idx});
    } else if (t == 2) {
      auto [x, y, z] = *a.begin();
      a.erase(a.begin());
      b.erase({-y, x, z});
      cout << z << ' ';
    } else {
      auto [x, y, z] = *b.begin();
      b.erase(b.begin());
      a.erase({y, -x, z});
      cout << z << ' ';
    }
  }

  cout << '\n';
}