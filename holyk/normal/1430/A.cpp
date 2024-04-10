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

int main() {
  int t; readInt(t);
  while (t--) {
    int n; readInt(n);
    bool ok = 0;
    for (int i = 0; i <= 3 && i * 7 <= n; i++) {
      for (int j = 0; j <= 3 && j * 5 + i * 7 <= n; j++)
        if ((n - i * 7 - j * 5) % 3 == 0) {
          ok = 1;
          printf("%d %d %d\n", (n - i * 7 - j * 5) / 3, j, i);
          break;
        }
      if (ok) break;
    }
    if (!ok) puts("-1");
  }
  return 0;
}