#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, a[maxn];

int main() {
  scanf("%d", &n);
  if (n % 2 == 0) {
    return puts("NO"), 0;
  }
  puts("YES");
  for (int i = 1; i <= n; i++) {
    int k = i * 2 - 1;
    a[i] = (i & 1) ? k : k + 1;
    a[n + i] = (i & 1) ? k + 1 : k;
  }
  for (int i = 1; i <= n << 1; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}