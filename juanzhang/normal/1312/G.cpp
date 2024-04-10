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
const int maxn = 1e6 + 10;
bool use[maxn];
int n, k, a[maxn], val[maxn];

vector <int> E[maxn];
int sz[maxn], tid[maxn], sum[maxn], ans[maxn];

void dfs1(int u) {
  sort(E[u].begin(), E[u].end(), [] (int x, int y) {
    return val[x] < val[y];
  });
  static int now;
  sz[u] = 1;
  tid[u] = ++now, sum[now] = sum[now - 1] + use[u];
  for (int v : E[u]) {
    ans[v] = ans[u] + 1, dfs1(v), sz[u] += sz[v];
  }
}

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

int mn[maxn << 2];

void upd(int k, int l, int r, int ql, int qr, int x) {
  if (ql <= l && r <= qr) {
    chkmin(mn[k], x); return;
  }
  if (ql <= mid) upd(lson, ql, qr, x);
  if (qr > mid) upd(rson, ql, qr, x);
}

int query(int k, int l, int r, int pos) {
  if (l == r) return mn[k];
  return min(mn[k], pos <= mid ? query(lson, pos) : query(rson, pos));
}

#undef mid
#undef lson
#undef rson

void dfs2(int u) {
  if (use[u]) {
    chkmin(ans[u], sum[tid[u]] + query(1, 1, n + 1, tid[u]));
  }
  upd(1, 1, n + 1, tid[u], tid[u] + sz[u] - 1, ans[u] - sum[tid[u] - 1]);
  for (int v : E[u]) {
    chkmin(ans[v], ans[u] + 1), dfs2(v);
  }
}

int main() {
  cin >> n;
  rep(i, 1, n) {
    E[read()].push_back(i);
    char ch = getchar();
    while (ch < 'a') ch = getchar();
    val[i] = ch;
  }
  cin >> k;
  rep(i, 1, k) {
    a[i] = read(), use[a[i]] = 1;
  }
  dfs1(0);
  memset(mn, 0x3f, sizeof mn);
  dfs2(0);
  rep(i, 1, k) printf("%d ", ans[a[i]]);
  return 0;
}