#include <cstdio>

const int N = 100 + 10;

int bit[N];

int n, m, a, b;

int count(int x) {
  if (!x) return 1;
  int res = 0;
  for (; x; x /= 7) ++res;
  return res;
}

bool check(int x, int y) {
  static int tag[N], cnt;
  ++cnt;
  for (int i = a; i--; x /= 7) {
    int t = x % 7;
    if (tag[t] == cnt) return false;
    tag[t] = cnt;
  }
  for (int i = b; i--; y /= 7) {
    int t = y % 7;
    if (tag[t] == cnt) return false;
    tag[t] = cnt;
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  --n, --m;
  a = count(n), b = count(m);
  if (a + b > 7) {
    puts("0");
    return 0;
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j)
      if (check(i, j)) ++ans;
  printf("%d\n", ans);
  return 0;
}