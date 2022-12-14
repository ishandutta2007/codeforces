#include <cctype>
#include <stdio.h>
#include <algorithm>

#define fst first
#define snd second

typedef std::pair<int, int> Pair;
typedef long long i64;

const int N = 1000000 + 10, INF = 0x3f3f3f3f;

inline int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int n, k, val[N];

inline int eval(const Pair &p) { return val[p.fst] + val[p.snd]; }
inline int getMin(int lhs, int rhs) { return val[lhs] < val[rhs] ? lhs : rhs; }
inline Pair merge(const Pair &lhs, const Pair &rhs) { return eval(lhs) < eval(rhs) ? lhs : rhs; }

struct Info {
  int a1, a2, a3, a4, min;
  Pair r1, r2, r3;
} info[2 * N];

inline Info operator+ (const Info &lhs, const Info &rhs) {
  Info res;
  res.min = std::min(lhs.min, rhs.min);
  res.a1 = getMin(lhs.a1, rhs.a1);
  res.a2 = getMin(lhs.a2, rhs.a2);
  res.r1 = merge(merge(lhs.r1, rhs.r1), Pair(lhs.a1, rhs.a2));
  res.r2 = merge(merge(lhs.r2, rhs.r2), Pair(lhs.a2, rhs.a1));
  if (lhs.min < rhs.min) {
    res.a3 = lhs.a3;
    res.a4 = getMin(rhs.a2, lhs.a4);
    res.r3 = merge(merge(rhs.r2, lhs.r3), Pair(lhs.a4, rhs.a1));
  } else if (lhs.min > rhs.min) {
    res.a3 = getMin(lhs.a1, rhs.a3);
    res.a4 = rhs.a4;
    res.r3 = merge(merge(lhs.r2, rhs.r3), Pair(lhs.a2, rhs.a3));
  } else {
    res.a3 = lhs.a3;
    res.a4 = rhs.a4;
    res.r3 = merge(merge(lhs.r3, rhs.r3), Pair(lhs.a4, rhs.a3));
  }
  return res;
}

int tag[2 * N];

inline int pos(int l, int r) { return (l + r) | (l != r); }

void build(int l, int r) {
  int id = pos(l, r);
  if (l == r) {
    if (l & 1) info[id].a1 = l; else info[id].a2 = l;
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid);
  build(mid + 1, r);
  info[id] = info[pos(l, mid)] + info[pos(mid + 1, r)];
}

inline void apply(int id, int v) {
  tag[id] += v;
  info[id].min += v;
}

void add(int l, int r, int p, int q, int v) {
  int id = pos(l, r);
  if (p <= l && r <= q) {
    apply(id, v);
    return;
  }
  int mid = (l + r) / 2, lch = pos(l, mid), rch = pos(mid + 1, r);
  if (tag[id]) apply(lch, tag[id]), apply(rch, tag[id]), tag[id] = 0;
  if (p <= mid) add(l, mid, p, q, v);
  if (q > mid) add(mid + 1, r, p, q, v);
  info[id] = info[lch] + info[rch];
}

int main() {
  n = nextInt();
  k = nextInt();
  for (int i = 1; i <= n; ++i) val[2 * i - 1] = nextInt();
  val[0] = INF;
  int m = 2 * n;
  build(1, m);
  i64 ans = 0;
  while (k--) {
    Pair cur = merge(info[pos(1, m)].r1, info[pos(1, m)].r3);
    ans += eval(cur);
    add(1, m, cur.fst, cur.snd - 1, (cur.fst & 1) ? 1 : -1);
    val[cur.fst] = INF, add(1, m, cur.fst, cur.fst, 0);
    val[cur.snd] = INF, add(1, m, cur.snd, cur.snd, 0);
  }
  printf("%lld\n", ans);
  return 0;
}