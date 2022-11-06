// Author:  HolyK
// Created: Fri Jul 30 23:02:22 2021
#include <bits/stdc++.h>
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(1e6 + 5);
#define ls o << 1
#define rs o << 1 | 1
inline char gc() {
  static constexpr int BufferSize = 1 << 22 | 5;
  static char buf[BufferSize], *p, *q;
  static std::streambuf *i = std::cin.rdbuf();
  return p == q ? p = buf, q = p + i->sgetn(p, BufferSize), p == q ? EOF : *p++ : *p++;
}
struct Reader {
  template <class T>
  Reader &operator>>(T &w) {
    char c, p = 0;
    for (; !std::isdigit(c = gc());) if (c == '-') p = 1;
    for (w = c & 15; std::isdigit(c = gc()); w = w * 10 + (c & 15)) ;
    if (p) w = -w;
    return *this;
  }
} cin;

int min[N << 2], add[N << 2], tg[N << 2];
void pushup(int o) {
  min[o] = std::min(min[ls], min[rs]) + add[o];
}
void update(int o, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) {
    min[o] += z;
    add[o] += z;
    return;
  }
  if (tg[o]) {
    tg[ls] = 1;
    tg[rs] = 1;
    min[ls] = add[ls] = min[rs] = add[rs] = 0;
    tg[o] = 0;
  }
  int m = l + r >> 1;
  if (x < m) update(ls, l, m, x, y, z);
  if (y > m) update(rs, m, r, x, y, z);
  pushup(o);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  
  std::vector<std::array<int, 3>> a(n);
  // std::vector<int> b;
  for (int i = 0; i < n; i++) {
    cin >> a[i][1] >> a[i][2] >> a[i][0];
    a[i][1]--, a[i][2]--;
  }
  std::sort(a.begin(), a.end());
  m--;
  tg[1] = 1, min[1] = add[1] = 0;
  int ans = 1e6;
  for (int i = 0, j = 0; i < n; i++) {
    update(1, 0, m, a[i][1], a[i][2], 1);
    while (min[1] > 0) {
      smin(ans, a[i][0] - a[j][0]);
      update(1, 0, m, a[j][1], a[j][2], -1);
      j++;
    }
  }
  std::cout << ans << "\n";
  return 0;
}
/*
5 12
1 5 5
3 4 10
4 10 6
11 12 5
10 12 3

 */