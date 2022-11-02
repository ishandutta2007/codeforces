#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 5e3 + 5;
int a[maxn];
ll b[maxn];
ll calc(int a[], int n) {
  if (!n) return 0;
  // for (int i = 0; i < n; i++) printf("%d ", a[i]);
  // puts("");
  ll ans = 0;
  b[0]=0;
  for (int i = 0; i < n; i++) {
    b[i + 1] = b[i] / a[i] + 1;
    ans += b[i + 1];
    b[i + 1] *= a[i];
  }
  // printf("%lld\n", ans);
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  ll ans = 1e18;
  for (int i = 0; i < n; i++) {
    reverse(a, a + i);
    ans = min(ans, calc(a, i) + calc(a + i + 1, n - i - 1));
    reverse(a, a + i);
  }
  printf("%lld\n", ans);
  return 0;
}