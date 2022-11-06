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
  int n; readInt(n);
  std::vector<int> p(n + 1), s(n + 1), v(n + 1, 1e9), sz(n + 1);
  LL ans = 0;
  for (int i = 2; i <= n; i++)
    readInt(p[i]), sz[p[i]]++;
  for (int i = 1, x, a; i <= n; i++) {
    readInt(x);
    if (~x) a = x - s[p[i]];
    else a = 0, x = s[p[i]];
    smin(v[p[i]], a);
    s[i] = x;
    if (a < 0) return puts("-1"), 0;
    ans += a;
  }
  for (int i = 1; i <= n; i++)
    ans -= 1LL * v[i] * std::max(0, sz[i] - 1);
  std::cout << ans;
  return 0;
}