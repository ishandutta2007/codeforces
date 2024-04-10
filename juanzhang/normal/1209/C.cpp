#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

int n, a[200010], a1[200010], a2[200010], ans[200010];

void solve() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%1d", a + i);
  rep(t, 0, 9) {
    bool F = 0;
    int c1 = 0, c2 = 0;
    rep(i, 1, n) {
      if (a[i] < t || (F && a[i] == t)) {
        a1[++c1] = a[i], ans[i] = 1;
      } else {
        F |= a[i] > t;
        a2[++c2] = a[i], ans[i] = 2;
      }
    }
    int lst = 0;
    bool flg = 1;
    rep(i, 1, c1) {
      if (lst > a1[i]) flg = 0;
      lst = a1[i];
    }
    rep(i, 1, c2) {
      if (lst > a2[i]) flg = 0;
      lst = a2[i];
    }
    if (flg) {
      for (int i = 1; i <= n; i++) {
        putchar(ans[i] | 48);
      }
      putchar(10);
      return;
    }
  }
  puts("-");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}