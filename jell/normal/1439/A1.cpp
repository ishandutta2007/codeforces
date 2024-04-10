#line 1 "codeforces-workspace\\contest\\1439\\a1\\a1.cpp"
#include <bits/extc++.h>

void _main() {
  using namespace std;

  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (auto &&e : s) {
    cin >> e;
  }

  vector<vector<int>> ops;

  if (n & 1) {
    auto &row = s.back();
    for (auto j = 0; j < m; ++j) {
      if (row[j] - '0') {
        vector ar = {n - 1, j, n - 2, j, n - 2, (j ^ 1) < m ? j ^ 1 : j - 1};
        ops.push_back(ar);
        for (auto i = 0; i < size(ar); i += 2) {
          s[ar[i]][ar[i + 1]] ^= 1;
        }
      }
    }
  }
  if (m & 1) {
    for (auto i = 0; i < n; ++i) {
      if (s[i].back() - '0') {
        vector ar = {i, m - 1, i, m - 2, i ^ 1, m - 2};
        ops.push_back(ar);
        for (auto i = 0; i < size(ar); i += 2) {
          s[ar[i]][ar[i + 1]] ^= 1;
        }
      }
    }
  }

  for (auto i = 0; i + 1 < n; i += 2) {
    for (auto j = 0; j + 1 < m; j += 2) {
      int cnt[2][2] = {};
      for (auto &&dx : {0, 1}) {
        for (auto &&dy : {0, 1}) {
          if (s[i + dx][j + dy] - '0') {
            cnt[dx ^ 1][dy] ^= 1, cnt[dx][dy ^ 1] ^= 1,
                cnt[dx ^ 1][dy ^ 1] ^= 1;
          }
        }
      }
      for (auto dx = 0; dx < 2; ++dx) {
        for (auto dy = 0; dy < 2; ++dy) {
          if (cnt[dx][dy]) {
            vector<int> ar;
            for (auto &&x : {0, 1}) {
              for (auto &&y : {0, 1}) {
                if (pair(x, y) != pair(dx, dy)) {
                  ar.emplace_back(x + i);
                  ar.emplace_back(y + j);
                }
              }
            }
            ops.push_back(ar);
            for (auto i = 0; i < size(ar); i += 2) {
              s[ar[i]][ar[i + 1]] ^= 1;
            }
          }
        }
      }
    }
  }

  for (auto &&r : s) {
    for (auto &&c : r) {
      assert(c == '0');
    }
  }

  assert(size(ops) <= n * m);
  cout << size(ops) << "\n";
  for (auto &&a : ops) {
    assert(size(a) == 6);
    for (auto &&e : a) {
      ++e;
      cout << e << " ";
    }
    cout << "\n";
  }
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    _main();
  }
}