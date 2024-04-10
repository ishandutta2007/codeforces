#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2e5 + 5;
vector<int> e[maxn];
int lim, cnt;
int dfs(int u) {
  int dep = 1;
  for (auto v : e[u]) dep = max(dep, dfs(v) + 1);
  if (dep == lim) {
    cnt++;
    return 0;
  }
  return dep;
}
bool check(int m, int k) {
  lim = m;
  cnt = 0;
  for (auto u : e[1])
    for (auto v : e[u]) dfs(v);
  return cnt <= k;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 2; i <= n; i++) {
      int t;
      scanf("%d", &t);
      e[t].push_back(i);
    }
    int l = 0, r = n;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (check(m, k))
        r = m;
      else
        l = m;
    }
    printf("%d\n", r);
    for (int i = 1; i <= n; i++) e[i].clear();
  }
  return 0;
}