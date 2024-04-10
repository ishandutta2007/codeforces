#include <algorithm>
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

int c[26][26], d[26];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k;
  std::cin >> n >> k;
  std::string s = "a";

  int cnt = 0;
  while (s.length() < n) {
    int x = s.back() - 'a';
    char y = 'a';
    PII best = {c[x][0], d[0]};
    for (int i = 1; i < k; i++) if (smin(best, PII(c[x][i], d[i]))) y = i + 'a';
    s += y;
    ++c[x][s.back() - 'a'];
    d[x] = *std::min_element(c[x], c[x] + k);
  }
  std::cout << s.substr(0, n) << "\n";
  return 0;
}