#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 3000 + 10;

int r, c, n, k;

struct Point {
  int x, y;
  inline bool operator< (const Point &rhs) const {
    if (x != rhs.x) return x < rhs.x;
    return y < rhs.y;
  }
} point[N];

int succ[N], pred[N], down[N], cnt[N], con[N];
i64 val;

void rebuild(int p, int v) {
  static int id[N];
  int tot = 0;
  for (int i = p; i && v--; i = pred[i]) id[++tot] = i;
  std::reverse(id + 1, id + tot + 1);
  for (int i = 1, temp = 0; i <= tot; ++i) {
    int &j = down[id[i]];
    val -= con[id[i]];
    if (i == 1) temp = cnt[j = id[i]]; else j = down[id[i - 1]], temp -= cnt[id[i - 1]];
    while (j && temp < k) temp += cnt[j = succ[j]];
    val += (con[id[i]] = (j ? (id[i] - pred[id[i]]) * (c - j + 1) : 0));
  }
}

i64 solve(int s) {
  for (int i = 1; i <= c; ++i) cnt[i] = 0;
  for (int i = n; i > 0; --i) if (point[i].x >= s) ++cnt[point[i].y]; else break;
  static int id[N];
  int tot = 0;
  for (int i = 1; i <= c; ++i) if (cnt[i]) id[++tot] = i;
  for (int i = 1; i < tot; ++i) succ[id[i]] = id[i + 1], pred[id[i + 1]] = id[i];
  pred[id[1]] = succ[id[tot]] = 0;
  for (int i = 1; i <= tot; ++i) con[id[i]] = 0;
  val = 0;
  rebuild(id[tot], tot);
  i64 res = 0;
  for (int e = r, j = n; e >= s; --e) {
    for (; j > 0 && point[j].x > e; --j) {
      int y = point[j].y;
      if (--cnt[y] == 0) {
        int p = pred[y], q = succ[y];
        if (p) succ[p] = q;
        if (q) pred[q] = p;
        val -= con[y];
        rebuild(succ[y] ? succ[y] : pred[y], k + 1);
      } else {
        rebuild(succ[y] ? succ[y] : y, k + 1);
      }
    }
    res += val;
  }
  return res;
}

int main() {
  scanf("%d%d%d%d", &r, &c, &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &point[i].x, &point[i].y);
  std::sort(point + 1, point + n + 1);
  i64 ans = 0;
  for (int i = 1; i <= r; ++i) ans += solve(i);
  printf("%I64d\n", ans);
  return 0;
}