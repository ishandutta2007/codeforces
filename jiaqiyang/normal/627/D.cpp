#include <cstdio>
#include <vector>
#include <algorithm>

#define fst first
#define snd second

typedef std::pair<int, int> Info;

const int N = 200000 + 10;

inline Info operator+ (const Info &lhs, const Info &rhs) { return Info(lhs.fst + rhs.fst, std::max(lhs.snd, rhs.snd)); }

int n, k, val[N];

std::vector<int> adj[N];

int fa[N], size[N], f[N], g[N];

bool check(int th) {
  static int q[N];
  fa[1] = 0;
  q[1] = 1;
  for (int i = 1, r = 1; i <= r; ++i) {
    int a = q[i];
    for (int j = 0; j < adj[a].size(); ++j) {
      int b = adj[a][j];
      if (b != fa[a]) fa[q[++r] = b] = a;
    }
  }
  for (int i = 1; i <= n; ++i) size[i] = 1;
  for (int i = n; i > 0; --i) size[fa[q[i]]] += size[q[i]];
  for (int i = n; i > 0; --i) {
    int a = q[i];
    if (val[a] < th) {
      f[a] = 0;
      continue;
    }
    f[a] = 1;
    int temp = 0;
    for (int j = 0; j < adj[a].size(); ++j) {
      int b = adj[a][j];
      if (b == fa[a]) continue;
      if (f[b] == size[b]) f[a] += f[b]; else temp = std::max(temp, f[b]);
    }
    f[a] += temp;
  }
  for (int i = 1; i <= n; ++i) {
    int a = q[i];
    static Info info[N], pre[N], suf[N];
    for (int j = 0; j < adj[a].size(); ++j) {
      int b = adj[a][j];
      if (b == fa[a]) info[j] = (g[a] == n - size[a] ? Info(g[a], 0) : Info(0, g[a])); else info[j] = (f[b] == size[b] ? Info(f[b], 0) : Info(0, f[b]));
    }
    for (int j = 0; j < adj[a].size(); ++j) pre[j] = suf[j] = info[j];
    for (int j = 1; j < adj[a].size(); ++j) pre[j] = pre[j - 1] + pre[j];
    for (int j = adj[a].size() - 2; j >= 0; --j) suf[j] = suf[j + 1] + suf[j];
    for (int j = 0; j < adj[a].size(); ++j) {
      Info cur;
      if (j) cur = cur + pre[j - 1];
      if (j + 1 < adj[a].size()) cur = cur + suf[j + 1];
      int b = adj[a][j];
      if (b == fa[a]) continue;
      if (val[a] >= th) g[b] = cur.fst + cur.snd + 1; else g[b] = 0;
    }
  }
  for (int a = 1; a <= n; ++a) {
    if (val[a] < th) continue;
    Info cur;
    for (int i = 0; i < adj[a].size(); ++i) {
      int b = adj[a][i];
      if (b == fa[a]) cur = cur + (g[a] == n - size[a] ? Info(g[a], 0) : Info(0, g[a])); else cur = cur + (f[b] == size[b] ? Info(f[b], 0) : Info(0, f[b]));
    }
    if (cur.fst + cur.snd + 1 >= k)
      return true;
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
  for (int i = n - 1; i--;) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int l = *std::min_element(val + 1, val + n + 1), r = *std::max_element(val + 1, val + n + 1);
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid)) l = mid; else r = mid - 1;
  }
  printf("%d\n", l);
  return 0;
}