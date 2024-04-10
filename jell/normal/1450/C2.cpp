#line 1 "codeforces-workspace/contest/1450/c2/c2.cpp"
#include <bits/extc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<string> g(n);
  for (auto &&r : g) {
    cin >> r;
  }

  int cnt[2][3] = {};
  int tot = 0;
  const string ox = "OX";
  for (auto i = 0; i < n; ++i) {
    for (auto j = 0; j < n; ++j) {
      if (g[i][j] != '.') {
        cnt[g[i][j] == 'X'][(i + j) % 3]++;
        tot++;
      }
    }
  }

  bool suc = false;
  for (auto i{0}; i < 3 && !suc; i++)
    for (auto j{0}; j < 3; j++) {
      if (i == j) continue;
      if ((cnt[0][i] + cnt[1][j]) * 3 > tot) continue;
      const int a[] = {i, j};
      for (auto x = 0; x < n; ++x) {
        for (auto y = 0; y < n; ++y) {
          if (g[x][y] != '.') {
            for (auto k : {0, 1}) {
              if (g[x][y] == ox[k] && a[k] == (x + y) % 3) {
                g[x][y] = ox[k ^ 1];
              }
            }
          }
        }
      }
      suc = 1;
      break;
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