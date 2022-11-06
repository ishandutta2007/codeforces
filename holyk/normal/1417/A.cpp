#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

namespace FastIn {

template <class T>
inline void readInt(T &w) {
  char c, p = 0;
  while (!isdigit(c = getchar())) p = c == '-';
  for (w = c & 15; isdigit(c = getchar()); w = w * 10 + (c & 15));
  if (p) w = -w;
}
template <class T, class... Args>
inline void readInt(T &w, Args &... args) { readInt(w), readInt(args...); }
}  // namespace FastIn
using namespace FastIn;
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

int n, k, a[1005];
int main() {
  int t; readInt(t);
  while(t--) {
    readInt(n, k);
    for (int i = 1; i <= n; i++)
      readInt(a[i]);
    std::sort(a + 1, a + 1 + n);
    int ans = 0;
    for (int i = 2; i <= n; i++)
      ans += (k - a[i]) / a[1];
    printf("%d\n", ans);
  }
  return 0;
}