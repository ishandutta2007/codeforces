#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cout << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

using i64 = int64_t;

constexpr i64 inf = 2e18;

int main() {
  ios_base::sync_with_stdio(false);

  int n, m;
  i64 k;
  string s;
  cin >> n >> m >> k;
  cin >> s;

  vector<vector<int>> lcp(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      auto& l = lcp[i][j];
      while (i + l < n && j + l < n && s[i + l] == s[j + l]) l++;
    }
  }

  vector<pair<int, int>> strings;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; i + j <= n; ++j) {
      strings.emplace_back(i, j);
    }
  }

  auto cmp = [&](auto a, auto b) -> bool {
    auto l = lcp[a.first][b.first];
    if (l < a.second && l < b.second) return s[a.first + l] < s[b.first + l];
    return a.second < b.second;
  };

  sort(strings.begin(), strings.end(), cmp);

  vector<vector<i64>> f(n + 1, vector<i64>(m + 1, 0));
  auto count = [&](auto&& p) -> i64 {
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        f[i][j] = 0;
      }
    }

    f[0][0] = 1;
    for (int i = 0; i < n; ++i) {
      int k = 1;
      while (i + k <= n && cmp(make_pair(i, k), p)) k++;

      for (int j = 0; j < m; ++j) {
        if (j > 0 && i > 0) f[i][j] = min(inf, f[i][j] + f[i - 1][j]);
        if (i + k <= n) f[i + k][j + 1] = min(inf, f[i + k][j + 1] + f[i][j]);
      }
    }

    i64 ret = 0;
    for (int i = 0; i <= n; ++i) {
      ret = min(inf, ret + f[i][m]);
    }
    return ret;
  };

  int lo = 0, hi = strings.size() - 1;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (count(strings[mid]) >= k)
      lo = mid;
    else
      hi = mid - 1;
  }

  auto ans = strings[lo];
  cout << s.substr(ans.first, ans.second) << '\n';
  return 0;
}