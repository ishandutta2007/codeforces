#include <bits/stdc++.h>
#ifdef LOCAL
#define dbg(args...) std::cerr << "\033[32;1m" << #args << " -> ", err(args)
#else
#define dbg(...)
#endif
inline void err() { std::cerr << "\033[0m\n"; }
template<class T, class... U>
inline void err(const T &x, const U &... a) { std::cerr << x << ' '; err(a...); }
template <class T>
inline void readInt(T &w) {
  char c, p = 0;
  while (!isdigit(c = getchar())) p = c == '-';
  for (w = c & 15; isdigit(c = getchar());) w = w * 10 + (c & 15);
  if (p) w = -w;
}
template <class T, class... U>
inline void readInt(T &w, U &... a) { readInt(w), readInt(a...); }
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }

typedef long long LL;
typedef std::pair<int, int> PII;

using Matrix = std::array<std::array<int, 4>, 4>;
Matrix operator*(const Matrix &a, const Matrix &b) {
  Matrix r;
  r[0][0] = std::max({ a[0][0] + b[0][0], a[0][1] + b[1][0], a[0][2] + b[2][0], a[0][3] + b[3][0] });
  r[0][1] = std::max({ a[0][0] + b[0][1], a[0][1] + b[1][1], a[0][2] + b[2][1], a[0][3] + b[3][1] });
  r[0][2] = std::max({ a[0][0] + b[0][2], a[0][1] + b[1][2], a[0][2] + b[2][2], a[0][3] + b[3][2] });
  r[0][3] = std::max({ a[0][0] + b[0][3], a[0][1] + b[1][3], a[0][2] + b[2][3], a[0][3] + b[3][3] });
  r[1][0] = std::max({ a[1][0] + b[0][0], a[1][1] + b[1][0], a[1][2] + b[2][0], a[1][3] + b[3][0] });
  r[1][1] = std::max({ a[1][0] + b[0][1], a[1][1] + b[1][1], a[1][2] + b[2][1], a[1][3] + b[3][1] });
  r[1][2] = std::max({ a[1][0] + b[0][2], a[1][1] + b[1][2], a[1][2] + b[2][2], a[1][3] + b[3][2] });
  r[1][3] = std::max({ a[1][0] + b[0][3], a[1][1] + b[1][3], a[1][2] + b[2][3], a[1][3] + b[3][3] });
  r[2][0] = std::max({ a[2][0] + b[0][0], a[2][1] + b[1][0], a[2][2] + b[2][0], a[2][3] + b[3][0] });
  r[2][1] = std::max({ a[2][0] + b[0][1], a[2][1] + b[1][1], a[2][2] + b[2][1], a[2][3] + b[3][1] });
  r[2][2] = std::max({ a[2][0] + b[0][2], a[2][1] + b[1][2], a[2][2] + b[2][2], a[2][3] + b[3][2] });
  r[2][3] = std::max({ a[2][0] + b[0][3], a[2][1] + b[1][3], a[2][2] + b[2][3], a[2][3] + b[3][3] });
  r[3][0] = std::max({ a[3][0] + b[0][0], a[3][1] + b[1][0], a[3][2] + b[2][0], a[3][3] + b[3][0] });
  r[3][1] = std::max({ a[3][0] + b[0][1], a[3][1] + b[1][1], a[3][2] + b[2][1], a[3][3] + b[3][1] });
  r[3][2] = std::max({ a[3][0] + b[0][2], a[3][1] + b[1][2], a[3][2] + b[2][2], a[3][3] + b[3][2] });
  r[3][3] = std::max({ a[3][0] + b[0][3], a[3][1] + b[1][3], a[3][2] + b[2][3], a[3][3] + b[3][3] });
  return r;
}

constexpr int N(5e5 + 5), INF(1e9);

int n, m, val[N], fa[N], son[N], siz[N];

std::vector<int> g[N];

void dfs1(int x) {
  siz[x] = 1;  
  for (int y : g[x]) {
    if (y == fa[x]) continue;
    fa[y] = x;
    dfs1(y);
    siz[x] += siz[y];
    if (siz[y] > siz[son[x]]) son[x] = y;
  }
}

