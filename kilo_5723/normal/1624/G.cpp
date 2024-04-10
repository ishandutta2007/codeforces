#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 2e5 + 5;

struct edge {
  int u, v, w;
};
edge e[maxn];

int f[maxn];
int ff(int u) { return f[u] == u ? u : f[u] = ff(f[u]); }

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    int ans = 0;
    for (int bin = 1 << 30; bin; bin >>= 1) {
      for (int i = 1; i <= n; i++) f[i] = i;
      int cnt = n;
      for (int i = 0; i < m; i++)
        if ((e[i].w & ans + bin - 1) == e[i].w) {
          int u = ff(e[i].u), v = ff(e[i].v);
          if (u == v) continue;
          f[u] = v;
          cnt--;
        }
      if (cnt > 1) ans += bin;
    }
    printf("%d\n", ans);
  }
  return 0;
}