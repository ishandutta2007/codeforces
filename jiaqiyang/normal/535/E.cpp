#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

#define x first
#define y second

typedef std::pair<double, double> Point;

const int N = 200000 + 10;
const double eps = 1e-22;

int n, mx[N];
Point pool[N];

inline double Cross(const Point &o, const Point &a, const Point &b) {
  return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

inline int sgn(double num) {
  if (fabs(num) < eps) return 0;
  return num > 0 ? 1 : -1;
}

inline bool Compare(int a, int b) {
  return pool[a] < pool[b];
//if (pool[a].x != pool[b].x) return pool[a].x < pool[b].x;
//return pool[a].y > pool[b].y;
}

int main() {
  scanf("%d", &n);
  static int order[N];
  for (int i = 1; i <= n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    pool[i].x = 1.0 / a;
    pool[i].y = 1.0 / b;
  }
  pool[0].y = pool[n + 1].x = 1e9;
  for (int i = 0; i <= n + 1; ++i) order[i] = i;
  std::sort(order, order + n + 2, Compare);
  static std::vector<int> convex, ans;
  for (int it = 0; it <= n + 1; ++it) {
    int i = order[it];
    while (convex.size() > 1 && sgn(Cross(pool[order[convex[convex.size() - 2]]], pool[order[convex.back()]], pool[i]) <= 0)) convex.pop_back();
    convex.push_back(it);
  }
  for (int i = 1, j = 0; i <= n; ++i) {
    while (j + 1 < convex.size() && convex[j + 1] <= i) ++j;
    if (sgn(Cross(pool[order[convex[j]]], pool[order[convex[j + 1]]], pool[order[i]])) == 0) ans.push_back(order[i]);
  }
  std::sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
  putchar('\n');
  return 0;
}