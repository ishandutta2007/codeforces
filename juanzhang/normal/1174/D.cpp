#include <bits/stdc++.h>
using namespace std;

const int maxn = (1 << 18) + 10;
int n, x, len, a[maxn], flg[maxn];

int main() {
  scanf("%d %d", &n, &x);
  for (int i = 1; i < 1 << n; i++) {
    if (!flg[i] && i != x) {
      a[++len] = i, flg[i] = flg[x ^ i] = 1;
    }
  }
  for (int i = len; i; i--) {
    a[i] ^= a[i - 1];
  }
  printf("%d\n", len);
  if (len) {
    for (int i = 1; i <= len; i++) {
      printf("%d ", a[i]);
    }
  }
  return 0;
}