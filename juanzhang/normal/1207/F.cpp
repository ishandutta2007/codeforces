#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int bsz = 650;
int a[500010];
ll sum[700][700];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int op, x, y;
    scanf("%d %d %d", &op, &x, &y);
    if (op == 1) {
      a[x] += y;
      for (int i = 1; i <= bsz; i++) {
        sum[i][x % i] += y;
      }
    } else {
      if (x > bsz) {
        ll ans = 0;
        for (int i = y; i <= 500000; i += x) {
          ans += a[i];
        }
        printf("%I64d\n", ans);
      } else {
        printf("%I64d\n", sum[x][y]);
      }
    }
  }
  return 0;
}