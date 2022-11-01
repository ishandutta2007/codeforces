#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<string> field(n);
  for (int i = 0; i < n; ++i) {
    cin >> field[i];
  }
  vector<string> ans(2 * n - 1, string(2 * n - 1, 'x'));
  ans[n - 1][n - 1] = 'o';
  for (int x1 = 0; x1 < n; ++x1) {
    for (int y1 = 0; y1 < n; ++y1) {
      if (field[x1][y1] != 'o')
        continue;
      for (int x2 = 0; x2 < n; ++x2) {
        for (int y2 = 0; y2 < n; ++y2) {
          if (field[x2][y2] != '.')
            continue;
          ans[x2 - x1 + n - 1][y2 - y1 + n - 1] = '.';
        }
      }
    }
  }
  vector<string> check_field(n, string(n, '.'));
  for (int x1 = 0; x1 < n; ++x1) {
    for (int y1 = 0; y1 < n; ++y1) {
      if (field[x1][y1] != 'o')
        continue;
      check_field[x1][y1] = 'o';
      for (int x2 = 0; x2 < n; ++x2) {
        for (int y2 = 0; y2 < n; ++y2) {
          if (check_field[x2][y2] != '.')
            continue;
          if (ans[x2 - x1 + n - 1][y2 - y1 + n - 1] == 'x') {
            check_field[x2][y2] = 'x';
          }
        }
      }
    }
  }
  if (check_field != field) {
    cout << "NO" << endl;
  }
  else {
    cout << "YES" << endl;
    for (const auto& str : ans) {
      cout << str << endl;
    }
  }
  return 0;
}