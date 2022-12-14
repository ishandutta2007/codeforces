#include <cstdio>

const int N = 1000 + 10;

double f[N][N];

double dfs(int n, int m) {
  if (!n || !m) return 1. / (m + 1.);
  double &res = f[n][m];
  if (res) return res;
  double a = m / (m + 1.) * (1. - dfs(m - 1, n)), b = a + 1. / (m + 1.);
  double c = 1. - dfs(m, n - 1);
  double p = (c - 1.) / (a - b + c - 1.);
  return res = p * a + 1. - p;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  double ans = dfs(n, m);
  printf("%.10f %.10f\n", ans, 1. - ans);
  return 0;
}