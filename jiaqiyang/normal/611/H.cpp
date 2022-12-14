#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

#define fst first
#define snd second

typedef std::pair<int, int> Edge;

const int N = 200000 + 10, M = 7;

int n, k, m, u[N], v[N];
int adj[M][M];

std::vector<Edge> edge;

int anc[M];

int find(int x) { return anc[x] == x ? x : (anc[x] = find(anc[x])); }

inline bool meld(int x, int y) {
  if ((x = find(x)) == (y = find(y))) return false;
  return anc[x] = y, true;
}

bool check(int s) {
  for (int i = 0; i < k; ++i) anc[i] = i;
  for (int i = 0; i < edge.size(); ++i) if ((s >> i & 1) && !meld(edge[i].fst, edge[i].snd)) return false;
  return true;
}

inline int calc(int x) {
  int res = 0;
  for (; x; x /= 10) ++res;
  return res - 1;
}

int lg[N];

std::vector<int> pool[M];

std::vector<Edge> ans[M][M];

int cur[M][M];

inline void append(int x, int y) {
  ans[lg[x]][lg[y]].push_back(Edge(x, y));
}

bool hall() {
  for (int s = 0; s < (1 << k); ++s) {
    int x = 0, y = 0;
    for (int i = 0; i < k; ++i) if (s >> i & 1) x += pool[i].size() - 1;
    for (int i = 0; i < k; ++i)
      if (s >> i & 1)
        for (int j = 0; j < k; ++j)
          if (s >> j & 1)
            y += cur[i][j];
    if (y > x) return false;
  }
  return true;
}

Edge get(int x, int y) {
  if (x > y) {
    Edge res = ans[y][x].back();
    std::swap(res.fst, res.snd);
    ans[y][x].pop_back();
    return res;
  }
  Edge res = ans[x][y].back();
  ans[x][y].pop_back();
  return res;
}

void solve(int s) {
  for (int i = 0; i < k; ++i)
    for (int j = 0; j < k; ++j)
      ans[i][j].clear();
  memcpy(cur, adj, sizeof cur);
  for (int i = 0; i < edge.size(); ++i) {
    if (s >> i & 1) {
      int x = pool[edge[i].fst][0], y = pool[edge[i].snd][0];
      if (x > y) std::swap(x, y);
      if (--cur[lg[x]][lg[y]] < 0) return;
      append(x, y);
    }
  }
  if (!hall()) return;
  for (int i = 0; i < k; ++i) {
    for (int j = i; j < k; ++j) {
      while (cur[i][j]) {
        --cur[i][j];
        if (pool[i].size() > 1) {
          int t = pool[i].back();
          pool[i].pop_back();
          if (hall()) {
            append(t, pool[j][0]);
            continue;
          }
          pool[i].push_back(t);
        }
        append(pool[i][0], pool[j].back());
        pool[j].pop_back();
      }
    }
  }
  for (int i = 1; i < n; ++i) {
    Edge cur = get(u[i], v[i]);
    printf("%d %d\n", cur.fst, cur.snd);
  }
  exit(0);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) lg[i] = calc(i);
  for (int i = 1; i < n; ++i) {
    static char s[M];
    scanf(" %s", s);
    u[i] = strlen(s) - 1;
    scanf(" %s", s);
    v[i] = strlen(s) - 1;
    if (u[i] < v[i]) ++adj[u[i]][v[i]]; else ++adj[v[i]][u[i]];
  }
  for (int i = 1; i <= n; ++i) pool[lg[i]].push_back(i);
  k = lg[n] + 1;
  for (int i = 0; i < k; ++i)
    for (int j = i + 1; j < k; ++j)
      edge.push_back(Edge(i, j));
  m = edge.size();
  for (int s = 0; s < (1 << m); ++s)
    if (__builtin_popcount(s) == k - 1 && check(s))
      solve(s);
  puts("-1");
  return 0;
}