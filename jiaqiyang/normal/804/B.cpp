#include <cstdio>
#include <cstring>

const int N = 1000000 + 10, MOD = 1000000007;

int b = 0, a = 0, p[N];

char s[N];

int main() {
  p[0] = 1;
  for (int i = 1; i < N; ++i) p[i] = 2LL * p[i - 1] % MOD;
  scanf(" %s", s);
  for (char *i = s; *i; ++i) if (*i == 'a') ++a; else b = (b + p[a]) % MOD;
  printf("%d\n", ((((a + b) % MOD - strlen(s)) % MOD) + MOD) % MOD);
  return 0;
}