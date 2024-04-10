#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 105;
int a[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int k, n;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = k; i < n; i++) a[i % k] = max(a[i % k], a[i]);
    ll sum = 0;
    for (int i = 0; i < k; i++) sum += a[i];
    printf("%lld\n", sum);
  }
  return 0;
}