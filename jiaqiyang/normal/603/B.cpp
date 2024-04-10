#include <cstdio>

typedef long long i64;

const int N = 1000000 + 10, MOD = 1000000007;

int power(int base, int exp) {
  int res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) res = (i64)res * base % MOD;
    base = (i64)base * base % MOD;
  }
  return res;
}

int p, k, ans[N];

bool flag[N];

int cnt[N], sum[N];

int main() {
  scanf("%d%d", &p, &k);
  if (k == 0) {
    printf("%d\n", power(p, p - 1));
    return 0;
  }
  for (int i = 0; i < p; ++i) {
    if (flag[i]) continue;
    int cur = 0;
    for (int j = i; !flag[j]; j = (i64)j * k % p) flag[j] = true, ++cur;
    ++cnt[cur];
  }
  for (int i = 1; i <= p; ++i)
    for (int j = i; j <= p; j += i)
      sum[j] = (sum[j] + (i64)i * cnt[i]) % MOD;
  int ans = 1;
  for (int i = 1; i <= p; ++i) ans = (i64)ans * power(sum[i], cnt[i]) % MOD;
  printf("%d\n", ans);
  return 0;
}