#include <cstdio>
#include <algorithm>

#define fst first
#define snd second

typedef long long i64;

const int N = 500000 + 10;

int n, k, c[N];

int main() {
  scanf("%d%d", &n, &k);
  i64 sum = 0;
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]), sum += c[i];
  std::sort(c + 1, c + n + 1);
  int max = (sum + n - 1) / n, min = sum / n;
  i64 a = 0;
  int b = 0;
  for (int i = n; i > 0; --i) {
    a += c[i], ++b;
    if (a - (i64)b * c[i] > k) break;
  }
  a -= c[n - b + 1], --b;
  int t = c[n - b + 1];
  int rem = k - (a - (i64)b * t);
  max = std::max(max, t - rem / b);
  a = 0, b = 0;
  for (int i = 1; i <= n; ++i) {
    a += c[i], ++b;
    if ((i64)b * c[i] - a > k) break;
  }
  a -= c[b--];
  t = c[b];
  rem = k - ((i64)b * t - a);
  min = std::min(min, t + rem / b);
  printf("%d\n", max - min);
  return 0;
}