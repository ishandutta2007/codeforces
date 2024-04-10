#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <map>
#include <memory>
#include <queue>

using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 2e5 + 5;
int n;
struct node {
  ll a, b;
  bool operator<(const node& o) const {
    if (b == o.b) return a < o.a;
    return b < o.b;
  }
} a[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld%lld", &a[i].a, &a[i].b);
  sort(a + 1, a + 1 + n);
  ll ans = 0, sum = 0, mm = 0;
  for (int i = 1; i <= n; i++) mm += a[i].a;
  for (int i = 1; i <= n; i++) {
    if (sum >= a[i].b) {
      a[i].a = min(a[i].a, mm);
      ans += a[i].a;
      sum += a[i].a;
      mm -= a[i].a;
    } else {
      ll need = a[i].b - sum;
      need = min(need, mm);
      ans += need * 2;
      mm -= need;
      sum += need;
      a[i].a = min(a[i].a, mm);
      ans += a[i].a;
      sum += a[i].a;
      mm -= a[i].a;
    }
  }
  printf("%lld\n", ans);
}