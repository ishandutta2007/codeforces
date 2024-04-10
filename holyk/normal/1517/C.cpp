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

const std::array<int, 2> D[] = {
  {-1, 0}, {0, -1}, {1, 0}, {0, 1}
};
int n, a[505], cnt[505], b[505][505];
void dfs(int x, int y, int z) {
  if (!cnt[z] || x < y || x < 1 || y < 1 || x > n || y > n || b[x][y]) return;
  b[x][y] = z;
  cnt[z]--;
  for (auto [dx, dy] : D) {
    dfs(x + dx, y + dy, z);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i], cnt[a[i]] = a[i];
  for (int i = 1; i <= n; i++) dfs(i, i, a[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) if (!b[i][j]) return puts("-1"), 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) std::cout << b[i][j] << " \n"[j == i];
  }

  return 0;
}