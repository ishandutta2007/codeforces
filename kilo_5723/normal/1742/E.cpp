#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
ll sum[maxn], req[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
      ll t;
      scanf("%lld", &t);
      req[i] = max(i ? req[i - 1] : 0, t);
      sum[i] = (i ? sum[i - 1] : 0) + t;
    }
    while (q--) {
      ll h;
      scanf("%lld", &h);
      printf("%lld ", sum[(upper_bound(req, req + n, h) - req) - 1]);
    }
    puts("");
  }
  return 0;
}