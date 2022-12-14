#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10;

int n, a[N], p[N];

bool flag[N];

int anc[N];
i64 sum[N], ans[N], cur;

int find(int x) { return anc[x] == x ? x : (anc[x] = find(anc[x])); }

void meld(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  anc[x] = y;
  cur = std::max(cur, sum[y] += sum[x]);
}

void solve(int x) {
  anc[x] = x;
  cur = std::max(cur, sum[x] = a[x]);
  flag[x] = true;
  if (flag[x - 1]) meld(x, x - 1);
  if (flag[x + 1]) meld(x, x + 1);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
  static i64 ans[N];
  for (int i = n; i > 0; --i) ans[i] = cur, solve(p[i]);
  for (int i = 1; i <= n; ++i) printf("%lld\n", ans[i]);
  return 0;
}