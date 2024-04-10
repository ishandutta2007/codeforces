#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 1e6 + 5, mod = 1e9 + 7;
int n, f[N], invf[N];
ll C(int n, int m) {
  if (m > n) return 0;
  return 1ll * f[n] * invf[m] % mod * invf[n - m] % mod;
}
int main() {
  // freopen("1.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      sum += x;
    }
    if (sum == n)
      printf("0\n");
    else if (sum < n)
      printf("1\n");
    else
      printf("%d\n", sum - n);
  }
}
/*
69420
629909355

42069
675837193
*/