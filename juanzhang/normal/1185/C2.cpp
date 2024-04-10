#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, m, a[maxn];

int sz[maxn << 2], sum[maxn << 2];

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

void ins(int k, int l, int r, int x) {
  sum[k] += x, sz[k]++;
  if (l == r) return;
  x <= mid ? ins(lson, x) : ins(rson, x);
}

int query(int k, int l, int r, int v) {
  if (l == r) return (v + l - 1) / l;
  if (v <= sum[k << 1 | 1]) {
    return query(rson, v);
  } else {
    return sz[k << 1 | 1] + query(lson, v - sum[k << 1 | 1]);
  }
}

#undef mid
#undef lson
#undef rson

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    printf("%d ", sum > m ? query(1, 1, 100, sum - m) : 0);
    ins(1, 1, 100, a[i]);
  }
  return 0;
}