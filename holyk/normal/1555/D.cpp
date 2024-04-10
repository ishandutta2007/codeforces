// Author:  HolyK
// Created: Fri Jul 30 23:13:38 2021
#include <bits/stdc++.h>
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = long long;
using PII = std::pair<int, int>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::string s;
  std::cin >> n >> m >> s;
  std::vector v {0, 1, 2};
  std::vector<std::string> vs;
  do {
    std::string w;
    for (int x : v) w += char(x + 'a');
    vs.push_back(w);
  } while (std::next_permutation(v.begin(), v.end()));
  std::vector<std::array<int, 6>> f(n);
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < 6; k++) {
      auto &c = vs[k];
      f[i][k] = i >= 3 ? f[i - 3][k] : 0;
      for (int j = 0; j <= i && j < 3; j++) {
        if (c[j] != s[i - j]) f[i][k]++;
      }
    }
  }
  while (m--) {
    int l, r;
    std::cin >> l >> r;
    l--, r--;
    int x = l, ans = 1e9;
    while (x % 3 != r % 3) x++;
    for (int k = 0; k < 6; k++) {
      auto &c = vs[k];
      int cnt = f[r][k] - f[x][k];
      
      for (int i = 0; i <= x - l; i++) cnt += c[i] != s[x - i];
      smin(ans, cnt);
    }
    std::cout << ans << "\n";
  }
  return 0;
}