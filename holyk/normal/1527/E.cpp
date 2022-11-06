#include <bits/stdc++.h>
#define perr(a...) fprintf(stderr, a)
#define dbg(a...) perr("\033[32;1m"), perr(a), perr("\033[0m")
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
constexpr int N(35000 + 5);
LL min[N << 2], tag[N << 2];
LL f[N];
#define ls o << 1
#define rs o << 1 | 1
void pushup(int o) {
  min[o] = std::min(min[ls], min[rs]);
}
void pushdown(int o) {
  if (tag[o]) {
    tag[ls] += tag[o], tag[rs] += tag[o];
    min[ls] += tag[o], min[rs] += tag[o];
    tag[o] = 0;
  }
}
void build(int o, int l, int r) {
  tag[o] = 0;
  if (l == r) {
    min[o] = f[l];
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  pushup(o);
}
void update(int o, int l, int r, int x, int y, int z) {
  if (y < l || r < x) return;
  if (x <= l && r <= y) {
    min[o] += z;
    tag[o] += z;
    return;
  }
  int m = l + r >> 1;
  pushdown(o);
  update(ls, l, m, x, y, z);
  update(rs, m + 1, r, x, y, z);
  pushup(o);
}
LL ask(int o, int l, int r, int x, int y) {
  if (r < x || y < l) return 1e18;
  if (x <= l && r <= y) return min[o];
  int m = l + r >> 1;
  pushdown(o);
  return std::min(ask(ls, l, m, x, y), ask(rs, m + 1, r, x, y));
}

int a[N], pos[N];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k;
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1];
    if (pos[a[i]]) f[i] += i - pos[a[i]];
    pos[a[i]] = i;
  }

  for (int t = 2; t <= k; t++) {
    build(1, t - 1, n);
    memset(pos, 0, sizeof pos);
    for (int i = t; i <= n; i++) {
      if (pos[a[i]]) update(1, t - 1, n, t - 1, pos[a[i]] - 1, i - pos[a[i]]);
      pos[a[i]] = i;
      f[i] = ask(1, t - 1, n, t - 1, i - 1);
    }
    f[t - 1] = 1e18;
  }
  std::cout << f[n] << "\n";
  return 0;
}
/*
7 2
1 6 6 4 6 6 6

7 4
5 5 5 5 2 3 3

 */