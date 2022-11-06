#include <bits/stdc++.h>

template <class T>
inline void readInt(T &w) {
  char c, p = 0;
  while (!isdigit(c = getchar())) p = c == '-';
  for (w = c & 15; isdigit(c = getchar()); w = w * 10 + (c & 15));
  if (p) w = -w;
}
template <class T, class... Args>
inline void readInt(T &w, Args &... args) { readInt(w), readInt(args...); }
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}
typedef long long LL;
typedef std::pair<int, int> PII;

int n, m;
std::vector<PII> a[10], b[10];
int main() {
  readInt(n, m);
  for (int i = 1; i <= n; i++) {
    std::vector<int> c(10, 0), d(10, 0);
    for (int j = 1, x; j <= m; j++) {
      readInt(x);
      for (int k = 0; k < 10; k ++)
        if (x >> k & 1) c[k] = j;
        else d[k] = j;
    }
    for (int k = 0; k < 10; k++) {
      if (c[k]) {
        if (d[k]) b[k].push_back({i, d[k]});
        a[k].push_back({i, c[k]});
      }
    }
  }
  for (int k = 0; k < 10; k++) {
    if (a[k].size() & 1 ^ 1 && !b[k].size()) continue;
    puts("TAK");
    std::vector<int> ans(n, 1);
    for (auto [i, j] : a[k]) {
      ans[i - 1] = j;
    }
    if (a[k].size() & 1 ^ 1) {
      auto [i, j] = b[k][0];
      ans[i - 1] = j;
    }
    for (int j : ans) printf("%d ", j);
    return 0;
  }
  puts("NIE");
  return 0;
}