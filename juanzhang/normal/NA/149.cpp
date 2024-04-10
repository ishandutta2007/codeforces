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

const int maxn = 5010, maxm = 1e5 + 10, inf = 1 << 30;
bool vis[maxn];
int S, T, h[maxn], f[maxn], dis[maxn], pre[maxn];

struct edges {
  int nxt, to, w, c;
} e[maxm];

queue <int> q;

void addline(int u, int v, int w, int c) {
  static int cnt = 1;
  e[++cnt] = {h[u], v, w, c}, h[u] = cnt;
  e[++cnt] = {h[v], u, 0, -c}, h[v] = cnt;
}

bool spfa() {
  memset(dis, 0x3f, sizeof dis);
  q.push(S), dis[S] = 0, f[S] = inf;
  while (!q.empty()) {
    int u = q.front();
    vis[u] = 0, q.pop();
    for (int i = h[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (e[i].w && dis[u] + e[i].c < dis[v]) {
        pre[v] = i;
        f[v] = min(f[u], e[i].w);
        dis[v] = dis[u] + e[i].c;
        if (!vis[v]) q.push(v), vis[v] = 1;
      }
    }
  }
  return dis[T] < 1e9;
}

int mf, mc;

void EK() {
  while (spfa()) {
    mf += f[T], mc += f[T] * dis[T];
    for (int u = T; u != S; u = e[pre[u] ^ 1].to) {
      e[pre[u]].w -= f[T], e[pre[u] ^ 1].w += f[T];
    }
  }
}

int n, cnt[26];
char A[105], str[105];

void getcnt(char *str) {
  int len = strlen(str + 1);
  memset(cnt, 0, sizeof cnt);
  rep(i, 1, len) {
    cnt[str[i] - 'a']++;
  }
}

int main() {
  scanf("%s %d", A + 1, &n);
  getcnt(A);
  S = 4999, T = 5000;
  rep(i, 0, 25) {
    addline(S, 3000 + i, cnt[i], 0);
  }
  rep(Case, 1, n) {
    int x;
    scanf("%s %d", str + 1, &x);
    getcnt(str);
    rep(i, 0, 25) {
      int u = Case * 26 + i;
      addline(3000 + i, u, inf, 0);
      addline(u, 3500 + Case, cnt[i], Case);
    }
    addline(3500 + Case, T, x, 0);
  }
  int tot = strlen(A + 1);
  EK();
  if (mf != tot) {
    puts("-1");
  } else {
    printf("%d", mc);
  }
  return 0;
}