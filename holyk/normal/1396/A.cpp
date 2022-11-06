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

constexpr int N(1e5 + 5);
int n, a[N];
int main() {
  readInt(n);
  for (int i = 1; i <= n; i++)
    readInt(a[i]);
  if (n == 1) {
    printf("1 1\n%d\n1 1\n0\n1 1\n0", -a[1]);
    return 0;
  }
  printf("1 %d\n", n);
  for (int i = 1; i <= n; i++)
    printf("%lld ", -1LL * a[i] * n);
  printf("\n2 %d\n", n);
  for (int i = 2; i <= n; i++)
    printf("%lld ", 1LL * a[i] * (n - 1));
  printf("\n1 1\n%lld\n", 1LL * a[1] * (n - 1));
  return 0;
}