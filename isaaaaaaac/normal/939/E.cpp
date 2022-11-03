#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long double LD;
typedef long long LL;
const int N = 5e5 + 5;

LL a[N];
int q, n = 0;
LD ans = 0;

inline void Upd() {
  int L = 1, R = n - 1, k, l, r;
  LD A, B;
  while (R - L + 1 >= 3) {
    k = (R - L + 1) / 3;
    l = L + k;
    r = R - k;
    A = a[n] - a[n - 1] - (LD)(a[l] + a[n] - a[n - 1]) / (l + 1);
    B = a[n] - a[n - 1] - (LD)(a[r] + a[n] - a[n - 1]) / (r + 1);
    if (A < B) L = l;
    else R = r;
    ans = max(ans, max(A, B));
  }
  for (int i = L; i <= R; i ++)
    ans = max(ans, a[n] - a[n - 1] - (LD)(a[i] + a[n] - a[n - 1]) / (i + 1));
}

int main() {
  scanf("%d", &q);
  for (int i = 1, t; i <= q; i ++) {
    scanf("%d", &t);
    if (t == 1) {
      n ++;
      scanf("%lld", &a[n]);
      a[n] += a[n - 1];
      Upd();
    }
    else printf("%.10Lf\n", ans);
  }
  return 0;
}