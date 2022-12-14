#include <cstdio>
#include <climits>
#include <cassert>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10;

int n;

struct Point {
  int x, y;
  inline bool operator< (const Point &rhs) const {
    return x != rhs.x ? x < rhs.x : y < rhs.y;
  }
} point[N];

struct Info {
  int min, max;
  Info(): min(INT_MAX), max(INT_MIN) {}
  Info(int _x): min(_x), max(_x) {}
  Info(int _min, int _max): min(_min), max(_max) {}
  inline Info& operator+= (const Info &rhs) {
    min = std::min(min, rhs.min);
    max = std::max(max, rhs.max);
    return *this;
  }
} pre[N], suf[N];

inline Info operator+ (Info lhs, const Info &rhs) { return lhs += rhs; }

inline i64 sqr(i64 x) { return x * x; }

i64 calc(int l, int r) {
  Info horz(point[l].x, point[r].x);
  i64 res = sqr(horz.max - horz.min);
  Info vert = pre[l - 1] + suf[r + 1];
  if (vert.min == INT_MAX && vert.max == INT_MIN) return res;
  res = std::max(res, sqr(vert.max - vert.min));
  res = std::max(res, sqr(vert.min) + sqr(horz.min));
  res = std::max(res, sqr(vert.min) + sqr(horz.max));
  res = std::max(res, sqr(vert.max) + sqr(horz.min));
  res = std::max(res, sqr(vert.max) + sqr(horz.max));
  return res;
}

bool solve(i64 th) {
  for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + point[i].y;
  if (sqr(pre[n].max - pre[n].min) <= th) return true;
  for (int i = n; i > 0; --i) suf[i] = suf[i + 1] + point[i].y;
  for (int i = 1, j = 1; i <= n; ++i) {
    while (j < n && abs(point[j + 1].x) <= abs(point[i].x) && sqr(point[j + 1].x - point[i].x) <= th) ++j;
    while (j > i && abs(point[j].x) > abs(point[i].x)) --j;
    if (calc(i, j) <= th) return true;
  }
  return false;
}

inline bool check(i64 th) {
  if (solve(th)) return true;
  std::reverse(point + 1, point + n + 1);
  return solve(th);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &point[i].x, &point[i].y);
  std::sort(point + 1, point + n + 1);
  i64 l = 0, r = sqr(point[n].x - point[1].x);
  while (l < r) {
    i64 mid = (l + r) / 2;
    if (check(mid)) r = mid; else l = mid + 1;
  }
  printf("%I64d\n", l);
  return 0;
}