#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 100000 + 10, S = 40 * N;

int n, a[N], root[N];

int lch[S], rch[S], size[S], tot = 0;

int add(int id, int l, int r, int p) {
  int res = ++tot;
  lch[res] = lch[id], rch[res] = rch[id], size[res] = size[id] + 1;
  if (l == r) return res;
  int mid = (l + r) >> 1;
  if (p <= mid) lch[res] = add(lch[id], l, mid, p); else rch[res] = add(rch[id], mid + 1, r, p);
  return res;
}

int cnt, val;

void query(int id, int l, int r, int p, int q) {
  if (!id || !cnt) return;
  if (p <= l && r <= q) {
    if (cnt > size[id]) {
      cnt -= size[id];
      return;
    }
    if (l == r) {
      if (cnt == size[id]) {
        --cnt;
        val = l;
      }
      return;
    }
  }
  int mid = (l + r) >> 1;
  if (p <= mid) query(lch[id], l, mid, p, q);
  if (q > mid) query(rch[id], mid + 1, r, p, q);
}

void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  static int b[N], last[N];
  for (int i = 1; i <= n; ++i) b[i] = last[a[i]], last[a[i]] = i;
  static std::pair<int, int> pool[N];
  for (int i = 1; i <= n; ++i) pool[i] = {b[i], i};
  std::sort(pool + 1, pool + n + 1);
  for (int i = 1, j = 1; i <= n; ++i) {
    root[i] = root[i - 1];
    for (; j <= n && pool[j].first < i; ++j) root[i] = add(root[i], 1, n, pool[j].second);
  }
}

int solve(int k) {
  int res = 0;
  for (int i = 1; i <= n;) {
    ++res;
    cnt = k + 1;
    val = n + 1;
    query(root[i], 1, n, i, n);
    i = val;
  }
  return res;
}

int main() {
  init();
  for (int i = 1; i <= n; ++i) printf("%d ", solve(i));
  return 0;
}