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

constexpr int N(1e5 + 5);
int r, n, f[N], t[N], a[N], b[N];
int main() {
  readInt(r, n);
  r <<= 2;
  int ans = 0;
  a[0] = b[0] = 1;
  for (int i = 1; i <= n; i++) {
    readInt(t[i], a[i], b[i]);
    f[i] = -1e9;
    for (int j = std::max(0, i - r); j < i; j++)
      if (t[i] - t[j] >= abs(a[i] - a[j]) + abs(b[i] - b[j]))
        smax(f[i], f[j] + 1);
    smax(ans, f[i]);
  }
  std::cout << ans;
  
  return 0;
}