#include <bits/stdc++.h>
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
int p[27];
int ins(int x) {
  if (!x) return -1;
  for (int i = 26; i >= 0; i--) {
    if (x >> i & 1 ^ 1) continue;
    if (!p[i]) return p[i] = x, i;
    x ^= p[i];
  }
  return -1;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> g(n);
  while (m--) {
    int x, y, z;
    std::cin >> x >> y >> z; 
    x--, y--;
    g[x].emplace_back(y, z);
    g[y].emplace_back(x, z);
  }
  std::vector<bool> vis(n);
  std::vector<int> d(n);
  std::function<void(int)> dfs = [&](int x) {
    vis[x] = true;
    for (auto [y, z] : g[x]) {
      if (vis[y]) {
        ins(d[x] ^ d[y] ^ z);
      } else {
        d[y] = d[x] ^ z;
        dfs(y);
      }
    }
  };

  dfs(0);
  for (int i = 26; i >= 0; i--) smin(d[n - 1], d[n - 1] ^ p[i]);
  std::cout << d[n - 1];
  return 0;
}