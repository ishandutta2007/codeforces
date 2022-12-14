#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 30 + 1, M = 100000 + N;

int n, m;

int p[N];
char s[M];

class SA {
  int gap;
  int table[20][M], sa[M], rank[M], h[M], lg2[M];
  bool sufComp(int a, int b) {
    if (rank[a] != rank[b]) return rank[a] < rank[b];
    a += gap, b += gap;
    return a <= m && b <= m ? rank[a] < rank[b] : a > b;
  }
 public:
  void build() {
    static int temp[M], sum[M];
    memset(sum, 0, sizeof sum);
    for (int i = 1; i <= m; ++i) ++sum[rank[i] = s[i]];
    for (int i = 1; i < 256; ++i) sum[i] += sum[i - 1];
    for (int i = m; i > 0; --i) sa[sum[rank[i]]--] = i;
    for (int i = 1; i <= m; ++i) temp[i] = temp[i - 1] + (rank[sa[i - 1]] < rank[sa[i]]);
    for (int i = 1; i <= m; ++i) rank[sa[i]] = temp[i];
    for (gap = 1;; gap *= 2) {
      for (int i = 1; i <= gap; ++i) temp[i] = m - i + 1;
      for (int i = 1, tot = gap; i <= m; ++i) if (sa[i] > gap) temp[++tot] = sa[i] - gap;
      memset(sum, 0, sizeof sum);
      for (int i = 1; i <= m; ++i) ++sum[rank[i]];
      for (int i = 1; i <= m; ++i) sum[i] += sum[i - 1];
      for (int i = m; i > 0; --i) sa[sum[rank[temp[i]]]--] = temp[i];
      for (int i = 1; i <= m; ++i) temp[i] = temp[i - 1] + sufComp(sa[i - 1], sa[i]);
      for (int i = 1; i <= m; ++i) rank[sa[i]] = temp[i];
      if (rank[sa[m]] == m) break;
    }
    for (int i = 1; i < M; ++i) lg2[i] = 31 - __builtin_clz(i);
    for (int i = 1, k = 0; i <= m; ++i) {
      if (rank[i] == 1) continue;
      for (int j = sa[rank[i] - 1]; s[i + k] == s[j + k];) ++k;
      h[rank[i]] = k;
      if (k) --k;
    }
    for (int i = 1; i <= m; ++i) table[0][i] = h[i];
    for (int i = 1; i < 20; ++i)
      for (int j = 1; j + (1 << (i - 1)) <= m; ++j)
        table[i][j] = std::min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
  }
  int lcp(int a, int b) {
    if (a == b) return m - a + 1;
    a = rank[a], b = rank[b];
    if (a > b) std::swap(a, b);
    ++a;
    int k = lg2[b - a + 1];
    return std::min(table[k][a], table[k][b - (1 << k) + 1]);
  }
} sa;

std::vector<int> adj[M];

bool solve(int l, int r) {
  for (int i = p[l]; i <= p[r + 1]; ++i) adj[i].clear();
  for (int a = l; a <= r; ++a) {
    adj[p[r + 1]].push_back(p[a]);
    int t = p[a + 1] - p[a];
    for (int i = 0; i < t; ++i) {
      for (int b = l; b <= r; ++b) {
        int u = t - i, v = p[b + 1] - p[b], w = sa.lcp(p[a] + i, p[b]);
        w = std::min(w, std::min(u, v));
        if (!i && u == v && v == w) continue;
        if (w == u) {
          adj[p[a] + i].push_back(u == v ? p[r + 1] : (p[b] + w));
        } else if (w == v) {
          adj[p[a] + i].push_back(p[a] + i + v);
        }
      }
    }
  }
  static int deg[M];
  for (int i = p[l]; i <= p[r + 1]; ++i) deg[i] = 0;
  for (int a = p[l]; a <= p[r + 1]; ++a)
    for (int i = 0; i < adj[a].size(); ++i)
      ++deg[adj[a][i]];
  static int q[M];
  int tot = 0;
  for (int i = p[l]; i <= p[r + 1]; ++i) if (!deg[i]) q[++tot] = i;
  for (int i = 1; i <= tot; ++i) {
    int a = q[i];
    for (int j = 0; j < adj[a].size(); ++j) {
      int b = adj[a][j];
      if (--deg[b] == 0) q[++tot] = b;
    }
  }
  return tot == p[r + 1] - p[l] + 1;
}

int main() {
  scanf("%d", &n);
  m = 0;
  for (int i = 1; i <= n; ++i) {
    p[i] = m + 1;
    scanf(" %s", s + p[i]);
    while (s[m + 1]) ++m;
  }
  sa.build();
  p[n + 1] = m + 1;
  int ans = 0;
  for (int l = 0, r = 1; r <= n; ++r) {
    while (!solve(l + 1, r)) ++l;
    ans += r - l;
  }
  printf("%d\n", ans);
  return 0;
}