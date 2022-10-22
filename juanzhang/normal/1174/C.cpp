#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, now, a[maxn];

int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    if (a[i]) continue;
    a[i] = ++now;
    for (int j = i << 1; j <= n; j += i) {
      a[j] = now;
    }
  }
  for (int i = 2; i <= n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}