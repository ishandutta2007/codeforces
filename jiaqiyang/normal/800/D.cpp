#include <cctype>
#include <stdio.h>

typedef long long i64;

const int N = 1000000, MOD = 1000000007;

inline void add(int &lhs, i64 rhs) { lhs = (lhs + rhs) % MOD; }

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int n, base[7];
int f[N][3];

inline int get(int x, int y) { return x / base[y] % 10; }

int main() {
  scanf("%d", &n);
  base[0] = 1;
  for (int i = 1; i <= 6; ++i) base[i] = 10 * base[i - 1];
  for (int i = n; i--;) {
    int a = nextInt();
    add(f[a][0], 1);
    add(f[a][1], a);
    add(f[a][2], (i64)a * a);
  }
  for (int i = 0; i < 6; ++i) {
    for (int j = N - 1; j >= 0; --j) {
      if (!get(j, i)) continue;
      int k = j - base[i];
      add(f[k][0], f[j][0]);
      add(f[k][1], f[j][1]);
      add(f[k][2], f[j][2]);
    }
  }
  static int res[N], mem[N + 1];
  mem[0] = 1;
  for (int i = 1; i <= N; ++i) mem[i] = 2 * mem[i - 1] % MOD;
  for (int i = 0; i < N; ++i) {
    int x = f[i][0], y = f[i][1], z = f[i][2];
    res[i] = ((i64)y * y - z) % MOD * (x > 1 ? mem[x - 2] : 0) % MOD;
    add(res[i], x ? (i64)z * mem[x - 1] : 0);
  }
  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < N; ++j)
      if (get(j, i)) add(res[j - base[i]], -res[j]);
  i64 ans = 0;
  for (int i = 0; i < N; ++i) ans ^= ((i64)res[i] + MOD) % MOD * i;
  printf("%lld\n", ans);
  return 0;
}