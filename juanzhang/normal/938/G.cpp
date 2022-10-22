#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
typedef pair <int, int> pii;
const int maxn = 2e5 + 10;
int n, m, q, ans[maxn];

struct edge {
  int u, v, w;
} Q[maxn];

map <pii, pii> G;

int top, st[maxn];
int par[maxn], sz[maxn], val[maxn];

int find(int x) {
  while (par[x] != x) x = par[x];
  return x;
}

int query(int x) {
  int res = 0;
  while (par[x] != x) res ^= val[x], x = par[x];
  return res;
}

struct linear_base {
  int A[30];
  
  void ins(int x) {
    per(i, 29, 0) if (x >> i & 1) {
      if (A[i]) {
        x ^= A[i];
      } else {
        rep(j, 0, i - 1) if (x >> j & 1) x ^= A[j];
        rep(j, i + 1, 29) if (A[j] >> i & 1) A[j] ^= x;
        A[i] = x;
        return;
      }
    }
  }
  
  int query(int x) {
    per(i, 29, 0) chkmin(x, x ^ A[i]);
    return x;
  }
} LB[20];

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

vector <edge> E[maxn << 2];

void ins(int k, int l, int r, int ql, int qr, edge x) {
  if (ql <= l && r <= qr) {
    E[k].push_back(x); return;
  }
  if (ql <= mid) ins(lson, ql, qr, x);
  if (qr > mid) ins(rson, ql, qr, x);
}

void solve(int k, int l, int r, int dep) {
  int state = top;
  LB[dep] = LB[dep - 1];
  for (edge p : E[k]) {
    int u = p.u, v = p.v;
    int x = find(u), y = find(v);
    int w = p.w ^ query(u) ^ query(v);
    if (x != y) {
      if (sz[x] < sz[y]) swap(x, y);
      par[y] = x, st[++top] = y;
      sz[x] += sz[y], val[y] = w;
    } else {
      LB[dep].ins(w);
    }
  }
  if (l == r) {
    int u = Q[l].u, v = Q[l].v;
    if (u) ans[l] = LB[dep].query(query(u) ^ query(v));
  } else {
    solve(lson, dep + 1), solve(rson, dep + 1);
  }
  while (top > state) {
    int u = st[top--];
    sz[par[u]] -= sz[u], par[u] = u, val[u] = 0;
  }
}

#undef mid
#undef lson
#undef rson

int main() {
  cin >> n >> m;
  rep(i, 1, m) {
    int u = read(), v = read(), w = read();
    if (u > v) swap(u, v);
    G[pii(u, v)] = pii(w, 1);
  }
  cin >> q;
  rep(i, 1, q) {
    int op = read(), u = read(), v = read();
    if (u > v) swap(u, v);
    if (op == 1) {
      int w = read();
      G[pii(u, v)] = pii(w, i);
    } else if (op == 2) {
      pii p = G[pii(u, v)];
      ins(1, 1, q, p.second, i, edge{u, v, p.first});
      G.erase(pii(u, v));
    } else {
      Q[i] = {u, v};
    }
  }
  for (auto x : G) {
    pii e = x.first, p = x.second;
    ins(1, 1, q, p.second, q, edge{e.first, e.second, p.first});
  }
  rep(i, 1, n) par[i] = i, sz[i] = 1;
  solve(1, 1, q, 1);
  rep(i, 1, q) if (Q[i].u) printf("%d\n", ans[i]);
  return 0;
}