#include <cstdio>
#include <cctype>
#include <cstring>
#include <set>
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

typedef long long LL;
constexpr int N(1e5 + 5);
int n;
LL a[N], s;
void modify(int p, int x) {
  if (p == 1) {
    a[p] += x;
    s += x;
    return;
  }
  if (a[p] > 0) s -= a[p];
  a[p] += x;
  if (a[p] > 0) s += a[p];
}
int main() {
  readInt(n);
  for (int i = 1; i <= n; i++)
    readInt(a[i]);
  for (int i = n; i; i--)
    a[i] -= a[i - 1];
  s = a[1];
  for (int i = 2; i <= n; i++)
    if (a[i] > 0) s += a[i];
  printf("%lld\n", s + 1 >> 1);
  int q;
  readInt(q);
  while(q--) {
    int l, r, x;
    readInt(l, r, x);
    modify(l, x);
    if (r < n) modify(r + 1, -x);
    printf("%lld\n", s + 1 >> 1);
  }
  return 0;
}