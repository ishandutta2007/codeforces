#include <stdio.h>
#include <cstdlib>
#include <algorithm>

const int N = 1000000 + 10;

int n, a[N];
int cnt[5];

int main() {
  scanf("%d", &n);
  int sum = 0;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), ++cnt[a[i]], sum += a[i];
  int ans = -1;
  for (int i = 0; 4 * i <= sum; ++i) {
    int j = sum - 4 * i;
    if (j % 3) continue;
    int a = i, b = j / 3, c = n - a - b, cur = 0;
    if (c < 0) continue;
    for (int k = 4; k >= 0; --k) {
      int v = cnt[k];
      if (a) {
        int t = std::min(v, a);
        a -= t;
        v -= t;
        cur += abs(4 - k) * t;
      }
      if (b) {
        int t = std::min(v, b);
        b -= t;
        v -= t;
        cur += abs(3 - k) * t;
      }
      int t = std::min(v, c);
      c -= t;
      v -= t;
      cur += k * t;
    }
    cur /= 2;
    if (ans == -1 || cur < ans) ans = cur;
  }
  printf("%d\n", ans);
  return 0;
}