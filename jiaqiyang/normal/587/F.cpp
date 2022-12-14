#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10, S = 26;

int n, m;

char *s[N], buffer[2 * N], *top = buffer;
int id[N], len[N];

std::vector<int> que[N];

int next[N][S], pre[N], fail[N], tot = 1;

int l[N], r[N], k[N];
i64 ans[N];

int insert(char *s) {
  int p = 1;
  for (; *s; ++s) {
    int c = *s - 'a';
    if (!next[p][c]) pre[next[p][c] = ++tot] = p;
    p = next[p][c];
  }
  return p;
}

int q[N];

void toposort() {
  static int dep[N], cnt[N];
  for (int i = 1; i <= tot; ++i) dep[i] = dep[pre[i]] + 1;
  for (int i = 1; i <= tot; ++i) ++cnt[dep[i]];
  for (int i = 1; i <= tot; ++i) cnt[i] += cnt[i - 1];
  for (int i = 1; i <= tot; ++i) q[cnt[dep[i]]--] = i;
  for (int i = 1; i <= tot; ++i) {
    int a = q[i];
    for (int j = 0; j < S; ++j) {
      int b = next[a][j];
      if (!b) continue;
      int &k = fail[b] = fail[a];
      while (k && !next[k][j]) k = fail[k];
      if (next[k][j]) k = next[k][j]; else k = 1;
    }
  }
}

std::vector<int> adj[N], pool[N];

int sum[2 * N], tag[N], size;

void add(int p, int v) {
  int x = p / size + 1, y = x * size;
  for (int i = p; i < y; ++i) sum[i] += v;
  for (int i = x; i * size <= n; ++i) tag[i] += v;
}

inline int query(int p) { return sum[p] + tag[p / size]; }

void dfs(int a) {
  for (int i = 0; i < pool[a].size(); ++i) add(pool[a][i], 1);
  for (int i = 0; i < que[a].size(); ++i) {
    int t = que[a][i];
    ans[t] += query(r[t]) - query(l[t] - 1);
  }
  for (int i = 0; i < adj[a].size(); ++i) dfs(adj[a][i]);
  for (int i = 0; i < pool[a].size(); ++i) add(pool[a][i], -1);
}

int main() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf(" %s", s[i] = top);
    top += (len[i] = strlen(s[i])) + 1;
    pool[id[i] = insert(s[i])].push_back(i);
  }
  toposort();
  for (int i = 1; i <= m; ++i) scanf("%d%d%d", &l[i], &r[i], &k[i]);
  size = sqrt(top - buffer);
  for (int i = 1; i <= m; ++i) if (len[k[i]] > size) que[k[i]].push_back(i);
  for (int i = 1; i <= n; ++i) {
    if (que[i].empty()) continue;
    static int temp[N];
    for (int j = 1; j <= tot; ++j) temp[j] = 0;
    for (int j = id[i]; j; j = pre[j]) temp[j] = 1;
    for (int j = tot; j > 0; --j) temp[fail[q[j]]] += temp[q[j]];
    static i64 cur[N];
    for (int j = 1; j <= n; ++j) cur[j] = temp[id[j]];
    for (int j = 1; j <= n; ++j) cur[j] += cur[j - 1];
    for (int j = 0; j < que[i].size(); ++j) {
      int t = que[i][j];
      ans[t] = cur[r[t]] - cur[l[t] - 1];
    }
    que[i].clear();
  }
  for (int i = 1; i <= tot; ++i) adj[fail[i]].push_back(i);
  for (int i = 1; i <= tot; ++i) que[i].clear();
  for (int i = 1; i <= m; ++i) if (len[k[i]] <= size) que[id[k[i]]].push_back(i);
  for (int i = tot; i > 0; --i) std::copy(que[q[i]].begin(), que[q[i]].end(), std::back_inserter(que[pre[q[i]]]));
  dfs(1);
  for (int i = 1; i <= m; ++i) std::cout << ans[i] << '\n';
  return 0;
}