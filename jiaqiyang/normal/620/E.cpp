#include <cctype>
#include <cstdio>
#include <stack>
#include <vector>

typedef long long i64;

const int N = 400000 + 10;

inline int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int tag[2 * N];
i64 mask[2 * N];

inline int pos(int l, int r) { return (l + r) | (l != r); }

void build(int l, int r) {
  int id = pos(l, r);
  if (l == r) return;
  int mid = (l + r) / 2, lch = pos(l, mid), rch = pos(mid + 1, r);
  build(l, mid);
  build(mid + 1, r);
  mask[id] = mask[lch] | mask[rch];
}

inline void apply(int id, int v) {
  tag[id] = v;
  mask[id] = 1LL << v;
}

void modify(int l, int r, int p, int q, int v) {
  int id = pos(l, r);
  if (p <= l && r <= q) {
    apply(id, v);
    return;
  }
  int mid = (l + r) / 2, lch = pos(l, mid), rch = pos(mid + 1, r);
  if (tag[id]) {
    apply(lch, tag[id]);
    apply(rch, tag[id]);
    tag[id] = 0;
  }
  if (p <= mid) modify(l, mid, p, q, v);
  if (q > mid) modify(mid + 1, r, p, q, v);
  mask[id] = mask[lch] | mask[rch];
}

i64 query(int l, int r, int p, int q) {
  int id = pos(l, r);
  if (p <= l && r <= q) return mask[id];
  int mid = (l + r) / 2, lch = pos(l, mid), rch = pos(mid + 1, r);
  if (tag[id]) {
    apply(lch, tag[id]);
    apply(rch, tag[id]);
    tag[id] = 0;
  }
  i64 res = 0;
  if (p <= mid) res |= query(l, mid, p, q);
  if (q > mid) res |= query(mid + 1, r, p, q);
  mask[id] = mask[lch] | mask[rch];
  return res;
}

int n, m;
std::vector<int> adj[N];

int fa[N], left[N], right[N];

void dfs() {
  std::stack<int> stk;
  stk.push(1);
  static int arc[N];
  for (int i = 1; i <= n; ++i) arc[i] = 0;
  int tot = 0;
  while (!stk.empty()) {
    int a = stk.top();
    if (!left[a]) left[a] = ++tot;
    int &i = arc[a];
    if (i < adj[a].size()) {
      int b = adj[a][i++];
      if (b != fa[a]) {
        fa[b] = a;
        stk.push(b);
      }
      continue;
    }
    right[a] = tot;
    stk.pop();
  }
}

int main() {
  n = nextInt();
  m = nextInt();
  static int col[N];
  for (int i = 1; i <= n; ++i) col[i] = nextInt();
  for (int i = n - 1; i--;) {
    int x = nextInt();
    int y = nextInt();
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs();
  for (int i = 1; i <= n; ++i) mask[pos(left[i], left[i])] = 1LL << col[i];
  build(1, n);
  while (m--) {
    int op = nextInt();
    if (op == 1) {
      int v = nextInt(), c = nextInt();
      modify(1, n, left[v], right[v], c);
    } else {
      int v = nextInt();
      printf("%d\n", __builtin_popcountll(query(1, n, left[v], right[v])));
    }
  }
  return 0;
}