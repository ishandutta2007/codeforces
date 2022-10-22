#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, x, y, a[maxn];

int main() {
  scanf("%d %d %d", &n, &x, &y);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; i++) {
    int mn = 1 << 30;
    for (int j = max(1, i - x); j <= i; j++) {
      mn = min(mn, a[j]);
    }
    for (int j = i; j <= min(n, i + y); j++) {
      mn = min(mn, a[j]);
    }
    if (a[i] <= mn) {
      printf("%d", i); return 0;
    }
  }
  return 0;
}