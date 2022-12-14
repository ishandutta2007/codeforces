#include <cstdio>
#include <cstring>

const int N = 200 + 10, MOD = 10007;

typedef int matrix[2 * N][2 * N];

int n, len, x, y, z, tot;
char s[N];

void Multiply(matrix lhs, const matrix rhs) {
  static matrix res;
  memset(res, 0, sizeof res);
  for (register int i = 1; i <= tot; ++i) {
    for (register int k = i; k <= tot; ++k) {
      if (!lhs[i][k]) continue;
      for (register int j = k; j <= tot; ++j)
        (res[i][j] += lhs[i][k] * rhs[k][j]) %= MOD;
    }
  }
  memcpy(lhs, res, sizeof res);
}

void Pow(matrix a, int exp) {
  static matrix res;
  memset(res, 0, sizeof res);
  for (int i = 1; i <= tot; ++i) res[i][i] = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) Multiply(res, a);
    Multiply(a, a);
  }
  memcpy(a, res, sizeof res);
}

matrix u, v;

void Preprocessing() {
  static matrix temp;
  for (int i = 1; i <= x; ++i) temp[i][i] = 24;
  for (int i = x + 1; i <= x + y; ++i) {
    temp[i][i] = 25;
    temp[i][y + i] = 1;
  }
  for (int i = 1; i < x + y; ++i) temp[i][i + 1] = 1;
  for (int i = x + y + 1; i <= tot; ++i) temp[i][i] = 26;
  memcpy(v, temp, sizeof v);
  Pow(v, (len - 1) / 2);
  memcpy(u, v, sizeof u);
  Multiply(u, temp);
}

int mem[N][N][N];

int Solve(int l, int r, int rem) {
  if (rem < 0) return 0;
  int &res = mem[l][r][rem];
  if (~res) return res;
  if (l == r || (l + 1 == r && s[l] == s[r]))
    res = (rem == 0);
  else if (s[l] == s[r])
    res = Solve(l + 1, r - 1, rem);
  else
    res = Solve(l + 1, r, rem - 1) + Solve(l, r - 1, rem - 1);
  return res %= MOD;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  scanf(" %s%d", s + 1, &len);
  len += (n = strlen(s + 1));
  x = n - 1;
  y = z = (n + 1) / 2;
  tot = x + y + z;
  Preprocessing();
  memset(mem, -1, sizeof mem);
  int ans = 0;
  for (int i = 0; i <= x; ++i) {
    int j = (n - i + 1) / 2;
    int cur = Solve(1, n, i);
    (ans += cur * u[x - i + 1][x + y + j] % MOD) %= MOD;
    if ((len & 1) && ((n - i) & 1) == 0)
      (ans -= cur * v[x - i + 1][x + j] % MOD) %= MOD;
  }
  printf("%d\n", (ans + MOD) % MOD);
  return 0;
}