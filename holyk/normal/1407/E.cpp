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

constexpr int N(5e5 + 5);
int n, m, f[2][N], d[N], q[N];
std::vector<int> g[2][N];

int main() {
  readInt(n, m);
  for (int i = 1, x, y, z; i <= m; i++) {
    readInt(x, y, z);
    g[z][y].push_back(x);
  }
  memset(d, 0x3f, sizeof d);
  memset(f, 0x3f, sizeof f);
  int l, r;
  q[l = r = 1] = n;
  d[n] = f[0][n] = f[1][n] = 0;
  while (l <= r) {
    const int &x = q[l++];
    for (int i = 0; i < 2; i++)
      for (int y : g[i][x]) {
        if (f[i][y] > 1e9)
          f[i][y] = d[x] + 1;
        if (smin(d[y], std::max(f[0][y], f[1][y])))
          q[++r] = y;
      }
  }
  printf("%d\n", d[1] > 1e9 ? -1 : d[1]);
  for (int i = 1; i <= n; i++)
    printf("%d", f[0][i] > f[1][i] ? 0 : 1);
  return 0;
}