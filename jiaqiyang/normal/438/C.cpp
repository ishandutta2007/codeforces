#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define x first
#define y second

typedef std::pair<int, int> Point;
typedef long long i64;

const int N = 200 + 10, MOD = 1000000007;

int n;
Point poly[N];

i64 sum[N];

inline i64 Cross(const Point &a, const Point &b) {
  return (i64)a.x * b.y - (i64)a.y * b.x;
}

int mem[N][N];

inline i64 Area(int l, int r) {
  return llabs(sum[r - 1] - sum[l - 1] + Cross(poly[r], poly[l]));
}

inline i64 Area(const Point &a, const Point &b, const Point &c) {
  return llabs(Cross(a, b) + Cross(b, c) + Cross(c, a));
}

int Solve(int l, int r) {
  int &res = mem[l][r];
  if (~res) return res;
  if (r - l < 2) return res = 1;
  res = 0;
  for (int i = l + 1; i < r; ++i) {
    i64 temp = Area(poly[l], poly[i], poly[r]);
    if (temp && Area(l, i) + Area(i, r) + temp == Area(l, r))
      (res += (i64)Solve(l, i) * Solve(i, r) % MOD) %= MOD;
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &poly[i].x, &poly[i].y);
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + Cross(poly[i], poly[i % n + 1]);
  memset(mem, -1, sizeof mem);
  printf("%d\n", Solve(1, n));
  return 0;
}