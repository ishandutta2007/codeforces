#include <cstdio>
#include <algorithm>

const int N = 2000 + 10;

int moe[N];

void sieve() {
  moe[1] = 1;
  static bool flag[N];
  static int prime[N];
  int tot = 0;
  for (int i = 2; i < N; ++i) {
    if (!flag[i]) moe[prime[++tot] = i] = -1;
    for (int j = 1; j <= tot && i * prime[j] < N; ++j) {
      flag[i * prime[j]] = true;
      if (i % prime[j] == 0) {
        moe[i * prime[j]] = 0;
        break;
      }
      moe[i * prime[j]] = -moe[i];
    }
  }
}

int a, b, c;

int gcd[N][N];

unsigned f(int x, int y) {
  unsigned res = 0;
  for (int i = 1; i <= y; ++i) if (gcd[i][x] == 1) res += y / i;
  return res;
}

unsigned solve(int x) {
  unsigned res = 0;
  for (int i = 1; i <= b; ++i) if (gcd[i][x] == 1 && moe[i]) res += moe[i] * f(x, b / i) * f(x, c / i);
  return res;
}

int main() {
  for (int i = 1; i < N; ++i) gcd[i][0] = gcd[0][i] = i;
  for (int i = 1; i < N; ++i)
    for (int j = 1; j <= i; ++j)
      gcd[i][j] = gcd[j][i] = gcd[j][i % j];
  sieve();
  scanf("%d%d%d", &a, &b, &c);
  if (a > b) std::swap(a, b);
  if (a > c) std::swap(a, c);
  if (b > c) std::swap(b, c);
  unsigned ans = 0;
  for (int i = 1; i <= a; ++i) ans += (a / i) * solve(i);
  printf("%u\n", ans & ((1 << 30) - 1));
  return 0;
}