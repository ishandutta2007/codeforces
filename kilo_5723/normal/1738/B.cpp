#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
ll a[maxn], s[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) scanf("%lld", &s[n - k + i]);
    for (int i = 1; i < k; i++) a[n - k + i] = s[n - k + i] - s[n - k + i - 1];
    // for (int i = 1; i < k; i++) printf("%lld ", a[n - k + i]);
    // puts("");
    bool flg = k == 1 || s[n - k] <= a[n - k + 1] * (n - k + 1);
    for (int i = 2; i < k; i++)
      if (a[n - k + i - 1] > a[n - k + i]) flg = false;
    puts(flg ? "Yes" : "No");
  }
  return 0;
}