#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int n, tot;
char a[maxn];

int main() {
  scanf("%s", a + 1);
  n = strlen(a + 1);
  for (int l = 1; l <= n; l++) {
    for (int j = 3; j < 20; j++) {
      int r = l + j - 1;
      if (r > n) {
        tot += n - l + 1;
        break;
      }
      bool flg = 0;
      for (int x = l; x < r - 1 && !flg; x++) {
        for (int k = 1; x + k + k <= r; k++) {
          if (a[x] == a[x + k] && a[x + k] == a[x + k + k]) {
            flg = 1; break;
          }
        }
      }
      if (flg) {
        tot += r - l;
        break;
      }
    }
  }
  printf("%I64d", 1ll * n * (n + 1) / 2 - tot);
  return 0;
}