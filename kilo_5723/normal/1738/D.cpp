#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn];
vector<int> e[maxn];
void dfs(int u) {
  for (auto v : e[u]) printf("%d ", v);
  if (e[u].size()) dfs(e[u].back());
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    int k = 0;
    while (k < n && b[k + 1] > k + 1) k++;
    printf("%d\n", k);
    for (int i = 0; i <= n + 1; i++) e[i].clear();
    for (int i = 1; i <= n; i++) e[b[i]].push_back(i);
    for (int i = 0; i <= n + 1; i++)
      sort(e[i].begin(), e[i].end(),
           [](int a, int b) { return e[a].size() < e[b].size(); });
    dfs(0);
    dfs(n + 1);
    puts("");
  }
  return 0;
}