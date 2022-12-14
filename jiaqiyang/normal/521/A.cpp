#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10, MOD = 1000000007;

int main() {
  int n;
  static char s[N];
  scanf("%d %s", &n, s);
  static int cnt[4];
  for (char *i = s; *i; ++i) {
    if (*i == 'A') ++cnt[0];
    if (*i == 'T') ++cnt[1];
    if (*i == 'C') ++cnt[2];
    if (*i == 'G') ++cnt[3];
  }
  std::sort(cnt, cnt + 4);
  int ans = 1;
  int x = 3;
  while (x >= 0 && cnt[x] == cnt[3]) --x;
  for (int i = n; i--;) ans = (3LL - x) * ans % MOD;
  printf("%d\n", ans);
  return 0;
}