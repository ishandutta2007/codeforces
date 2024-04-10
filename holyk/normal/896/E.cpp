// Author:  HolyK
// Created: Fri Sep 10 15:54:37 2021
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

constexpr int N(1e6 + 5), T(888), M(1e5 + 5);
struct Option {
  int opt, l, r, x;
} q[N];

int n, m, a[N], ans[N];

template <int S, int I>
struct LazyArray {
  int a[S], b[S], c;
  void clear() { c++; }
  int &operator[](const int &i) {
    if (b[i] != c) b[i] = c, a[i] = I;
    return a[i];
  }
};
LazyArray<M * 2, -1> pos;
int fa[T], siz[T];
int find(int x) {
  while (x != fa[x]) x = fa[x] = fa[fa[x]];
  return x;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    cin >> q[i].opt >> q[i].l >> q[i].r >> q[i].x;
    q[i].l--;
  }
  for (int x = 0; x < n; x += T) {
    int y = std::min(n, x + T), max, tag;
    auto build = [&] {
      max = tag = 0;
      pos.clear();
      memset(siz, 0, sizeof siz);
      for (int i = x; i < y; i++) {
        smax(max, a[i]);
        pos[a[i]] = i - x;
      }
      for (int i = x; i < y; i++) {
        fa[i - x] = pos[a[i]];
        siz[fa[i - x]]++;
      }
    };
    build();
    for (int i = 1; i <= m; i++) {
      if (q[i].l >= y || q[i].r <= x) continue;
      if (q[i].l <= x && y <= q[i].r) {
        if (q[i].opt == 2) {
          if (~pos[q[i].x + tag]) {
            ans[i] += siz[pos[q[i].x + tag]];
          }
          continue;
        }
        if (max <= q[i].x || !q[i].x) continue;
        if (std::min(max - q[i].x, q[i].x) <= T) {
          if (max <= q[i].x * 2) {
            for (int j = q[i].x + 1 + tag; j <= max + tag; j++) {
              if (pos[j] == -1) continue;
              int &u = pos[j], &v = pos[j - q[i].x];
              if (v == -1) {
                v = u, a[x + u] -= q[i].x;
              } else {
                fa[u] = v;
                siz[v] += siz[u];
                siz[u] = 0;
              }
              u = -1;
            }
            max = q[i].x;
          } else {
            for (int j = q[i].x + tag; j >= tag; j--) {
              if (pos[j] == -1) continue;
              int &u = pos[j], &v = pos[j + q[i].x];
              if (v == -1) {
                v = u, a[x + u] += q[i].x;
              } else {
                fa[u] = v;
                siz[v] += siz[u];
                siz[u] = 0;
              }
              u = -1;
            }
            tag += q[i].x;
            max -= q[i].x;
          }
          continue;
        }
      }
      for (int j = x; j < y; j++) {
        a[j] = a[x + find(j - x)];
      }
      for (int j = x; j < y; j++) {
        a[j] -= tag;
      }
      int l = std::max(q[i].l, x), r = std::min(q[i].r, y);
      if (q[i].opt == 1) {
        for (int j = l; j < r; j++) {
          if (a[j] > q[i].x) a[j] -= q[i].x;
        }
      } else {
        for (int j = l; j < r; j++) {
          if (a[j] == q[i].x) ans[i]++;
        }
      }
      build();
    }
  }
  for (int i = 1; i <= m; i++) {
    if (q[i].opt == 2) {
      std::cout << ans[i] << "\n";
    }
  }
  return 0;
}