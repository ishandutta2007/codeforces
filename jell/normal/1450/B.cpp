#line 1 "codeforces-workspace/contest/1450/b/b.cpp"
/*
 * @file template.cpp
 * @brief Template
 */

#include <bits/extc++.h>

void solve() {
  // start here!
  using namespace std;
  int n, k;
  std::cin >> n >> k;
  vector<pair<int, int>> pos(n);
  for (auto &&[x, y] : pos) {
    std::cin >> x >> y;
  }
  for (auto &&[x, y] : pos) {
    bool fail = 0;
    for (auto &&[x2, y2] : pos) {
      if (k < abs(x - x2) + abs(y - y2)) {
        fail = 1;
      }
    }
    if (!fail) {
      cout << 1 << endl;
      return;
    }
  }
  cout << -1 << endl;
}

int main() {
  using namespace std;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}