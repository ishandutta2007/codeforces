#include <cstdio>
#include <cassert>
#include <stack>
#include <vector>
#include <algorithm>

const int N = 100000 + 10, S = 20;

int n;
std::vector<int> adj[N];

int fa[N], dfn[N], dep[N];

int table[S][2 * N], tot;

void dfs(int a) {
  table[0][dfn[a] = ++tot] = a;
  for (auto b : adj[a]) {
    if (b != fa[a]) {
      fa[b] = a;
      dep[b] = dep[a] + 1;
      dfs(b);
      table[0][++tot] = a;
    }
  }
}

inline int get(int a, int b) { return dep[a] < dep[b] ? a : b; }

int query(int l, int r) {
  if (l > r) std::swap(l, r);
  int k = 31 - __builtin_clz(r - l + 1);
  return get(table[k][l], table[k][r - (1 << k) + 1]);
}

int lca(int x, int y) { return query(dfn[x], dfn[y]); }
inline bool comp(int x, int y) { return dfn[x] < dfn[y]; }

std::vector<int> cur[N];

int tag[N], cnt;

int f[N], g[N];

void calc(int a) {
  if (tag[a] == cnt) {
    f[a] = N;
    g[a] = 0;
    for (auto b : cur[a]) {
      calc(b);
      g[a] += f[b];
    }
  } else {
    int s1 = 0, s2 = 0, det = 0;
    for (auto b : cur[a]) {
      calc(b);
      s1 += f[b];
      s2 += g[b];
      det = std::min(det, g[b] - f[b]);
    }
    f[a] = std::min(s2 + 1, s1);
    g[a] = s1 + det;
  }
  g[a] = std::min(g[a], f[a]);
}

int solve(std::vector<int> &id) {
  std::vector<int> temp = id;
  std::sort(id.begin(), id.end(), comp);
  for (auto i : id) if (fa[i]) temp.push_back(fa[i]);
  for (int i = 1; i < id.size(); ++i) temp.push_back(lca(id[i - 1], id[i]));
  std::sort(temp.begin(), temp.end());
  temp.erase(std::unique(temp.begin(), temp.end()), temp.end());
  std::sort(temp.begin(), temp.end(), comp);
  ++cnt;
  for (auto i : id) tag[i] = cnt;
  for (auto i : temp) cur[i].clear();
  std::stack<int> stk;
  for (auto i : temp) {
    while (!stk.empty() && lca(stk.top(), i) != stk.top()) stk.pop();
    if (!stk.empty()) cur[stk.top()].push_back(i);
    stk.push(i);
  }
  calc(temp[0]);
  int res = std::min(f[temp[0]], g[temp[0]]);
  if (res < temp.size()) return res; else return -1;
}

int main() {
  scanf("%d", &n);
  for (int i = n - 1; i--;) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dep[1] = 1;
  dfs(1);
  for (int i = 1; i < S; ++i)
    for (int j = 1; j + (1 << (i - 1)) <= tot; ++j)
      table[i][j] = get(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
  int q;
  for (scanf("%d", &q); q--;) {
    int k;
    std::vector<int> id;
    for (scanf("%d", &k); k--;) {
      int x;
      scanf("%d", &x);
      id.push_back(x);
    }
    printf("%d\n", solve(id));
  }
  return 0;
}