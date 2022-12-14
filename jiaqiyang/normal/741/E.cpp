#include <cctype>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 200000 + 10, S = 300;

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int n, m, tot;
char s[N], t[N], text[N];

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

class SA {
  int sa[N], rank[N], h[N], gap;
  bool sufComp(int a, int b) {
    if (rank[a] != rank[b]) return rank[a] < rank[b];
    a += gap, b += gap;
    return a <= tot && b <= tot ? rank[a] < rank[b] : a > b;
  }
  int table[20][N], lg2[N];
 public:
  void build() {
    static int sum[N], temp[N];
    memset(sum, 0, sizeof sum);
    for (int i = 1; i <= tot; ++i) ++sum[rank[i] = text[i]];
    for (int i = 1; i <= 256; ++i) sum[i] += sum[i - 1];
    for (int i = 1; i <= tot; ++i) sa[sum[rank[i]]--] = i;
    for (int i = 1; i <= tot; ++i) temp[i] = temp[i - 1] + sufComp(sa[i - 1], sa[i]);
    for (int i = 1; i <= tot; ++i) rank[sa[i]] = temp[i];
    for (gap = 1;; gap *= 2) {
      for (int i = 1; i <= gap; ++i) temp[i] = tot - i + 1;
      for (int i = 1, cnt = gap; i <= tot; ++i) if (sa[i] > gap) temp[++cnt] = sa[i] - gap;
      memset(sum, 0, sizeof sum);
      for (int i = 1; i <= tot; ++i) ++sum[rank[i]];
      for (int i = 1; i <= tot; ++i) sum[i] += sum[i - 1];
      for (int i = tot; i > 0; --i) sa[sum[rank[temp[i]]]--] = temp[i];
      for (int i = 1; i <= tot; ++i) temp[i] = temp[i - 1] + sufComp(sa[i - 1], sa[i]);
      for (int i = 1; i <= tot; ++i) rank[sa[i]] = temp[i];
      if (rank[sa[tot]] == tot) break;
    }
    for (int i = 1, k = 0; i <= tot; ++i) {
      if (rank[i] == 1) continue;
      for (int j = sa[rank[i] - 1]; text[i + k] == text[j + k];) ++k;
      h[rank[i]] = k;
      if (k) --k;
    }
    for (int i = 1; i < N; ++i) lg2[i] = 31 - __builtin_clz(i);
    for (int i = 1; i <= tot; ++i) table[0][i] = h[i];
    for (int i = 1; i < 20; ++i)
      for (int j = 1; j + (1 << (i - 1)) <= tot; ++j)
        table[i][j] = MIN(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
  }
  int lcp(int a, int b) {
    if (a == b) return tot - a + 1;
    a = rank[a], b = rank[b];
    if (a > b) std::swap(a, b);
    ++a;
    int k = lg2[b - a + 1];
    return MIN(table[k][a], table[k][b - (1 << k) + 1]);
  }
} sa;

int id[N], rank[N];

bool comp(int x, int y) {
  if (x == y || x == -1) return false;
  if (y == -1) return true;
  if (x > y) return !comp(y, x);
  if (x + m < y) {
    int v = sa.lcp(n + 2, x + 1);
    if (v < m) return t[1 + v] < s[x + 1 + v];
    v = sa.lcp(x + 1, x + m + 1);
    if (v < y - (x + m)) return s[x + 1 + v] < s[x + m + 1 + v];
    v = sa.lcp(n + 2, y + 1 - m);
    if (v < m) return s[y + 1 - m + v] < t[1 + v];
  } else {
    int v = sa.lcp(n + 2, x + 1);
    if (v < y - x) return t[1 + v] < s[x + 1 + v];
    v = sa.lcp(n + 2, n + 2 + y - x);
    if (v < x + m - y) return t[y - x + 1 + v] < t[1 + v];
    v = sa.lcp(x + 1, n + 2 + (x + m) - y);
    if (v < y - x) return s[x + 1 + v] < t[1 + x + m - y + v];
  }
  return x < y;
}

inline int min(int a, int b) {
  if (a == -1) return b;
  if (b == -1) return a;
  return rank[a] < rank[b] ? a : b;
}

int pool[40 * N], *top;

int *init(int len) {
  int *res = top;
  top += len;
  return res;
}

class Seg {
  int n, *data;
 public:
  void build(int k, int i) {
    int tot = (::n - i) / k + 1;
    n = 1;
    while (n <= tot) n *= 2;
    data = init(2 * n);
    memset(data, -1, 2 * n * sizeof(int));
    for (int j = 0; j * k + i <= ::n; ++j) data[n + j + 1] = j * k + i;
    for (int j = n - 1; j > 0; --j) data[j] = min(data[j << 1], data[j << 1 | 1]);
  }
  int query(int l, int r) {
    int res = -1;
    for (l = l + n - 1, r = r + n + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
      if (!(l & 1)) res = min(res, data[l + 1]);
      if (r & 1) res = min(res, data[r - 1]);
    }
    return res;
  }
} seg[S];

inline int cdiv(int x, int y) {
  return x >= 0 ? (x + y - 1) / y : -(-x / y);
}

inline int fdiv(int x, int y) {
  return x >= 0 ? x / y : -((-x + y - 1) / y);
}

int q;

struct Query {
  int l, r, k, x, y;
} query[N];

int ans[N];

std::vector<int> mem[N];

void solve1(int k) {
  for (int it = 0; it < mem[k].size(); ++it) {
    int i = mem[k][it];
    for (int j = query[i].x; j <= query[i].y; ++j) {
      int p = cdiv(query[i].l - j, k), q = fdiv(query[i].r - j, k);
      if (p <= q) ans[i] = min(ans[i], seg[j].query(p + 1, q + 1));
    }
  }
}

void solve2(int k) {
  for (int it = 0; it < mem[k].size(); ++it) {
    int i = mem[k][it];
    for (int j = 0; j <= n; j += k) {
      int p = MAX(j + query[i].x, query[i].l), q = MIN(j + query[i].y, query[i].r);
      if (p <= q) ans[i] = min(ans[i], seg[0].query(p + 1, q + 1));
    }
  }
}

int main() {
  scanf(" %s %s%d", s + 1, t + 1, &q);
  n = strlen(s + 1);
  m = strlen(t + 1);
  for (int i = 1; i <= n; ++i) text[++tot] = s[i];
  text[++tot] = '$';
  for (int i = 1; i <= m; ++i) text[++tot] = t[i];
  text[++tot] = '#';
  sa.build();
  for (int i = 0; i <= n; ++i) id[i] = i;
  std::sort(id, id + n + 1, comp);
  rank[id[0]] = 0;
  for (int i = 1; i <= n; ++i) rank[id[i]] = rank[id[i - 1]] + comp(id[i - 1], id[i]);
  for (int i = 1; i <= q; ++i) query[i].l = nextInt(), query[i].r = nextInt(), query[i].k = nextInt(), query[i].x = nextInt(), query[i].y = nextInt();
  for (int i = 1; i <= q; ++i) mem[query[i].k].push_back(i);
  std::fill(ans + 1, ans + q + 1, -1);
  for (int i = 1; i < S; ++i) {
    if (mem[i].empty()) continue;
    top = pool;
    for (int j = 0; j < i; ++j) seg[j].build(i, j);
    solve1(i);
  }
  top = pool;
  seg[0].build(1, 0);
  for (int i = S; i <= n; ++i) solve2(i);
  for (int i = 1; i <= q; ++i) printf("%d ", ans[i]);
  return 0;
}