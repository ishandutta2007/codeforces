#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

int l[N][N], r[N][N], a[N];
int T, n;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(l[0], 0, sizeof(l[0])); memset(r[n + 1], 0, sizeof(r[n + 1]));
    for (int i = 1; i <= n; i++) {
      memcpy(l[i], l[i - 1], sizeof(l[i]));
      ++l[i][a[i]];
    }
    for (int i = n; i >= 1; i--) {
      memcpy(r[i], r[i + 1], sizeof(r[i]));
      ++r[i][a[i]];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) ans += l[i - 1][a[j]] * r[j + 1][a[i]];
    }
    printf("%lld\n", ans);
  }
  return 0;
}