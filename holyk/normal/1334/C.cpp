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

constexpr int N(3e5 + 5);

int main() {
  int t, n; readInt(t);
  while (t--) {
    readInt(n);
    std::vector<LL> a(n), b(n);
    for (int i = 0; i < n; i++)
      readInt(a[i], b[i]);
    LL ans = std::min(a[0], b[n - 1]);
    for (int i = 1; i < n; i++) {
      smin(ans, std::min(a[i], b[i - 1]));
      a[i] -= b[i - 1];
      if (a[i] < 0) a[i] = 0;
    };
    a[0] -= b[n - 1];
    if (a[0] < 0) a[0] = 0;
    ans = std::accumulate(a.begin(), a.end(), ans);
    printf("%lld\n", ans);
  }
  return 0;
}