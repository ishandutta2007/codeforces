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

inline void smax(int &x, int y) {
  if (y > x) x = y;
}
inline void smin(int &x, int y) {
  if (y < x) x = y;
}
constexpr int N(3e5 + 5);
int n, m, a[N], b[N], f[N], lGreater[N], rGreater[N], lLess[N], rLess[N];

namespace BIT {
int c[N];
inline void clear() { memset(c, 0, m + 1 << 2); }
inline void add(int p, int x) {
  for (; p <= m; p += p & -p) smax(c[p], x);
}
inline int ask(int p) {
  int ans = 0;
  for (; p; p -= p & -p) smax(ans, c[p]);
  return ans;
}
}
void init(int *l, int *r) {
  using namespace BIT;
  clear();
  for (int i = 1; i <= n; i++) {
    l[i] = ask(a[i]);
    add(a[i], i);
  }
  clear();
  for (int i = n; i; i--) {
    r[i] = n - ask(a[i]) + 1;
    add(a[i], n - i + 1);
  }
}
int main() {
  readInt(n);
  for (int i = 1; i <= n; i++)
    readInt(a[i]);
  for (int i = 1; i <= n; i++)
    b[i] = a[i];
  std::sort(b + 1, b + 1 + n);
  m = std::unique(b + 1, b + 1 + n) - b - 1;
  for (int i = 1; i <= n; i++)
    a[i] = std::lower_bound(b + 1, b + 1 + m, a[i]) - b;
  init(lLess, rLess);
  for (int i = 1; i <= n; i++)
    a[i] = m - a[i] + 1;
  init(lGreater, rGreater);
  memset(f, 0x3f, sizeof f);
  f[1] = 0;
  for (int i = 1; i <= n; i++) {
    smin(f[i], f[lLess[i]] + 1);
    smin(f[i], f[lGreater[i]] + 1);
    smin(f[rLess[i]], f[i] + 1);
    smin(f[rGreater[i]], f[i] + 1);
  }
  printf("%d\n", f[n]);
  return 0;
}