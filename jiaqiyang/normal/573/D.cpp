#include <cstdio>
#include <iostream>
#include <algorithm>

#define fst first
#define snd second

typedef std::pair<int, int> Info;
typedef long long i64;

const int N = 30000 + 10;
const i64 INF = 1LL << 60;

inline void check(i64 &lhs, i64 rhs) { if (rhs > lhs) lhs = rhs; }

int n;

int a[N], b[N];

Info w[N], h[N];

i64 g[N][3];

int tag[N];

void touch(int i) {
  if (i <= 0) return;
  g[i][0] = g[i][1] = g[i][2] = -INF;
  if (tag[i] != i) g[i][0] = (i64)a[i] * b[i];
  if (tag[i] != i + 1 && tag[i + 1] != tag[i]) g[i][1] = (i64)a[i] * b[i + 1] + (i64)a[i + 1] * b[i];
  if (tag[i] != i + 1 && tag[i + 1] != i + 2 && tag[i + 2] != i) g[i][2] = (i64)a[i] * b[i + 1] + (i64)a[i + 1] * b[i + 2] + (i64)a[i + 2] * b[i];
  if (tag[i] != i + 2 && tag[i + 1] != i && tag[i + 2] != i + 1) check(g[i][2], (i64)a[i] * b[i + 2] + (i64)a[i + 1] * b[i] + (i64)a[i + 2] * b[i + 1]);
}

i64 solve() {
  static i64 f[N];
  for (int i = 1; i <= n + 1; ++i) f[i] = -INF;
  f[1] = 0;
  for (int i = 1; i <= n; ++i) {
    check(f[i + 1], f[i] + g[i][0]);
    check(f[i + 2], f[i] + g[i][1]);
    check(f[i + 3], f[i] + g[i][2]);
  }
  return f[n + 1];
}

int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &w[i].fst), w[i].snd = i;
  for (int i = 1; i <= n; ++i) scanf("%d", &h[i].fst), h[i].snd = i;
  std::sort(w + 1, w + n + 1);
  std::sort(h + 1, h + n + 1);
  for (int i = 1; i <= n; ++i) a[i] = h[i].fst, b[i] = w[i].fst;
  static int p[N], q[N];
  for (int i = 1; i <= n; ++i) p[h[i].snd] = i;
  for (int i = 1; i <= n; ++i) q[w[i].snd] = i;
  for (int i = 1; i <= n; ++i) tag[p[i]] = q[i];
  for (int i = 1; i <= n; ++i) touch(i);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    std::swap(p[a], p[b]);
    tag[p[a]] = q[a];
    tag[p[b]] = q[b];
    touch(p[a] - 2);
    touch(p[a] - 1);
    touch(p[a]);
    touch(p[b] - 2);
    touch(p[b] - 1);
    touch(p[b]);
    std::cout << solve() << '\n';
  }
  return 0;
}