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

constexpr int N(1e5 + 5);
std::vector<int> g[N], ans;
bool vis[N], ins[N];
void dfs(int x) {
  if (ins[x]) {
    std::cout << "-1\n";
    exit(0);
  }
  if (vis[x]) return;
  ins[x] = vis[x] = true;
  for (int y : g[x]) {
    dfs(y);
  }
  ans.push_back(x);
  ins[x] = false;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(m);
  for (int &x : a) std::cin >> x;
  for (int i = 1; i <= n; i++) {
    int t, x;
    std::cin >> t;
    while (t--) std::cin >> x, g[i].push_back(x);
  }
  for (int x : a) dfs(x);
  std::cout << ans.size() << "\n";
  for (int x : ans) std::cout << x << " ";
  return 0;
}