#include <cstdio>
#include <cstring>

typedef long long i64;

const int N = 100 + 10;
const int p[] = {4, 5, 6, 3, 2, 1};

char s[N];

int main() {
  scanf(" %s", s + 1);
  int l = strlen(s + 1);
  i64 n = 0;
  for (int i = 1; i < l; ++i) n = 10 * n + s[i] - '0';
  --n;
  i64 ans = (n % 4 < 2 ? n : (n - 2));
  ans += 12 * (n / 4);
  if (n & 1) ans += 6;
  ans += p[s[l] - 'a'];
  printf("%lld\n", ans);
  return 0;
}