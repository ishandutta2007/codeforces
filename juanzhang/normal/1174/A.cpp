#include <bits/stdc++.h>
using namespace std;

int n, a[2010];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n * 2; i++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + n + n + 1);
  int s1 = 0, s2 = 0;
  for (int i = 1; i <= n; i++) {
    s1 += a[i], s2 += a[n + i];
  }
  if (s1 == s2) return puts("-1"), 0;
  for (int i = 1; i <= n * 2; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}