#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 2e5 + 5, maxm = 1e3 + 5, inf = 1e9;
int a[maxn], last[maxm], _gcd[maxm][maxm];
int gcd(int a, int b) {
  if (_gcd[a][b])
    return _gcd[a][b];
  else
    return b ? gcd(b, a % b) : a;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    fill(last, last + maxm, -inf);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      last[a[i]] = i;
    }
    int ans = -inf;
    for (int i = 0; i < maxm; i++)
      for (int j = 0; j < maxm; j++)
        if (gcd(i, j) == 1) ans = max(ans, last[i] + last[j] + 2);
    printf("%d\n", ans < 0 ? -1 : ans);
  }
  return 0;
}