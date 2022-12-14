#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int m, n, a[N];

void init() {
  int p = -1, v = -1;
  for (int i = 0; i < n; ++i) {
    int t = (a[(i + 1) % n] - a[i] + m) % m;
    if (t > v) v = t, p = i;
  }
  std::rotate(a, a + (p = (p + 1) % n), a + n);
  for (int i = 1; i < n; ++i) if (a[i] < a[i - 1]) a[i] += m;
  for (int i = 0, j = a[0]; i < n; ++i) a[i] -= j;
}

int f[N], b;

int dp(int s) {
  std::fill(f + s, f + n, 0);
  for (int i = s; i < n; ++i) {
    if (f[i - 1] + 1 < a[i] - b) return false;
    f[i] = a[i];
    if (f[i - 1] + 1 >= a[i]) f[i] = std::max(f[i], a[i] + b);
    if (i > s && f[i - 2] + 1 >= a[i] - b) f[i] = std::max(f[i], a[i - 1] + b);
  }
  return f[n - 1];
}

bool check() {
  f[0] = 0;
  if (dp(1) + 1 >= m - b) return true;
  if (a[0] + b + 1 >= a[1]) {
    f[1] = std::max(a[0] + b, a[1]);
    if (dp(2) + 1 >= m + std::min(0, a[1] - b)) return true;
  }
  return false;
}

int main() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]), --a[i];
  if (n == 1) return printf("%d\n", m - 1), 0;
  init();
  int l = 0, r = m - a[n - 1];
  while (l < r) {
    int mid = (l + r) >> 1;
    if (b = mid, check()) r = mid; else l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}