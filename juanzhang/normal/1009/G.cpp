#pragma GCC optimize(3)

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
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
typedef pair <int, int> pii;
const int maxn = 1e5 + 10;
char str[maxn], ans[maxn];
int n, m, cnt[6], state[maxn];

int data[1 << 6];

const int inf = 1e9;
int S, T, ecnt, h[100], cur[100], dis[100];

struct edges {
  int nxt, to, w;
  edges(int x = 0, int y = 0, int z = 0) :
    nxt(x), to(y), w(z) {}
} e[2000];

void addline(int u, int v, int w) {
  e[++ecnt] = edges(h[u], v, w), h[u] = ecnt;
  e[++ecnt] = edges(h[v], u, 0), h[v] = ecnt;
}

bool bfs() {
  static int Q[100];
  memcpy(cur, h, sizeof h);
  memset(dis, 0, sizeof dis);
  int l = 1, r = 1;
  Q[1] = S, dis[S] = 1;
  while (l <= r) {
    int u = Q[l++];
    for (int i = h[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (e[i].w && !dis[v]) {
        Q[++r] = v, dis[v] = dis[u] + 1;
        if (v == T) return 1;
      }
    }
  }
  return 0;
}

int dfs(int u, int f) {
  if (u == T || !f) {
    return f;
  }
  int res = 0, tmp;
  for (int& i = cur[u]; i && f; i = e[i].nxt) {
    int v = e[i].to;
    if (e[i].w && dis[v] == dis[u] + 1) {
      if (!(tmp = dfs(v, min(f, e[i].w)))) {
        dis[v] = 0; continue;
      }
      res += tmp, f -= tmp, e[i].w -= tmp, e[i ^ 1].w += tmp;
    }
  }
  return res;
}

int dinic() {
  int res = 0;
  while (bfs()) {
    res += dfs(S, inf);
  }
  return res;
}

bool check() {
  ecnt = 1;
  memset(h, 0, sizeof h);
  S = 90, T = 91;
  int sum = 0;
  rep(i, 0, 5) if (cnt[i]) addline(S, 70 + i, cnt[i]);
  rep(i, 1, (1 << 6) - 2) if (data[i]) addline(i, T, data[i]), sum += data[i];
  rep(i, 0, 5) if (cnt[i]) {
    rep(j, 1, (1 << 6) - 2) if (data[j] && (j >> i & 1)) {
      addline(70 + i, j, inf);
    }
  }
  return dinic() == sum;
}

void solve() {
  scanf("%s %d", str + 1, &m);
  n = strlen(str + 1);
  rep(i, 1, m) {
    int pos = read();
    static char tmp[10];
    scanf("%s", tmp + 1);
    rep(j, 1, strlen(tmp + 1)) state[pos] |= 1 << (tmp[j] - 'a');
  }
  rep(i, 1, n) {
    cnt[str[i] - 'a']++;
    if (!state[i]) state[i] = (1 << 6) - 1;
    data[state[i]]++;
  }
  if (!check()) return puts("Impossible"), void();
  rep(i, 1, n) {
    data[state[i]]--;
    rep(j, 0, 5) if ((state[i] >> j & 1) && cnt[j]) {
      cnt[j]--;
      if (check()) {
        ans[i] = 'a' + j; break;
      }
      cnt[j]++;
    }
  }
  rep(i, 1, n) putchar(ans[i]);
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}