#include <bits/stdc++.h>
#define dbg(...) std::cerr << "\033[32;1m", fprintf(stderr, __VA_ARGS__), std::cerr << "\033[0m"
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }
using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(1e5 + 5);
std::vector<int> g[N];
int cnt, k;
int dfs(int x, int fa) {
  int max = 1;
  for (int y : g[x]) {
    if (y == fa) continue;
    if (!max) {
      dfs(y, x);
      continue;
    }
    int d = dfs(y, x);
    if (max + d >= k) {
      cnt++, max = 0;
    } else {
      smax(max, d + 1);
    }
  }
  return max;
}
int calc(int x) {
  cnt = 0, k = x;
  dfs(1, 0);
  return cnt;
}
void solve(int l, int r, int sl, int sr) {
  if (l > r) return;
  if (sl == sr) {
    for (int i = l; i <= r; i++) std::cout << sl << "\n";
    return;
  }
  int m = l + r >> 1, s = calc(m);
  solve(l, m - 1, sl, s);
  std::cout << s << "\n";
  solve(m + 1, r, s, sr);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  for (int i = 1, x, y; i < n; i++) {
    std::cin >> x >> y;
    g[x].push_back(y), g[y].push_back(x);
  }
  std::cout << n << "\n";
  solve(2, n, n, 0);
  return 0;
}