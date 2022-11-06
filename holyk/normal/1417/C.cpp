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

constexpr int N(3e5 + 5);

int n, pos[N];
std::pair<int, int> len[N];
int main() {
  int t; readInt(t);
  while(t--) {
    readInt(n);
    memset(len, 0, n + 1 << 3);
    memset(pos, 0, n + 1 << 2);
    for (int i = 1, x; i <= n; i++) {
      readInt(x);
      len[x].second = x;
      smax(len[x].first, i - pos[x]);
      pos[x] = i;
    }
    for (int i = 1; i <= n; i++) {
      if (len[i].second)
        smax(len[i].first, n + 1 - pos[i]);
      else
        len[i].first = n + 1;
      
    }
    std::sort(len + 1, len + 1 + n);
    int ans = n + 1;
    for (int i = 1, j = 1; i <= n; i++) {
      while (j <= n && len[j].first <= i) smin(ans, len[j++].second);
      printf("%d ", ans > n ? -1 : ans);
    }
    puts("");
  }
  return 0;
}