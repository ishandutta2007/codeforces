#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef pair <int, int> pii;
const int maxn = 2e5 + 10;
int n, m, h[maxn];

struct edges {
  int nxt, to, w;
} e[maxn << 1];

void addline(int u, int v, int w) {
  static int cnt = 1;
  e[++cnt] = edges{h[u], v, w}, h[u] = cnt;
}

int pre[maxn], dep[maxn], dis[maxn];

bool FLG;

void bfs() {
  static int Q[maxn];
  int l = 1, r = 1;
  pre[n] = n, dep[n] = 1, Q[1] = n;
  while (l <= r) {
    int u = Q[l++];
    for (int i = h[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (!pre[v] && !e[i].w) {
        if (!pre[v]) pre[v] = u;
        dep[v] = dep[u] + 1;
        Q[++r] = v;
        if (v == 1) FLG = 1;
      }
    }
  }
}

void dijkstra() {
  int tot = 0;
  priority_queue <pii, vector <pii>, greater <pii> > Q;
  memset(dis, 0x3f, sizeof dis);
  for (int i = 1; i <= n; i++) {
    if (pre[i]) {
      Q.push(pii(0, i)), dis[i] = 0;
    } else {
      dep[i] = 1 << 30;
    }
  }
  int lst = -1;
  while (!Q.empty()) {
    pii p = Q.top();
    int u = p.second;
    Q.pop();
    if (dis[u] < p.first) continue;
    if (dis[u] != lst) lst = dis[u], dis[u] = ++tot;
    for (int i = h[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      int val = tot * 10 + e[i].w;
      if (dis[v] > val || (dis[v] == val && dep[v] > dep[u] + 1)) {
        dis[v] = val, pre[v] = u, dep[v] = dep[u] + 1, Q.push(pii(dis[v], v));
      }
    }
  }
}

bool Zero = 1;
vector <int> path;

void Print(int u) {
  path.push_back(u);
  if (u != n) Print(pre[u]);
}

void print(int u) {
  path.push_back(u);
  if (u != n) print(pre[u]);
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == pre[u]) {
      if (e[i].w) Zero = 0;
      if (e[i].w || (!e[i].w && !Zero)) {
        putchar(e[i].w | 48);
      }
      break;
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u++, v++;
    addline(u, v, w), addline(v, u, w);
  }
  bfs();
  if (FLG) {
    puts("0");
    Print(1);
    printf("%d\n", (int) path.size());
    for (int x : path) printf("%d ", x - 1);
    return 0;
  }
  dijkstra();
  print(1);
  if (Zero) putchar(48);
  printf("\n%d\n", (int) path.size());
  for (int x : path) printf("%d ", x - 1);
  return 0;
}