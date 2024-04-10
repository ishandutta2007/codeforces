#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

typedef long long i64;

inline void check(i64 &lhs, i64 rhs) { if (rhs < lhs) lhs = rhs; }

const int N = 300000 + 10, K = 5000 + 10;
const i64 INF = 1LL << 60;

int nextInt() {
  char ch;
  while (ch = getchar(), ch != '-' && !isdigit(ch)) {}
  bool flag = (ch == '-');
  if (flag) ch = getchar();
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return flag ? -res : res;
}

int n, k, a[N];

std::vector<i64> f[K];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) a[i] = nextInt();
  std::sort(a + 1, a + n + 1);
  int cnt = n / k;
  int p = n - cnt * k;
  for (int i = 0; i <= k; ++i) f[i].resize(p + 1, INF);
  f[0][0] = 0;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j <= p; ++j) {
      int cur = i * cnt + j;
      check(f[i + 1][j], f[i][j] + abs(a[cur + cnt] - a[cur + 1]));
      if (j < p) check(f[i + 1][j + 1], f[i][j] + abs(a[cur + cnt + 1] - a[cur + 1]));
    }
  }
  std::cout << f[k][p] << '\n';
  return 0;
}