#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
int n, m, a[maxn];

struct segment_tree {
  #define mid ((l + r) >> 1)
  #define lson k << 1, l, mid
  #define rson k << 1 | 1, mid + 1, r

  int tag[maxn << 2], sum[maxn << 2];

  void maintain(int k) {
    sum[k] = sum[k << 1] + sum[k << 1 | 1];
  }

  void pushlazy(int k, int l) {
    tag[k] ^= 1, sum[k] = l - sum[k];
  }

  void pushdown(int k, int l) {
    if (!tag[k]) return;
    pushlazy(k << 1, (l + 1) >> 1);
    pushlazy(k << 1 | 1, l >> 1);
    tag[k] = 0;
  }

  void build(int k, int l, int r, int bit) {
    if (l == r) {
      sum[k] = a[l] >> bit & 1;
      return;
    }
    build(lson, bit), build(rson, bit);
    maintain(k);
  }

  void upd(int k, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
      pushlazy(k, r - l + 1); return;
    }
    pushdown(k, r - l + 1);
    if (ql <= mid) upd(lson, ql, qr);
    if (qr > mid) upd(rson, ql, qr);
    maintain(k);
  }

  int query(int k, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
      return sum[k];
    }
    pushdown(k, r - l + 1);
    int res = 0;
    if (ql <= mid) res = query(lson, ql, qr);
    if (qr > mid) res += query(rson, ql, qr);
    return res;
  }
} tree[20];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  scanf("%d", &m);
  for (int i = 0; i < 20; i++) {
    tree[i].build(1, 1, n, i);
  }
  int op, l, r, x;
  while (m--) {
    scanf("%d %d %d", &op, &l, &r);
    if (op == 1) {
      ll ans = 0;
      for (int i = 0; i < 20; i++) {
        ans += (ll) tree[i].query(1, 1, n, l, r) << i;
      }
      printf("%I64d\n", ans);
    } else {
      scanf("%d", &x);
      for (int i = 0; i < 20; i++) {
        if (x >> i & 1) tree[i].upd(1, 1, n, l, r);
      }
    }
  }
  return 0;
}