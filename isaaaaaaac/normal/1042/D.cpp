#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 2e5 + 50;

namespace Bit {
#define lb(x) (x & (- x))
  LL a[N];
  int vis[N], cur;
  inline void Init() { cur ++; }
  inline void Add(int p, LL v) {
    for (; p < N; p += lb(p)) {
      if (vis[p] == cur) a[p] += v;
      else vis[p] = cur, a[p] = v;
    }
  }
  inline LL Sum(int p) {
    LL res = 0;
    for (; p > 0; p -= lb(p))
      if (vis[p] == cur) res += a[p];
    return res;
  }
}

int n;
LL t, a[N], tab[N];

inline int find(LL x) {
  return lower_bound(tab + 1, tab + n + 2, x) - tab;
}

int main() {
  scanf("%d%lld", &n, &t);
  for (int i = 1; i <= n; i ++) {
    scanf("%lld", &a[i]);
    a[i] += a[i - 1];
    tab[i] = a[i];
  }
  LL ans = 0;
  sort(tab + 1, tab + n + 2);
  Bit :: Add(find(0), 1);
  for (int i = 1, p, q; i <= n; i ++) {
    p = find(a[i]);
    q = find(a[i] - t);
    if (tab[q] > a[i] - t) q --;
    ans += i - Bit :: Sum(q);
    Bit :: Add(p, 1);
  }
  printf("%lld\n", ans);
  return 0;
}