struct Node {
  Node *ls, *rs, *fa;
  Matrix val, sum;
  inline void pushup() {
    sum = ls ? ls->sum * val : val;
    if (rs) sum = sum * rs->sum;
  }
} t[N];
std::multiset<int> vir[N][3];
void updateVal(int x) {
  auto &v = t[x].val;
  auto p0 = vir[x][0].rbegin(), p1 = vir[x][1].rbegin();
  int k = val[son[x]], m0 = *p0, m1 = *p1;
  v[0][k] = 1, v[0][!k] = v[0][2] = -INF, v[0][3] = m0;
  v[1][!k] = 1, v[1][k] = v[1][2] = -INF, v[1][3] = m1;
  v[2][k] = m0 + 1, v[2][!k] = m1 + 1, v[2][2] = 0;
  v[2][3] = vir[x][0].size() > 1 ? std::max(m0 + *++p0, m1 + *++p1) : 0;
  smax(v[2][3], *vir[x][2].rbegin());
  v[3][0] = v[3][1] = v[3][2] = -INF, v[3][3] = 0;
}
int f[N][3];
void dfs2(int x) {
  f[x][0] = f[x][2] = 0, f[x][1] = -INF;
  vir[x][0].insert(0), vir[x][1].insert(-INF), vir[x][2].insert(0);
  for (int y : g[x]) {
    if (y == fa[x]) continue;
    dfs2(y);
    smax(f[x][2], f[y][2]);
    smax(f[x][2], f[x][0] + f[y][val[y]] + 1);
    smax(f[x][2], f[x][1] + f[y][!val[y]] + 1);
    smax(f[x][0], f[y][val[y]] + 1);
    smax(f[x][1], f[y][!val[y]] + 1);
    if (y == son[x]) continue;
    vir[x][0].insert(f[y][val[y]] + 1);
    vir[x][1].insert(f[y][!val[y]] + 1);
    vir[x][2].insert(f[y][2]);
  }
  updateVal(x);
}
int top[N], s[N], sum[N];
Node* build(int l, int r) {
  if (l == r) return t[s[l]].pushup(), t + s[l];
  int m = l, tot = sum[r] + sum[l - 1];
  while (m < r && sum[m] << 1 < tot) m++;
  Node *o = t + s[m];
  if (l < m) o->ls = build(l, m - 1), o->ls->fa = o;
  if (m < r) o->rs = build(m + 1, r), o->rs->fa = o;
  o->pushup();
  return o;
}
Node *root;
void dfs3(int x, int tp) {
  top[x] = tp;
  if (x == tp) {
    int m = 0;
    for (int i = x; i; i = son[i]) {
      s[++m] = i;
      sum[m] = sum[m - 1] + siz[i] - siz[son[i]];
    }
    if (x > 1)
      build(1, m)->fa = t + fa[x];
    else
      root = build(1, m);
  }
  if (!son[x]) return;
  dfs3(son[x], tp);
  for (int y : g[x]) {
    if (y == fa[x] || y == son[x]) continue;
    dfs3(y, y);
  }
}
inline void erase(std::multiset<int> &s, int x) {
  if (x < 0)
    assert(*s.begin() < 0), s.erase(s.begin());
  else 
    s.erase(s.find(x));
}
void work(int x, int y) {
  assert(fa[y] == x);
  Node *o = t + x;
  int &v = val[y];
  if (son[x] == y) {
    v ^= 1;
  } else {
    Node *p = t + y;
    while (p->fa != o) p = p->fa;
    erase(vir[x][0], p->sum[v][3] + 1);
    erase(vir[x][1], p->sum[!v][3] + 1);
    v ^= 1;
    vir[x][0].insert(p->sum[v][3] + 1);
    vir[x][1].insert(p->sum[!v][3] + 1);
  }
  for (updateVal(x); o->fa; o = o->fa) {
    if (o->fa->ls != o && o->fa->rs != o) {
      x = o->fa - t, y = val[top[o - t]];
      erase(vir[x][0], o->sum[y][3] + 1);
      erase(vir[x][1], o->sum[!y][3] + 1);
      erase(vir[x][2], o->sum[2][3]);
      o->pushup();
      vir[x][0].insert(o->sum[y][3] + 1);
      vir[x][1].insert(o->sum[!y][3] + 1);
      vir[x][2].insert(o->sum[2][3]);
      updateVal(x);
    } else {
      o->pushup();
    }
  }
  o->pushup();
}
struct Edge {
  int x, y, z;
} e[N];
int main() {
  readInt(n);
  for (int i = 1; i < n; i++) {
    auto &[x, y, z] = e[i];
    readInt(x, y, z);
    g[x].push_back(y), g[y].push_back(x);
  }
  dfs1(1);
  for (int i = 1; i < n; i++) {
    auto &[x, y, z] = e[i];
    if (fa[y] != x) std::swap(x, y);
    assert(fa[y] == x);
    val[y] = z;
  }
  
  dfs2(1);
  dfs3(1, 1);
  readInt(m);
  while (m--) {
    int i; readInt(i);
    work(e[i].x, e[i].y);
    printf("%d\n", root->sum[2][3]);
  }
  return 0;
}