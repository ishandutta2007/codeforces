#include <cstdio>
#include <cstring>

typedef long long i64;

const int N = 100000 + 10;

int n;

inline int lowbit(int x) { return x & -x; }

int tree[2 * N];

inline void add(int pos, int val) {
  while (pos <= 2 * n) {
    tree[pos] += val;
    pos += lowbit(pos);
  }
}

inline int query(int pos) {
  int res = 0;
  while (pos) {
    res += tree[pos];
    pos -= lowbit(pos);
  }
  return res;
}

int x[2 * N], y[2 * N], z[2 * N], map[2 * N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    map[a] = b;
    map[b] = a;
  }
  static int sum[2 * N];
  memset(sum, 0, sizeof sum);
  memset(tree, 0, sizeof tree);
  for (int i = 1; i <= 2 * n; ++i) {
    sum[i] = sum[i - 1];
    if (map[i] < i) {
      z[map[i]] += query(map[i]) - sum[map[i]];
      y[map[i]] += sum[i] - query(map[i]);
      ++sum[i];
      add(map[i], 1);
    }
  }
  memset(sum, 0, sizeof sum);
  memset(tree, 0, sizeof tree);
  for (int i = 2 * n; i > 0; --i) {
    sum[i] = sum[i + 1];
    if (i < map[i]) {
      z[i] += query(2 * n - map[i] + 1) - sum[map[i]];
      ++sum[i];
      add(2 * n - map[i] + 1, 1);
    }
  }
  i64 a = 0, b = 0;
  for (int i = 1; i <= 2 * n; ++i) {
    x[i] = n - 1 - y[i] - z[i];
    a += (i64)x[i] * y[i];
    b += (i64)(x[i] + y[i]) * z[i];
  }
  printf("%I64d\n", (i64)n * (n - 1) * (n - 2) / 6 - a - b / 2);
  return 0;
}