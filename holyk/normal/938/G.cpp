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

constexpr int N(2e5 + 5);
PII query[N];
#define ls o << 1
#define rs o << 1 | 1
std::vector<std::array<int, 3>> g[N << 2];
void update(int o, int l, int r, int x, int y, int u, int v, int w) {
  if (r < x || l > y) return;
  if (x <= l && r <= y) {
    g[o].push_back({u, v, w});
    return;
  }
  int m = l + r >> 1;
  update(ls, l, m, x, y, u, v, w), update(rs, m + 1, r, x, y, u, v, w);
}
std::vector<std::pair<int*, int>> changes;
void record(int &x) { changes.emplace_back(&x, x); }
void rollBack(size_t t) {
  while (changes.size() > t) {
    *changes.back().first = changes.back().second;
    changes.pop_back();
  }
} 

int fa[N], siz[N], val[N];
int find(int &x) {
  int r = val[x];
  while (x != fa[x]) r ^= val[x = fa[x]];
  return r;
}
void ins(int *p, int x) {
  if (!x) return;
  for (int i = 29; i >= 0; i--) {
    if (x >> i & 1 ^ 1) continue;
    if (!p[i]) {
      record(p[i]);
      p[i] = x;
      break;
    }
    x ^= p[i];
  }
}
int p[N][30];
void solve(int o, int l, int r) {
  size_t now = changes.size();
  for (auto [x, y, z] : g[o]) {
    int r = find(x) ^ find(y) ^ z;
    if (x == y) {
      ins(p[x], r);
    } else {
      if (siz[x] > siz[y]) std::swap(x, y);
      record(fa[x]), record(siz[y]), record(val[x]);
      fa[x] = y, siz[y] += siz[x], val[x] ^= r;
      for (int i = 0; i < 30; i++) ins(p[y], p[x][i]);
    }
  }
  if (l == r) {
    auto [x, y] = query[l];
    if (x) {
      int ans = find(x) ^ find(y);
      assert(x == y);
      for (int i = 29; i >= 0; i--) smin(ans, ans ^ p[x][i]);
      std::cout << ans << "\n";
    }
    rollBack(now);
    return;
  }
  int m = l + r >> 1;
  solve(ls, l, m), solve(rs, m + 1, r);
  rollBack(now);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::map<PII, PII> t;
  while (m--) {
    int x, y, z;
    std::cin >> x >> y >> z;
    t[PII(x, y)] = {0, z};
  }
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    int opt, x, y;
    std::cin >> opt >> x >> y;
    if (opt == 1) {
      int z;
      std::cin >> z;
      t[PII(x, y)] = {i, z};
    } else if (opt == 2) {
      auto [l, w] = t[PII(x, y)];
      update(1, 1, m, l, i - 1, x, y, w);
      t.erase(PII(x, y));
    } else {
      query[i] = {x, y};
    }
  }
  for (auto &[u, v] : t) {
    auto &[x, y] = u;
    auto &[l, w] = v;
    update(1, 1, m, l, m, x, y, w);
  }
  std::iota(fa, fa + 1 + n, 0);
  std::fill(siz, siz + 1 + n, 1);
  solve(1, 1, m);
  return 0;
}