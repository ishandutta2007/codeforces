#include <cctype>
#include <cstdio>
#include <cstring>
#include <vector>

typedef std::pair<int, int> Info;

const int N = 500000 + 10, S = 50 + 1;

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int n, m, k, q, a[N], b[N], e[N], c[N], succ[N];

std::vector<Info> pool[2 * N];

inline int pos(int l, int r) { return (l + r) | (l != r); }

void modify(int l, int r, int p, int q, const Info &info) {
  if (p <= l && r <= q) {
    pool[pos(l, r)].push_back(info);
    return;
  }
  int mid = (l + r) / 2;
  if (p <= mid) modify(l, mid, p, q, info);
  if (q > mid) modify(mid + 1, r, p, q, info);
}

class DSU {
  int anc[N], size[N];
  bool col[N];
  int p[N], top;
 public:
  inline void init(int n) {
    for (int i = 1; i <= n; ++i) anc[i] = i, size[i] = 1;
    top = 0;
  }
  int find(int x) { return anc[x] == x ? x : find(anc[x]); }
  bool eval(int x) { return anc[x] == x ? col[x] : (col[x] ^ eval(anc[x])); }
  void link(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return;
    if (size[x] > size[y]) std::swap(a, b), std::swap(x, y);
    p[++top] = x;
    anc[x] = y;
    size[y] += size[x];
    if (eval(a) == eval(b)) col[x] ^= 1;
  }
  inline int save() { return top; }
  inline void load(int x) {
    for (; top > x; --top) {
      int a = p[top], b = anc[a];
      size[b] -= size[a];
      anc[a] = a;
    }
  }
} dsu[S];

int cur[N];

void solve(int l, int r) {
  int id = pos(l, r);
  std::vector<int> mem(k + 1);
  for (int i = 1; i <= k; ++i) mem[i] = dsu[i].save();
  for (int j = 0; j < pool[id].size(); ++j) dsu[pool[id][j].first].link(a[pool[id][j].second], b[pool[id][j].second]);
  if (l < r) {
    int mid = (l + r) / 2;
    solve(l, mid);
    solve(mid + 1, r);
  } else {
    int x = e[l], y = c[l];
    if (dsu[y].find(a[x]) == dsu[y].find(b[x]) && dsu[y].eval(a[x]) == dsu[y].eval(b[x])) puts("NO"); else puts("YES"), cur[x] = y;
    if (l < q) modify(1, q, l + 1, succ[l], Info(cur[x], x));
  }
  for (int i = 1; i <= k; ++i) dsu[i].load(mem[i]);
}

int main() {
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 1; i <= m; ++i) a[i] = nextInt(), b[i] = nextInt();
  for (int i = 1; i <= k; ++i) dsu[i].init(n);
  for (int i = 1; i <= q; ++i) e[i] = nextInt(), c[i] = nextInt();
  static int temp[N];
  for (int i = 1; i <= m; ++i) temp[i] = q;
  for (int i = q; i > 0; --i) succ[i] = temp[e[i]], temp[e[i]] = i;
  solve(1, q);
  return 0;
}