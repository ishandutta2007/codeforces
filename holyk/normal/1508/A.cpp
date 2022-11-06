#include <bits/stdc++.h>
#define perr(a...) fprintf(stderr, a)
#define dbg(a...) perr("\033[32;1m"), perr(a), perr("\033[0m")
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
  int t;
  std::cin >> t;
  while (t--) []() {
    int n;
    std::cin >> n;
    std::string s[3];
    for (auto &c : s) std::cin >> c;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < i; j++) {
        int cnt = 0;
        for (int k = 0; k < 2 * n; k++) if (s[i][k] == s[j][k]) cnt++;
        if (cnt < n) continue;
        std::string ans;
        for (int k = 0; k < 2 * n; k++) {
          ans += s[i][k];
          if (s[i][k] != s[j][k]) ans += s[j][k];
        }
        std::cout << ans << "\n";
        return;
      }
    std::vector<int> v[2];
    for (int i = 0; i < 3; i++) {
      int cnt = 0;
      for (char c : s[i]) cnt += c == '1';
      v[cnt >= n].push_back(i);
    }
    for (int p = 0; p < 2; p++) {
      if (v[p].size() < 2) continue;
      int i = v[p][0], j = v[p][1];
      std::string ans;
      int u = 0;
      for (int k = 0; k < 2 * n; k++) {
        if (s[i][k] == '0' + p) {
          while (u < 2 * n && s[i][k] != s[j][u]) ans += s[j][u++];
          u++;
        }
        ans += s[i][k];
      }
      while (u < 2 * n) ans += s[j][u++];
      std::cout << ans << "\n";
      return;
    }
  }();
  return 0;
}