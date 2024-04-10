#line 1 "codeforces-workspace/contest/1450/c1/c1.cpp"
#include <bits/extc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<string> g(n);
  for (auto &&r : g) {
    cin >> r;
  }

  int cnt[3] = {};
  for (auto i = 0; i < n; ++i) {
    for (auto j = 0; j < n; ++j) {
      if (g[i][j] == 'X') {
        cnt[(i + j) % 3]++;
      }
    }
  }

  auto c = min_element(begin(cnt), end(cnt)) - cnt;
  for (auto i = 0; i < n; ++i) {
    for (auto j = 0; j < n; ++j) {
      if (g[i][j] == 'X' && (i + j) % 3 == c) {
        g[i][j] = 'O';
      }
    }
  }

  for (auto i = 0; i < n; ++i) {
    cout << g[i] << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}