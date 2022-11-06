#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
#include <functional>
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
int t, n;
std::vector<int> a, b;
int main() {
  readInt(t);
  while(t--) {
    readInt(n);
    a.clear(), b.clear();
    while(n--) {
      int x; readInt(x);
      if (x >= 0)
        a.push_back(x);
      else
        b.push_back(x);
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    std::sort(b.begin(), b.end());
    long long ans = -1e18;
    if (a.empty()) {
      ans = 1;
      for (int i = 1, r = b.size(); i <= 5; i++)
        ans *= b[r - i];
      printf("%lld\n", ans);
      continue;
    }
    for (int i = 0, j; i <= 5; i++) {
      j = 5 - i;
      if (i <= a.size() && j <= b.size()) {
        long long t = 1;
        for (int k = 0; k < i; k++) t *= a[k];
        for (int k = 0; k < j; k++) t *= b[k];
        smax(ans, t);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}