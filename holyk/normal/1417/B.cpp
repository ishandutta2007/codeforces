#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

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
constexpr int N(1e5 + 5);
int n, k, c[N], m, ans[N];
int main() {
  int t; readInt(t);
  while (t--) {
    readInt(n, k); 
    m = 0;
    for (int i = 1; i <= n; i++) {
      int x; readInt(x);
      x <<= 1;
      if (x != k) {
        ans[i] = x < k;
      } else {
        c[++m] = i;
        ans[i] = 1;
      }
    }
    k = m >> 1;
    for (int i = 1; i <= k; i++)
      ans[c[i]] = 0;
    for (int i = 1; i <= n; i++)
      printf("%d ", ans[i]);
    puts("");
   }
  return 0;
}