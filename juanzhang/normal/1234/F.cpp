#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int maxn = 1e6 + 10;
char a[maxn];
int n, f[1 << 20], g[1 << 20];

int main() {
  scanf("%s", a + 1);
  n = strlen(a + 1);
  for (int i = 1; i <= n; i++) {
    int S = 0;
    for (int j = i; j <= min(i + 19, n); j++) {
      int x = a[j] - 'a';
      if (S >> x & 1) break;
      S |= 1 << x;
      f[S] = max(f[S], j - i + 1);
    }
  }
  for (int S = 1; S < 1 << 20; S++) {
    g[S] = f[S];
    for (int i = 0; i < 20; i++) {
      if (S >> i & 1) g[S] = max(g[S], g[S ^ (1 << i)]);
    }
  }
  int ans = 0;
  int all = (1 << 20) - 1;
  for (int S = 0; S < 1 << 20; S++) {
    ans = max(ans, f[S] + g[all ^ S]);
  }
  printf("%d", ans);
  return 0;
}