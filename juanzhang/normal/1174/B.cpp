#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, a[maxn];

int main() {
  scanf("%d", &n);
  bool f0 = 0, f1 = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    f1 |= a[i] & 1;
    f0 |= ~a[i] & 1;
  }
  if (!f0 || !f1) {
    for (int i = 1; i <= n; i++) {
      printf("%d ", a[i]);
    }
    return 0;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}