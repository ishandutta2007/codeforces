#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int a[1010], b[1010];

int main() {
  scanf("%d %d %d", &n, &m, &r);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", b + i);
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  int val = b[m], ans = 0;
  for (int i = 1; i <= n; i++) {
    if (val < a[i]) continue;
    int t = r / a[i];
    ans += t * val, r %= a[i];
  }
  ans += r;
  printf("%d", ans);
  return 0;
}