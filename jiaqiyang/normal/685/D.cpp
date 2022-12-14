#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10, K = 300 + 10, S = K * N;

int n, k;

struct Point {
  int x, y;
  inline bool operator< (const Point &rhs) const {
    return x < rhs.x;
  }
} point[N];

struct Event {
  int x, y1, y2, z;
  Event() {}
  Event(int _x, int _y1, int _y2, int _z): x(_x), y1(_y1), y2(_y2), z(_z) {}
  inline bool operator< (const Event &rhs) const {
    return x < rhs.x;
  }
} event[2 * N];

int cnt;

int sorted[S], cur[S], tot;

i64 ans[N];

void inc(int p, int x) {
  ans[cur[p]] += x;
  ans[++cur[p]] -= x;
}

void dec(int p, int x) {
  ans[cur[p]] += x;
  ans[--cur[p]] -= x;
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &point[i].x, &point[i].y);
    for (int j = 0; j < k; ++j) sorted[++tot] = point[i].y - j;
    event[++cnt] = Event(point[i].x - k + 1, point[i].y - k + 1, point[i].y, 1);
    event[++cnt] = Event(point[i].x + 1, point[i].y - k + 1, point[i].y, -1);
  }
  std::sort(sorted + 1, sorted + tot + 1);
  tot = std::unique(sorted + 1, sorted + tot + 1) - sorted - 1;
  std::sort(event + 1, event + cnt + 1);
  for (int i = 1; i <= cnt; ++i) {
    int t = event[i].x;
    int l = event[i].y1 = std::lower_bound(sorted + 1, sorted + tot + 1, event[i].y1) - sorted;
    int r = event[i].y2 = std::lower_bound(sorted + 1, sorted + tot + 1, event[i].y2) - sorted;
    for (int j = l; j <= r; ++j) if (event[i].z > 0) inc(j, t); else dec(j, t);
  }
  for (int i = 1; i <= n; ++i) printf("%I64d ", ans[i]);
  return 0;
}