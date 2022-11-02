#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 2e3 + 5;
int a[maxn];
int solve(int n, int m) {
  int cur = 0, cnt = 0, res = 0;
  for (int i = 0; i < n; i++) {
    cur += a[i];
    cnt++;
    if (cur > m) return maxn;
    if (cur == m) {
      res = max(res, cnt);
      cnt = 0;
      cur = 0;
    }
  }
  return res;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      s += a[i];
    }
    int ans = maxn;
    for (int i = n; i >= 1; i--)
      if (!(s % i)) ans = min(ans, solve(n, s / i));
    printf("%d\n", ans);
  }
  return 0;
}