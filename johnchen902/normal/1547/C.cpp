#include <stdio.h>

int a[300], b[300], ans[600];

void solve() {
  int k, n, m;
  scanf("%d%d%d", &k, &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d", a + i);
  for (int i = 0; i < m; i++)
    scanf("%d", b + i);

  for (int i = 0, j = 0; i < n || j < m; ) {
    if (i < n && a[i] <= k) {
      ans[i + j] = a[i];
      if (a[i] == 0) k++;
      i++;
    } else if (j < m && b[j] <= k) {
      ans[i + j] = b[j];
      if (b[j] == 0) k++;
      j++;
    } else {
      puts("-1");
      return;
    }
  }

  for (int i = 0; i < n + m; i++)
    printf("%d%c", ans[i], i + 1 == n + m ? '\n' : ' ');
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}