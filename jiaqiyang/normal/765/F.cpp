#include <cmath>
#include <cctype>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <algorithm>

const int N = 100000 + 10, S = 640, INF = 1e9 + 7;

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int n, m, size, a[N], pos[N], sorted[N];

int succ[N], pred[N], table[S][N];

void init() {
  for (int i = 1; i <= n; ++i) table[1][i] = INF;
  for (int i = 2; i <= size; ++i)
    for (int j = 1; j + i - 1 <= n; ++j)
      table[i][j] = std::min(std::min(table[i - 1][j], table[i - 1][j + 1]), abs(a[j] - a[j + i - 1]));
  static std::pair<int, int> info[N];
  for (int i = 1; i <= n; ++i) info[i] = std::make_pair(a[i], i);
  std::sort(info + 1, info + n + 1);
  for (int i = 1; i <= n; ++i) a[i] = std::lower_bound(info + 1, info + n + 1, std::make_pair(a[i], i)) - info;
  for (int i = 1; i <= n; ++i) pos[a[i]] = i;
  for (int i = 1; i <= n; ++i) sorted[i] = info[i].first;
  pos[n + 1] = n + 1;
}

struct Query {
  int l, r, id;
  inline bool operator< (const Query &rhs) const {
    return r < rhs.r;
  }
};

std::vector<Query> pool[S];

int ans[3 * N];

void del(int x) {
  pred[succ[x]] = pred[x];
  succ[pred[x]] = succ[x];
}

int ins(int x) {
  int res = INF;
  int t = succ[x];
  if (t <= n) res = sorted[t] - sorted[x];
  t = pred[x];
  if (t) res = std::min(res, sorted[x] - sorted[t]);
  succ[pred[x]] = pred[succ[x]] = x;
  return res;
}

void clear() {
  for (int i = 1; i <= n; ++i) pred[i] = i - 1, succ[i] = i + 1;
  pred[n + 1] = n;
  succ[0] = 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) a[i] = nextInt();
  size = n / sqrt(n + m) + .5;
  init();
  m = nextInt();
  for (int i = 1; i <= m; ++i) {
    Query cur;
    cur.l = nextInt();
    cur.r = nextInt();
    cur.id = i;
    if (cur.r - cur.l + 1 <= size) ans[i] = table[cur.r - cur.l + 1][cur.l]; else pool[cur.l / size].push_back(cur);
  }
  for (int i = 0; i < S; ++i) {
    if (pool[i].empty()) continue;
    clear();
    int p = i * size + size - 1, q = i * size;
    static int mem[N];
    for (int j = 1; j < p; ++j) del(a[j]);
    for (int j = n; j > p; --j) del(a[j]);
    mem[p] = INF;
    for (int j = p + 1; j <= n; ++j) mem[j] = std::min(mem[j - 1], ins(a[j]));
    for (int j = p - 1; j >= q; --j) ins(a[j]);
    std::sort(pool[i].begin(), pool[i].end());
    int k = n;
    for (int j = pool[i].size() - 1; j >= 0; --j) {
      const Query &info = pool[i][j];
      for (; k > info.r; --k) del(a[k]);
      int cur = mem[info.r];
      for (int t = q; t < p; ++t) del(a[t]);
      for (int t = p - 1; t >= info.l; --t) cur = std::min(cur, ins(a[t]));
      for (int t = info.l - 1; t >= q; --t) ins(a[t]);
      ans[info.id] = cur;
    }
  }
  for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
  return 0;
}