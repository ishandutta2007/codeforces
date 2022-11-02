#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 3e5 + 5;
int a[maxn];
int solve(int l, int n) {
  if (n == 1) return 0;
  int mnm = maxn, mxm = 0;
  n >>= 1;
  for (int i = l; i < l + n; i++) {
    mnm = min(mnm, a[i]);
    mxm = max(mxm, a[i]);
  }
  int flg;
  if (mnm == n)
    flg = 1;
  else if (mxm == n - 1)
    flg = 0;
  else
    return maxn;
  for (int i = l; i < l + n * 2; i++) a[i] %= n;
  // printf("%d %d %d\n", l, n, flg);
  return min(maxn, solve(l, n) + solve(l + n, n) + flg);
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      a[i]--;
    }
    int ans = solve(0, n);
    printf("%d\n", ans < maxn ? ans : -1);
  }
  return 0;
}