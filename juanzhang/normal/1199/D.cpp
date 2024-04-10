#include <bits/stdc++.h>
using namespace std;

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

const int maxn = 2e5 + 10;
int n, m, a[maxn], val[maxn << 2], tag[maxn << 2];

void pushtag(int k) {
  tag[k << 1] = max(tag[k << 1], tag[k]);
  tag[k << 1 | 1] = max(tag[k << 1 | 1], tag[k]);
  tag[k] = 0;
}

void build(int k, int l, int r) {
  if (l == r) {
    val[k] = a[l]; return;
  }
  build(lson), build(rson);
}

void ins(int k, int l, int r, int x, int v) {
  if (l == r) {
    val[k] = v, tag[k] = 0; return;
  }
  pushtag(k);
  if (x <= mid) ins(lson, x, v);
  if (x > mid) ins(rson, x, v);
  tag[k] = 0;
}

void print(int k, int l, int r) {
  if (l == r) {
    printf("%d ", max(val[k], tag[k])); return;
  }
  pushtag(k);
  print(lson), print(rson);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  build(1, 1, n);
  scanf("%d", &m);
  while (m--) {
    int op, x, y;
    scanf("%d %d", &op, &x);
    if (op == 1) {
      scanf("%d", &y);
      ins(1, 1, n, x, y);
    } else {
      tag[1] = max(tag[1], x);
    }
  }
  print(1, 1, n);
  return 0;
}