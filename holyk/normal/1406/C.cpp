#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
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

constexpr int N(1e5 + 5);
int n, m, rt, rt2, fa[N], siz[N];
std::vector<int> g[N];
void dfs(int x) {
  siz[x] = 1;
  int max = 0;
  for (int y : g[x])
    if (y != fa[x]) {
      fa[y] = x;
      dfs(y);
      siz[x] += siz[y];
      smax(max, siz[y]);
    }
  smax(max, n - siz[x]);
  if (smin(m, max))
    rt = x;
  else if (m == max)
    rt2 = x;
}

int main() {
  int t; readInt(t);
  while (t--) {
    readInt(n), m = n;
    for (int i = 1; i <= n; i++)
      g[i].clear(), fa[i] = 0;
    for (int i = 1, x, y; i < n; i++) {
      readInt(x, y);
      g[x].push_back(y), g[y].push_back(x);
    }
    
    dfs(1);
    if ((n & 1) || m != n / 2) {
      printf("1 %d\n1 %d\n", g[1][0], g[1][0]);
      continue;
    }
    std::swap(rt, rt2);
    for (int y : g[rt])
      if (y != rt2) {
        printf("%d %d\n", rt, y);
        rt = y;
        break;
      }
    printf("%d %d\n", rt, rt2);
  }
  return 0;
}