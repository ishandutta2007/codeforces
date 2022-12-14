#include <cctype>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

typedef long long i64;

const int N = 1 << 21, MOD = 998244353;

inline int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

inline int power(int base, int exp) {
  int res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) res = (i64)res * base % MOD;
    base = (i64)base * base % MOD;
  }
  return res;
}

void ntt(int a[], int sig) {
  for (int i = 0, j = 0; i < N; ++i) {
    if (i < j) std::swap(a[i], a[j]);
    for (int k = N >> 1; k && (j ^= k) < k;) k >>= 1;
  }
  for (int m = 2; m <= N; m *= 2) {
    int gap = m / 2, w = power(3, (MOD - 1) / m);
    if (sig < 0) w = power(w, MOD - 2);
    for (int i = 0; i < N; i += m) {
      for (int j = i, o = 1; j < i + gap; ++j, o = (i64)o * w % MOD) {
        int u = a[j], v = (i64)o * a[j + gap] % MOD;
        a[j] = (u + v) % MOD;
        a[j + gap] = (u - v + MOD) % MOD;
      }
    }
  }
  if (sig < 0) for (int i = 0, inv = power(N, MOD - 2); i < N; ++i) a[i] = (i64)a[i] * inv % MOD;
}

int main() {
  int n = nextInt(), m = nextInt();
  static int poly[N], orig[N];
  for (int i = 1; i <= n; ++i) poly[nextInt()] = 1;
  memcpy(orig, poly, sizeof poly);
  ntt(poly, 1);
  for (int i = 0; i < N; ++i) poly[i] = (i64)poly[i] * poly[i] % MOD;
  ntt(poly, -1);
  std::vector<int> ans;
  for (int i = 1; i <= m; ++i) {
    if (poly[i] && !orig[i]) return puts("NO"), 0;
    if (!poly[i] && orig[i]) ans.push_back(i);
  }
  printf("YES\n%u\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
  return 0;
}