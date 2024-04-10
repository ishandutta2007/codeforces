#include <cstdio>
#include <cstring>
#include <vector>

const int N = 1000 + 10, M = 200000 + 10;

inline void check(int &lhs, int rhs) { if (rhs < lhs) lhs = rhs; }

int n, m, q, f[N][N];

int x[M], y[M], l[M], r[M], s[M], t[M];

std::vector<int> query[M];

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= m; ++i) scanf("%d%d", &x[i], &y[i]);
  for (int i = 1; i <= q; ++i) scanf("%d%d%d%d", &l[i], &r[i], &s[i], &t[i]), query[l[i]].push_back(i);
  memset(f, 0x3f, sizeof f);
  static bool ans[M];
  for (int i = m; i > 0; --i) {
    int a = x[i], b = y[i];
    f[a][b] = f[b][a] = i;
    for (int c = 1; c <= n; ++c) check(f[a][c], f[b][c]);
    for (int c = 1; c <= n; ++c) check(f[b][c], f[a][c]);
    for (int j = 0; j < query[i].size(); ++j) {
      int z = query[i][j];
      ans[z] = (f[s[z]][t[z]] <= r[z]);
    }
  }
  for (int i = 1; i <= q; ++i) puts(ans[i] ? "Yes" : "No");
  return 0;
}