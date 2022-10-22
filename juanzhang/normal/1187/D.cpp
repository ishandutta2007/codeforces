#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int n, m, a[maxn], b[maxn];

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

int val[maxn << 2];

void maintain(int k) {
  val[k] = min(val[k << 1], val[k << 1 | 1]);
}

void build(int k, int l, int r) {
  if (l == r) {
    val[k] = a[l]; return;
  }
  build(lson), build(rson);
  maintain(k);
}

void upd(int k, int l, int r, int x) {
  if (l == r) {
    val[k] = 1 << 30; return;
  }
  x <= mid ? upd(lson, x) : upd(rson, x);
  maintain(k);
}

int query(int k, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    return val[k];
  }
  int res = 1 << 30;
  if (ql <= mid) res = query(lson, ql, qr);
  if (qr > mid) res = min(res, query(rson, ql, qr));
  return res;
}

#undef mid
#undef lson
#undef rson

vector <int> vec[maxn];

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    vec[i].clear();
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", b + i);
  }
  for (int i = 1; i <= n; i++) {
    vec[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    reverse(vec[i].begin(), vec[i].end());
  }
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    if (vec[b[i]].empty()) {
      puts("NO"); return;
    }
    int pos = vec[b[i]].back();
    vec[b[i]].pop_back();
    if (query(1, 1, n, 1, pos) < b[i]) {
      puts("NO"); return;
    }
    upd(1, 1, n, pos);
  }
  puts("YES");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}