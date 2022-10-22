#include <bits/stdc++.h>
using namespace std;

int n;

inline int qp(int a, int k) {
  int res = 1;
  for (; k; k >>= 1, a = 1ll * a * a % n) {
    if (k & 1) res = 1ll * res * a % n;
  }
  return res;
}

inline bool pd(int x) {
  int tmp = sqrt(x);
  for (int i = 2; i <= tmp; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}

int main() {
  scanf("%d", &n);
  if (n == 1) return puts("YES\n1"), 0;
  if (n == 4) return puts("YES\n1\n3\n2\n4"), 0;
  if (!pd(n)) return puts("NO"), 0;
  puts("YES\n1");
  for (int i = 2; i < n; i++) {
    printf("%d\n", 1ll * i * qp(i - 1, n - 2) % n);
  }
  printf("%d", n);
  return 0;
}