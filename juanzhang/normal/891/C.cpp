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

typedef pair <int, int> pii;
const int maxn = 5e5 + 10;
bool ans[maxn];
int n, m, q;

struct edge {
  int u, v, w, tid;
} E[maxn];

int top, st[maxn];
int par[maxn], sz[maxn];

int find(int x) {
  while (par[x] != x) x = par[x];
  return x;
}

bool unite(int x, int y) {
  if ((x = find(x)) == (y = find(y))) {
    return 0;
  }
  if (sz[x] < sz[y]) swap(x, y);
  par[y] = x, sz[x] += sz[y], st[++top] = y;
  return 1;
}

void revert(int k) {
  while (top > k) {
    int u = st[top--];
    sz[par[u]] -= sz[u], par[u] = u;
  }
}

int mp[maxn];
vector <pii> Q[maxn];

int vis[maxn];
set <int> S;
vector <int> vec[maxn];

int main() {
  cin >> n >> m;
  rep(i, 1, m) {
    int u = read(), v = read(), w = read();
    E[i] = {u, v, w, i};
  }
  cin >> q;
  rep(i, 1, q) {
    int k = read();
    while (k--) {
      int x = read();
      Q[E[x].w].push_back(pii(i, x));
    }
  }
  sort(E + 1, E + m + 1, [] (edge P, edge Q) {
    return P.w < Q.w;
  });
  memset(ans, 1, sizeof ans);
  rep(i, 1, m) mp[E[i].tid] = i;
  rep(i, 1, n) par[i] = i, sz[i] = 1;
  rep(i, 1, m) {
    S.clear();
    for (pii p : Q[E[i].w]) {
      int u = p.first;
      if (S.find(u) == S.end()) {
        S.insert(u), vec[u].clear();
      }
      vec[u].push_back(mp[p.second]);
    }
    int cur = top;
    for (int p : S) {
      if (!ans[p]) continue;
      for (int x : vec[p]) if (!unite(E[x].u, E[x].v)) {
        ans[p] = 0; break;
      }
      revert(cur);
    }
    unite(E[i].u, E[i].v);
    for (; i < m && E[i].w == E[i + 1].w; i++) {
      unite(E[i + 1].u, E[i + 1].v);
    }
  }
  rep(i, 1, q) puts(ans[i] ? "YES" : "NO");
  return 0;
}