#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 50;

int a[N], k[N], b[N];

int main() {
  int n, m, tot = 0, sigma = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i ++) {
    scanf("%d", &k[i]);
    tot += (k[i] > 0);
    sigma += k[i];
  }
  int ans = 1e9;
  for (int i = 0, j = 1; i <= n; i ++) {
    if (i) {
      b[a[i]] --;
      tot += (k[a[i]] > b[a[i]]);
    }
    while (j <= n && tot) {
      b[a[j]] ++;
      tot -= (k[a[j]] == b[a[j]]);
      j ++;
    }
    if (!tot)
      ans = min(ans, j - i - 1);
  }
  printf("%d\n", ans == 1e9 ? -1 : ans - sigma);
  return 0;
}