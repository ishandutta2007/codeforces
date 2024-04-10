#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, a[maxn];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i), a[i] = abs(a[i]);
  }
  sort(a + 1, a + n + 1);
  long long ans = 0;
  for (int i = 1, j = 2; i <= n && j <= n; j++) {
    while (a[i] * 2 < a[j]) i++;
    if (i <= n) ans += j - i;
  }
  printf("%I64d", ans);
  return 0;
}