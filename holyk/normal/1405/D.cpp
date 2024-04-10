#include <cstdio>
#include <algorithm>
#include <vector>

constexpr int N(1e5 + 5);
int n, a, b, da, db, e;
int dis, p, q;
std::vector<int> g[N];
void dfs(int x, int d, int f) {
  if (d > dis) dis = d, p = x;
  for (int y : g[x]) 
    if (f != y) {
      dfs(y, d + 1, x);
    }

}
void go(int x, int d, int f) {
  if (x == b) {
    e = d;
    return;
  }
  for (int y : g[x]) 
    if (f != y) {
      go(y, d + 1, x);
    }
}
int main() {
  int t; scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int x, y, i = 1; i < n; i++) { 
      scanf("%d%d", &x, &y);
      g[x].push_back(y);
      g[y].push_back(x);
    }
    dis = 0, dfs(a, 0, 0), dfs(q = p, 0, 0);
    da = std::min(dis, da), db = std::min(dis, db);
    
    if (da * 2 >= db) {
      puts("Alice");
    } else {
      go(a, 0, 0);
      puts(e <= da ? "Alice" : "Bob");
    }
  }
  return 0;
}