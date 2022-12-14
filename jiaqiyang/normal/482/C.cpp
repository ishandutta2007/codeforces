#include <cstdio>
#include <cstring>

typedef long long i64;

const int N = 50 + 1, S = 1 << 20;

int n, m;
char s[N][N];

bool flag[S];

i64 tar, mask[N];

int binom[N][N];

double ans = 0.;

void dfs(int dep, int s, i64 t, int cnt) {
  if (dep == m) {
    if (t != tar) ans += 1. / binom[m][cnt];
    return;
  }
  dfs(dep + 1, s, t, cnt);
  dfs(dep + 1, s | (1 << dep), t | mask[dep], cnt + 1);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf(" %s", s[i]);
  m = strlen(s[1]);
  binom[0][0] = 1;
  for (int i = 1; i < N; ++i)
    for (int j = 0; j < N; ++j)
      binom[i][j] = binom[i - 1][j] + (j ? binom[i - 1][j - 1] : 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      mask[j] = 0;
      for (int k = 0; k < n; ++k)
        if (s[i][j] != s[k][j]) mask[j] |= 1LL << k;
    }
    tar = (1LL << n) - 1;
    dfs(0, 0, 1LL << i, 0);
  }
  printf("%.12f\n", ans / n);
  return 0;
}