#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 200 + 10, M = 1000 + 10, E = M * 2 + 10, INF = 1 << 25;

int n, m, a[M], b[M], c[M];

int adj[N], s, t;
int to[E], next[E], cap[E], cnt;

int h[N], gap[N];

inline void link(int a, int b, int c) {
  to[cnt] = b;
  next[cnt] = adj[a]; 
  cap[cnt] = c;
  adj[a] = cnt++;
}

int DFS(int a, int df) {
  if (a == t) return df;
  int tot = 0;
  for (int it = adj[a]; it; it = next[it]) {
    int b = to[it];
    if (cap[it] && h[a] == h[b] + 1) {
      int f = DFS(b, std::min(df - tot, cap[it]));
      cap[it] -= f;
      cap[it ^ 1] += f;
      tot += f;
    }
    if (tot == df) return tot;
  }
  if (--gap[h[a]] == 0) h[s] = n + 1;
  ++gap[++h[a]];
  return tot;
}

int ISAP() {
  memset(h, 0, sizeof h);
  memset(gap, 0, sizeof gap);
  int res = 0;
  while (h[s] < n + 1) res += DFS(s, INF);
  return res;
}

inline void BuildGraph() {
  memset(adj, 0, sizeof adj);
  cnt = 2;
  for (int i = 1; i <= m; ++i) {
    link(a[i], b[i], c[i]);
    link(b[i], a[i], c[i]);
  }
}

int mx[N][N];

struct Edge {
  int u, v, w;
  Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
  inline bool operator< (const Edge &rhs) const {
    return w > rhs.w;
  }
};

std::vector<Edge> e;

void Divide(std::vector<int> &cur) {
  if (cur.size() < 2) return;
  BuildGraph();
  s = cur[0], t = cur[1];
  e.push_back(Edge(s, t, ISAP()));
  std::vector<int> div[2];
  std::vector<int> q;
  bool flag[N];
  q.clear();
  memset(flag, false, sizeof flag);
  q.push_back(s);
  flag[s] = true;
  for (int i = 0; i < q.size(); ++i) {
    int a = q[i];
    for (int it = adj[a]; it; it = next[it]) {
      int b = to[it];
      if (cap[it] && !flag[b]) {
        q.push_back(b);
        flag[b] = true;
      }
    }
  }
  for (int i = 0; i < cur.size(); ++i) div[flag[cur[i]]].push_back(cur[i]);
  Divide(div[0]);
  Divide(div[1]);
}

int anc[N];

inline int find(int x) { return anc[x] == x ? x : (anc[x] = find(anc[x])); }

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) scanf("%d%d%d", a + i, b + i, c + i);
  static std::vector<int> pool;
  for (int i = 1; i <= n; ++i) pool.push_back(i);
  Divide(pool);
  std::sort(e.begin(), e.end());
  int ans = 0;
  for (int i = 0; i < e.size(); ++i) ans += e[i].w;
  printf("%d\n", ans);
  for (int i = 1; i <= n; ++i) anc[i] = i;
  static int fa[N];
  for (int i = 0; i < e.size(); ++i) {
    int x = e[i].u, y = e[i].v;
    fa[find(x)] = y;
    anc[find(x)] = find(y);
  }
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int j = i; j; j = fa[j]) ++cnt;
    if (cnt == n) {
      for (int j = i; j; j = fa[j]) printf("%d ", j);
      putchar('\n');
      break;
    }
  }
  return 0;
}