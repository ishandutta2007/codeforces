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
int t, n, a[101];
int main() {
  
  readInt(t);
  while(t--) {
    readInt(n);
    memset(a, 0, sizeof a);
    while(n--) {
      int x; readInt(x);
      a[x]++;
    }
    int ans = 0;
    for (int i = 0; i < 2; i++) {
      for (int x = 0; x <= 100; x++) {
        if (!a[x]) {
          ans += x;
          break;
        } else {
          a[x]--;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}