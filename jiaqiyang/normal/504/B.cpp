#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 200000 + 10;

int n, a[N], b[N];

int sum[N];

inline void add(int p, int v = 1) {
  for (++p; p <= n; p += p & -p) sum[p] += v;
}

inline int query(int p) {
  int res = 0;
  for (++p; p; p ^= p & -p) res += sum[p];
  return res;
}

void trans(int val[]) {
  memset(sum, 0, sizeof sum);
  for (int i = 0; i < n; ++i) {
    int t = val[i];
    val[i] = query(t);
    add(t);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
  std::reverse(a, a + n);
  std::reverse(b, b + n);
  trans(a);
  trans(b);
  static int c[N];
  for (int i = 0; i < n; ++i) {
    c[i] += a[i] + b[i];
    c[i + 1] += c[i] / (i + 1);
    c[i] %= (i + 1);
  }
  memset(sum, 0, sizeof sum);
  for (int i = 0; i < n; ++i) add(i, 1);
  std::reverse(c, c + n);
  for (int i = 0; i < n; ++i) {
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (query(mid) >= c[i] + 1) r = mid; else l = mid + 1;
    }
    c[i] = l;
    add(c[i], -1);
    printf("%d ", c[i]);
  }
  return 0;
}