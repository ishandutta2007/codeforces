#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10, M = 12;

int n, q;

i64 mem[M];

bool flag[2 * N];
i64 min[2 * N], tag[2 * N], val[2 * N];

inline int pos(int l, int r) { return (l + r) | (l != r); }

void release(int l, int r) {
  int id = pos(l, r), mid = (l + r) / 2;
  int lch = pos(l, mid), rch = pos(mid + 1, r);
  if (flag[id]) {
    flag[lch] = flag[rch] = true;
    min[lch] = min[rch] = min[id];
    val[lch] = val[rch] = val[id];
    tag[id] = 0;
    flag[id] = false;
  }
  if (tag[id]) {
    tag[lch] += tag[id];
    tag[rch] += tag[id];
    min[lch] -= tag[id];
    min[rch] -= tag[id];
    tag[id] = 0;
  }
}

void update(int l, int r) {
  int id = pos(l, r), mid = (l + r) / 2;
  int lch = pos(l, mid), rch = pos(mid + 1, r);
  min[id] = std::min(min[lch], min[rch]);
}

bool get(i64 x, i64 &a, i64 &b) {
  for (int i = 0;; ++i) {
    if (x < mem[i]) {
      b = (a = mem[i]) - x;
      return x == mem[i - 1];
    }
  }
}

void build(int l, int r) {
  int id = pos(l, r);
  if (l == r) {
    int x;
    scanf("%d", &x);
    get(x, val[id], min[id]);
    flag[id] = true;
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid);
  build(mid + 1, r);
  update(l, r);
}

i64 query(int l, int r, int p) {
  int id = pos(l, r);
  if (flag[id]) return val[id] - min[id];
  int mid = (l + r) / 2;
  release(l, r);
  i64 res = (p <= mid ? query(l, mid, p) : query(mid + 1, r, p));
  update(l, r);
  return res;
}

void modify(int l, int r, int p, int q, i64 a, i64 b) {
  int id = pos(l, r);
  if (p <= l && r <= q) {
    flag[id] = true;
    val[id] = a;
    min[id] = b;
    tag[id] = 0;
    return;
  }
  release(l, r);
  int mid = (l + r) / 2;
  if (p <= mid) modify(l, mid, p, q, a, b);
  if (q > mid) modify(mid + 1, r, p, q, a, b);
  update(l, r);
}

bool add(int l, int r, int p, int q, int x) {
  int id = pos(l, r);
  if (p <= l && r <= q && (x < min[id] || flag[id])) {
    tag[id] += x;
    min[id] -= x;
    bool res = false;
    if (min[id] <= 0) res = get(val[id] - min[id], val[id], min[id]);
    return res;
  }
  int mid = (l + r) / 2;
  release(l, r);
  bool res = false;
  if (p <= mid) res |= add(l, mid, p, q, x);
  if (q > mid) res |= add(mid + 1, r, p, q, x);
  update(l, r);
  return res;
}

int main() {
  scanf("%d%d", &n, &q);
  mem[0] = 1;
  for (int i = 1; i < M; ++i) mem[i] = 42 * mem[i - 1];
  build(1, n);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int x;
      scanf("%d", &x);
      printf("%I64d\n", query(1, n, x));
    } else {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      if (op == 2) {
        i64 a, b;
        get(x, a, b);
        modify(1, n, l, r, a, b);
      } else {
        while (add(1, n, l, r, x)) {}
      }
    }
  }
  return 0;
}