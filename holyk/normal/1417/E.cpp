#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iostream>

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
int n, m;

int son[N << 4][2];
long long ans, c[30][2];
std::vector<int> id[N << 4];
void ins(int x, int i) {
  int o = 1;
  for (int i = 29; i >= 0; i--) {
    int u = x >> i & 1;
    if (!son[o][u]) son[o][u] = ++m;
    o = son[o][u];
  }
  id[o].push_back(i);
}

void calc(int o, int d) {
  if (!o || d == 0) return;
  calc(son[o][0], d - 1);
  calc(son[o][1], d - 1);
  std::vector<int> &ls = id[son[o][0]], &rs = id[son[o][1]];
  int i = 0, j = 0;
  while(i < ls.size()) {
    while (j < rs.size() && rs[j] < ls[i])
      id[o].push_back(rs[j++]), c[d - 1][1] += i;
    id[o].push_back(ls[i++]);
    c[d - 1][0] += j;
  }
  while (j < rs.size())
    id[o].push_back(rs[j++]), c[d - 1][1] += i;
}
int main() {
  readInt(n);
  m = 1;
  for (int i = 1, x; i <= n; i++)
    readInt(x), ins(x, i);
  calc(1, 30);
  int x = 0;
  for (int i = 0; i <= 29; i++) {
    ans += std::min(c[i][0], c[i][1]);
    if (c[i][1] < c[i][0])
      x |= 1 << i;
  }
  printf("%lld %d\n", ans, x);
  return 0;
}