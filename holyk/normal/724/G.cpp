#include <bits/stdc++.h>
#include <string.h>
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

constexpr int N(1e5 + 5), P(1e9 + 7);
std::vector<std::pair<int, LL>> g[N];
bool vis[N];
LL d[N], p[61];
int cnt[61];
bool ins(LL x) {
  if (!x) return false;
  for (int i = 60; i >= 0; i--) {
    if (x >> i & 1 ^ 1) continue;
    if (!p[i]) {
      p[i] = x;
      return true;
    }
    x ^= p[i];
  }
  return false;
}
int size;
void dfs(int x) {
  vis[x] = true;
  size++;
  for (int i = 0; i <= 60; i++) if (d[x] >> i & 1) cnt[i]++;
  for (auto [y, z] : g[x]) {
    if (vis[y]) {
      ins(d[x] ^ d[y] ^ z);
    } else {
      d[y] = d[x] ^ z;
      dfs(y);
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  while (m--) {
    int x, y;
    LL z;
    std::cin >> x >> y >> z;
    g[x].emplace_back(y, z);
    g[y].emplace_back(x, z);
  }
  int ans = 0;
  
  for (int u = 1; u <= n; u++) {
    if (vis[u]) continue;
    memset(cnt, 0, sizeof cnt);
    memset(p, 0, sizeof p);
    size = 0;
    dfs(u);
    int tot = 0;
    for (int i = 0; i <= 60; i++) if (p[i]) tot++;
    for (int i = 0, x = 1; i <= 60; i++, x = x * 2LL % P) {
      int v1 = 1LL * cnt[i] * (size - cnt[i]) % P, v0 = (1LL * size * (size - 1) / 2 - v1) % P;
      int c = 0, p0, p1 = 0;
      for (int j = i; j <= 60; j++) if (p[j] >> i & 1) c++;
      p0 = 1;
      for (int j = tot - c; j--; p0 = p0 * 2LL % P) ;
      if (c) {
        while (--c) p0 = p0 * 2LL % P;
        p1 = p0;
      }
      ans = (ans + (1LL * v0 * p1 + 1LL * v1 * p0) % P * x) % P;
    }
  }
  std::cout << (ans + P) % P << "\n";
  return 0;
}