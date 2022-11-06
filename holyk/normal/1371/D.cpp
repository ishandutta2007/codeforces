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
int main() {
  int t, n, k; readInt(t);
  while (t--) {
    readInt(n, k);
    std::vector<std::vector<int>> v(n, std::vector<int>(n, 0));
    std::vector<int> r(n), c(n);
    auto fl = [&](int x, int y) {
      x %= n, y %= n;
      while (v[x][y]) x = (x + n - 1) % n;
      v[x][y] = 1;
      r[x]++, c[y]++;
    };
    for (int i = 1, x = 0, y = 0; i <= k; i++, x++, y++)
      fl(x, y);
    int maxr, minr, maxc, minc;
    maxr = *std::max_element(r.begin(), r.end());
    minr = *std::min_element(r.begin(), r.end());
    maxc = *std::max_element(c.begin(), c.end());
    minc = *std::min_element(c.begin(), c.end());
    
    auto sqr = [](int x) {
      return x * x;
    };
    printf("%d\n", sqr(maxr - minr) + sqr(maxc - minc));
    for (int i = 0; i < n; i++, puts(""))
      for (auto x : v[i])
        printf("%d", x);
  }
  return 0;
}