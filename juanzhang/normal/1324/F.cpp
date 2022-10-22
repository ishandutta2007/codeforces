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
const int maxn = 2e5 + 10;
int n, a[maxn], dp1[maxn], dp2[maxn];

vector <int> E[maxn];

void dfs1(int u, int f) {
  dp1[u] = a[u];
  for (int v : E[u]) if (v != f) {
    dfs1(v, u), dp1[u] += max(0, dp1[v]);
  }
}

void dfs2(int u, int f) {
  for (int v : E[u]) if (v != f) {
    int val = dp2[u] - max(0, dp1[v]);
    dp2[v] = dp1[v] + max(0, val);
    dfs2(v, u);
  }
}

int main() {
  n = read();
  rep(i, 1, n) {
    a[i] = read();
    if (!a[i]) a[i] = -1;
  }
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    E[u].push_back(v), E[v].push_back(u);
  }
  dfs1(1, 0);
  dp2[1] = dp1[1];
  dfs2(1, 0);
  rep(i, 1, n) printf("%d ", dp2[i]);
  return 0;
}