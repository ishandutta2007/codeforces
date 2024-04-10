#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2e5 + 5;
vector<vector<int>> e;
bool vis[maxn];
bool dfs(int s, int t) {
  if (s==t) return true;
  if (vis[s]) return false;
  vis[s] = true;
  for (auto u : e[s])
    if (dfs(u, t)) return true;
  return false;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    e.clear();
    e.resize(n + 1);
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      if (i + t + 1 <= n) e[i].push_back(i + t + 1);
      if (i >= t) e[i - t].push_back(i + 1);
    }
    fill(vis, vis + n + 1, false);
    puts(dfs(0, n) ? "YES" : "NO");
  }
  return 0;
}