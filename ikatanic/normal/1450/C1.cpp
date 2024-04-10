#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;
using i64 = int64_t;

bool have3(string s) {
  for (int i = 0; i + 2 < (int)s.size(); ++i) {
    if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) return true;
  }
  return false;
}

vector<string> solve(const vector<string> &a) {
  int n = a.size();
  int k = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] != '.') k++;
    }
  }

  for (int d = 0; d < 3; ++d) {
    auto b = a;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if ((i + j) % 3 != d || b[i][j] == '.') continue;

        char same = b[i][j];
        char diff = b[i][j] == 'X' ? 'O' : 'X';

        string horSame, verSame;
        string horDiff, verDiff;
        for (int k = -2; k <= 2; ++k) {
          if (i + k >= 0 && i + k < n) {
            verSame.push_back(b[i + k][j]);
            verDiff.push_back(k == 0 ? diff : b[i + k][j]);
          }
          if (j + k >= 0 && j + k < n) {
            horSame.push_back(b[i][j + k]);
            horDiff.push_back(k == 0 ? diff : b[i][j + k]);
          }
        }

        bool haveSame = have3(horSame) || have3(verSame);
        bool haveDiff = have3(horDiff) || have3(verDiff);

        if (!haveSame && !haveDiff) continue;
        if (!haveSame && haveDiff) continue;
        if (haveSame && !haveDiff) {
          b[i][j] = diff;
          cnt++;
          continue;
        }
      }
    }
    if (cnt * 3 <= k) return b;
  }
  assert(false);
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    auto b = solve(a);
    for (int i = 0; i < n; ++i) {
      cout << b[i] << '\n';
    }
  }

  return 0;
}