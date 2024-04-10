#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
vector<int> e[maxn];
ll s[maxn], nxt[maxn];
ll dfs(int u, int k) {
  ll res = s[u] * k;
  nxt[u] = s[u];
  if (!e[u].size()) return res;
  int siz = e[u].size(), rep = k / siz, sel = k % siz;
  for (auto v : e[u]) res += dfs(v, rep);
  sort(e[u].begin(), e[u].end(), [](int u, int v) { return nxt[u] > nxt[v]; });
  for (int i = 0; i < sel; i++) res += nxt[e[u][i]];
  nxt[u] += nxt[e[u][sel]];
  return res;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++) {
      int t;
      scanf("%d", &t);
      e[t].push_back(i + 1);
    }
    for (int i = 1; i <= n; i++) scanf("%lld", &s[i]);
    printf("%lld\n", dfs(1, k));
    for (int i = 1; i <= n; i++) e[i].clear();
  }
  return 0;
}