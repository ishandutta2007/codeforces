#include <cstdio>
#include <algorithm>

#define ll long long
#define db double
#define ull unsigned long long
#define uint unsigned int
#define FIO ""
#define dbug(...) fprintf(stderr, __VA_ARGS__)

template <typename Y> inline bool updmin(Y &a, Y b){if (a > b) {a = b; return 1;} return 0;}
template <typename Y> inline bool updmax(Y &a, Y b){if (a < b) {a = b; return 1;} return 0;}
template <typename Y> inline Y abs(Y a){if (a < 0) a = -a; return a;}
template <typename Y> inline Y sqr(Y a){return a * a;}

typedef std::pair<int, int> par;
#define fx first
#define fy second
#define mpar std::make_pair
#define pb push_back

int read() {
  int w = 1, q = 0, ch = ' ';
  for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) q = q * 10 + ch - 48;
  return q * w;
}

inline void FileIO(){freopen(FIO".in", "r", stdin); freopen(FIO".out", "w", stdout);}

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10050;
const int INF = (int)1e9;
int e_num = 1, S, T;
int hed[maxn], dep[maxn];

struct Edge {
  int from, to, nxt, c;
} edge[maxn * 4];

void addedge(int from, int to, int c) {
  edge[++e_num] = (Edge){from, to, hed[from], c};
  hed[from] = e_num;
}

void adde(int from, int to, int c) {
  addedge(from, to, c);
  addedge(to, from, 0);
}

int queue[maxn + 5], head = 0, tail = 0;
bool bfs() {
  head = tail = 0;
  queue[tail++] = S;
  for (int i = S; i <= T; i++) {
    dep[i] = 0;
  }
  dep[S] = 1;
  while (head != tail) {
    int cur = queue[head++]; head %= maxn;
    for (int i = hed[cur]; i; i = edge[i].nxt) {
      int to = edge[i].to;
      if (!dep[to] && edge[i].c) {
        dep[to] = dep[cur] + 1;
        queue[tail++] = to; tail %= maxn;
      }
    }
  }
  return dep[T];
}

int dfs(int x, int flow) {
  if (x == T) return flow;
  int ret = 0;
  for (int i = hed[x]; i; i = edge[i].nxt) {
    int to = edge[i].to;
    if (dep[to] == dep[x] + 1 && edge[i].c) {
      int tmp = dfs(to, std::min(flow, edge[i].c));
      edge[i].c -= tmp;
      edge[i ^ 1].c += tmp;
      flow -= tmp;
      ret += tmp;
      if (!flow) {
        break;
      }
    }
  }
  if (!ret) dep[x] = 0;
  return ret;
}

int dinic() {
  int ret = 0;
  while (bfs()) {
    ret += dfs(S, INF);
  }
  return ret;
}

#include <vector>
std::vector<int> adj[maxn], bdj[maxn];
int n, m, k, ans[maxn];

#define WXHGAY for(int xx=1;xx<=m;xx++)printf("0 ");puts("");return;

inline void Main() {
  n = read();
  m = read();
  k = read();
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    bdj[i].clear();
  }
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    adj[x].pb(i);
    adj[y].pb(i);
    ans[i] = i;
  }
  memset(hed, 0, sizeof hed);
  e_num = 1;
  S = 0, T = n + m + 2;
  int qq = 0;
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() > 2 * k) {
      WXHGAY;
    }
    adde(S, i, std::max(((int)adj[i].size() - k) * 2, 0));
    qq += std::max(((int)adj[i].size() - k) * 2, 0);
    for (auto x : adj[i]) {
      adde(i, x + n, 1);
    }
  }
  for (int i = 1; i <= m; i++) {
    adde(i + n, T, 1);
  }
  int wxh = dinic();
  if (wxh != qq) {
    WXHGAY;
  }
  for (int i = 1; i <= n; i++) {
    for (int e = hed[i]; e; e = edge[e].nxt) {
      if (edge[e].to == S) continue;
      if (!edge[e].c) {
        bdj[i].pb(edge[e].to - n);
      }
    }
    for (size_t j = 0; j < bdj[i].size(); j += 2) {
      ans[bdj[i][j]] = bdj[i][j + 1];
    }
  }
  for (int i = 1; i <= m; i++) {
    printf("%d ", ans[i]);
  }
  puts("");
}

int main() {
  int T = read();
  while (T--) {
    Main();
  }
  return 0;
}