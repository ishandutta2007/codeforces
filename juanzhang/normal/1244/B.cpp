#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int n;
char a[1010];

void solve() {
  scanf("%d %s", &n, a + 1);
  int ans = n;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 49) {
      ans = max(ans, max(i, n - i + 1) * 2);
    }
  }
  printf("%d\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}