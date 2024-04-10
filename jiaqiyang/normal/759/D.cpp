#include <cstdio>
#include <cstring>

typedef long long i64;

const int N = 5000 + 10, S = 26, MOD = 1000000007;

inline void add(int &lhs, i64 rhs) { lhs = (lhs + rhs) % MOD; }

int n, f[N][N];
char s[N];

int succ[N];

int main() {
  scanf("%d %s", &n, s + 1);
  static int last[S];
  for (int i = n; i > 0; --i) {
    int c = s[i] - 'a';
    succ[i] = last[c];
    last[c] = i;
  }
  for (int i = 0; i < S; ++i) if (last[i]) f[last[i]][1] = 1;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int c = s[i] - 'a';
    static int g[S][N], sum[N];
    for (int j = 1; j <= n; ++j) add(f[i][j], sum[j] - g[c][j]);
    for (int j = 1; j < n; ++j) add(f[i][j + 1], f[i][j]);
    for (int j = 1; j <= n; ++j) g[c][j] = sum[j];
    for (int p = 1; p < n; ++p) add(sum[p + 1], f[i][p]), add(g[c][p + 1], f[i][p]);
    add(ans, f[i][n]);
  }
  printf("%d\n", (ans + MOD) % MOD);
  return 0;
}