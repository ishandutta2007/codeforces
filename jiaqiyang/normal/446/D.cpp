#include <bits/stdc++.h>

const int N = 500 + 5;

typedef double matrix[N][N];

int n, m, k;
bool flag[N];
int trap[N], cnt;
int deg[N], e[N][N];

double p[N][N * 2];
matrix w;

void gauss() {
  memset(p, 0, sizeof (p));
  for (int i = 1; i <= n; ++i) {
    p[i][i] = p[i][i + n] = 1.0;
    for (int j = 1; j <= n; ++j)
      if (!flag[j] && j != i) p[i][j] = -e[i][j] / (double)deg[j];
  }
  for (int i = 1; i <= n; ++i) {
    double cur = p[i][i];
    for (int j = 1; j <= n * 2; ++j) p[i][j] /= cur;
    for (int j = 1; j <= n; ++j) {
      if (j != i) {
        double tmp = p[j][i];
        for (int k = 1; k <= 2 * n; ++k) p[j][k] -= tmp * p[i][k];
      }
    }
  }
  for (int i = 1; i <= cnt; ++i)
    for (int j = 1; j <= cnt; ++j)
      for (int k = 1; k <= n; ++k)
        w[j][i] += p[trap[i]][k + n] * (e[k][trap[j]] / (double)deg[trap[j]]);
}

void mul(matrix a, const matrix b) {
  static matrix c;
  memset(c, 0, N * N * sizeof(double));
  for (int k = 1; k <= cnt; ++k)
    for (int i = 1; i <= cnt; ++i)
      for (int j = 1; j <= cnt; ++j)
        c[i][j] += a[i][k] * b[k][j];
  memcpy(a, c, N * N * sizeof(double));
}

inline void pow(matrix a, int k) {
  static matrix res, base;
  memcpy(base, a, N * N * sizeof(double));
  for (int i = 1; i <= cnt; ++i) res[i][i] = 1;
  while (k) {
    if (k & 1) mul(res, base);
    mul(base, base);
    k >>= 1;
  }
  memcpy(a, res, N * N * sizeof(double));
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", flag + i);
    if (flag[i]) trap[++cnt] = i;
  }
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    deg[u]++, deg[v]++;
    e[u][v]++, e[v][u]++;
  }
  gauss();
  pow(w, k -= 2);
  double ans = 0;
  for (int i = 1; i <= cnt; ++i) ans += p[trap[i]][1 + n] * w[i][cnt];
  printf("%.10lf\n", ans);
  return 0;
}