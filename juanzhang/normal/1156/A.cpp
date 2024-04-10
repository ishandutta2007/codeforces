#include <bits/stdc++.h>
using namespace std;

int n, a[105];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int ans = 0;
  bool flg = 0;
  for (int i = 2; i <= n; i++) {
    if ((a[i] == 2 && a[i - 1] == 3) || (a[i] == 3 && a[i - 1] == 2)) {
      flg = 1; break;
    }
    if (a[i] == 1) {
      ans += a[i - 1] + 1;
    } else if (a[i] == 2) {
      ans += 3;
    } else {
      ans += 4;
    }
    if (i > 2 && a[i - 2] == 3 && a[i - 1] == 1 && a[i] == 2) {
      ans--;
    }
  }
  if (flg) {
    puts("Infinite");
  } else {
    puts("Finite");
    printf("%d", ans);
  }
  return 0;
}