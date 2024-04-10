#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 5e3 + 5;
int cnt[maxn];
ll calc(int a[], int n, int b[], int m) {
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; i++) cnt[a[i]]++;
  for (int i = 1; i < maxn; i++) cnt[i] += cnt[i - 1];
  ll ans = 0;
  for (int i = 0; i < m; i++) ans += (m - i - 1) * (cnt[b[i]]);
  // puts("aa");
  // for (int i=0;i<n;i++) printf("%d ",a[i]);
  // puts("");
  // for (int i=0;i<m;i++) printf("%d ",b[i]);
  // puts("");
  // printf("%lld\n",ans);
  // puts("bb");
  return ans;
}
int a[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    ll ans = 0;
    while (n) {
      // for (int i = 0; i < n; i++) printf("%d ", a[i]);
      // puts("");
      int p = 0;
      while (a[p] < n) p++;
      reverse(a, a + p);
      ans += calc(a, p, a + p + 1, n - p - 1);
      ans += calc(a + p + 1, n - p - 1, a, p);
      reverse(a, a + p);
      while (p < n) {
        swap(a[p], a[p + 1]);
        p++;
      }
      // printf("%lld\n", ans);
      n--;
    }
    printf("%lld\n", ans);
  }
  return 0;
}