#include <algorithm>
#include <bitset>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1e4 + 5, width = 1 << 6;
typedef bitset<width> my_stat;
vector<vector<int>> e;
my_stat dp[maxn], in[maxn];
int h[maxn], dep[maxn];
my_stat operator+(const my_stat &a, const my_stat &b) {
  my_stat c;
  for (int i = 0; i < width; i++)
    if (a[i])
      for (int j = 0; j < width; j++)
        if (b[j]) c[i | j] = 1;
  return c;
}
int cnt[width];
my_stat init(int n) {
  my_stat a;
  a[0] = 1;
  a[n] = 1;
  return a;
}
void write(my_stat a) {
  for (int i = 0; i < width; i++) putchar(a[i] ? '1' : '0');
  puts("");
}
int main() {
  for (int i = 1; i < width; i++) cnt[i] = cnt[i >> 1] + (i & 1);
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    e.assign(n + 1, {});
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      e[u].push_back(v);
      e[v].push_back(u);
    }
    int f;
    scanf("%d", &f);
    for (int i = 0; i < f; i++) scanf("%d", &h[i]);
    int k;
    scanf("%d", &k);
    fill(dp, dp + n + 1, my_stat(1));
    fill(in, in + n + 1, my_stat(1));
    for (int i = 0; i < k; i++) {
      int p;
      scanf("%d", &p);
      int &t = h[p - 1];
      in[t] = in[t] + init(1 << i);
      t = 1;
    }
    // for (int i = 1; i <= n; i++) write(in[i]);
    // puts("");
    queue<int> que;
    que.push(1);
    fill(dep, dep + n + 1, 0);
    dep[1] = 1;
    while (que.size()) {
      // puts("1");
      int u = que.front();
      que.pop();
      dp[u] = dp[u] + in[u];
      for (auto v : e[u]) {
        if (!dep[v]) {
          dep[v] = dep[u] + 1;
          que.push(v);
        }
        if (dep[v] == dep[u] + 1) dp[v] |= dp[u];
      }
    }
    my_stat res = 1;
    for (int i = 0; i < f; i++) {
      // write(dp[h[i]]);
      res = res + dp[h[i]];
    }
    int ans = 0;
    for (int i = 0; i < width; i++)
      if (res[i]) {
        ans = max(ans, cnt[i]);
        // printf("%d ", cnt[i]);
      }
    printf("%d\n", k - ans);
  }
  return 0;
}