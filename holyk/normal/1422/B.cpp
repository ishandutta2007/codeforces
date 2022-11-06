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

int n, m, a[102][102];
int main() {
  int t; readInt(t);
  while (t--) {
    readInt(n, m);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        readInt(a[i][j]);
    LL ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        std::vector<int> v { a[i][j], a[n - i + 1][j], a[i][m - j + 1], a[n - i + 1][m - j + 1] };
        std::sort(v.begin(), v.end());
        ans += abs(v[1] - a[i][j]);
      }
    std::cout << ans << "\n";
  }
  return 0;
}