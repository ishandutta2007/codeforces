#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn], e[maxn];
bool vis[maxn];
int dfs(int u) {
  int v = u, ans = 0;
  do {
    vis[v] = true;
    v = e[v];
    ans++;
  } while (v != u);
  return ans;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    for (int i = 0; i < n; i++) e[a[i]] = b[i];
    fill(vis, vis + n + 1, false);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      if (!vis[i])
        if (dfs(i) & 1) cnt++;
    int m = (n - cnt) / 2;
    printf("%lld\n", 2LL * (n - m) * m);
  }
  return 0;
}