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

constexpr int N(2e5 + 5);
int main() {
  int t, n, k; readInt(t);
  while (t--) {
    readInt(n, k);
    std::vector<int> a(n);
    for (int &x : a) readInt(x);
    std::sort(a.begin(), a.end(), std::greater<int>());
    LL ans = a[0];
    for (int i = 1; i <= k && i < n; i++)
      ans += a[i];
    printf("%lld\n", ans);
  }
  return 0;
}