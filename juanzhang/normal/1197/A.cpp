#include <bits/stdc++.h>
using namespace std;

int n, a[100010];

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + n + 1);
  int x = a[n - 1], y = a[n];
  printf("%d\n", min(n - 2, x - 1));
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}