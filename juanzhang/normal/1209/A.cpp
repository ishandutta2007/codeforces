#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

int n, a[201], vis[201];

int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  int ans = 0;
  rep(i, 1, n) {
    if (vis[i]) continue;
    ans++;
    rep(j, i + 1, n) {
      if (a[j] % a[i] == 0) vis[j] = 1;
    }
  }
  printf("%d", ans);
  return 0;
}