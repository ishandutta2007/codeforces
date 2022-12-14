#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

typedef long long i64;
typedef std::pair<i64, int> Info;

const int N = 100000 + 10, S = 1000 + 10;
const i64 INF = 1LL << 60;

int n, size;

struct Point {
  i64 x, y;
  int z;
  Point() {}
  Point(i64 _x, i64 _y, int _z): x(_x), y(_y), z(_z) {}
};

inline bool concavity(const Point &o, const Point &a, const Point &b) {
  return (a.x - o.x) * (b.y - o.y) < (a.y - o.y) * (b.x - o.x);
}

inline i64 calc(const Point &a, i64 k) { return k * a.x + a.y; }

struct Hull {
  std::vector<int> a, order;
  std::vector<i64> b;
  std::vector<bool> flag;
  std::vector<Point> q;
  int n, f, pre;
  i64 suf;
  void init(std::vector<int> &_a) {
    a.swap(_a);
    b.resize(n = a.size());
    order.resize(n);
    flag.resize(n);
    for (int i = 0; i < n; ++i) order[i] = i;
    std::sort(order.begin(), order.end(), [&] (int lhs, int rhs) { return a[lhs] < a[rhs]; });
    pre = suf = 0;
    build();
  }
  void build() {
    std::vector<i64> b(n);
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) if (flag[i]) b[i] = a[i], c[i] = 1;
    for (int i = 1; i < n; ++i) c[i] += c[i - 1];
    for (int i = n - 2; i >= 0; --i) b[i] += b[i + 1];
    q.clear();
    for (int i = 0; i < n; ++i) {
      int j = order[i];
      if (flag[j]) continue;
      Point cur(a[j], b[j] + a[j] * (c[j] + 1LL), j);
      if (!q.empty() && q.back().x == cur.x) {
        if (q.back().y >= cur.y) continue;
        q.pop_back();
      }
      while (q.size() > 1 && !concavity(q[q.size() - 2], q.back(), cur)) q.pop_back();
      q.push_back(cur);
    }
    f = 0;
  }
  Info solve() {
    while (f + 1 < q.size() && calc(q[f], pre) <= calc(q[f + 1], pre)) ++f;
    return q.empty() ? Info(-INF, -1) : Info(calc(q[f], pre) + suf, q[f].z);
  }
  inline void del(int x) {
    flag[x] = true;
    build();
  }
} hull[S];

int main() {
  scanf("%d", &n);
  size = sqrt(n) + .5;
  for (int i = 0; i < n; i += size) {
    std::vector<int> cur;
    for (int j = i; j < i + size && j < n; ++j) {
      int x;
      scanf("%d", &x);
      cur.push_back(x);
    }
    hull[i / size].init(cur);
  }
  i64 ans = 0, cur = 0;
  for (int i = n; i--;) {
    Info info(-INF, -1);
    for (int j = 0; j * size < n; ++j) {
      Info temp = hull[j].solve();
      temp.second += j * size;
      info = std::max(info, temp);
    }
    int x = info.second / size, y = info.second % size;
    for (int j = 0; j < x; ++j) hull[j].suf += hull[x].a[y];
    for (int j = x + 1; j * size < n; ++j) ++hull[j].pre;
    hull[x].del(y);
    ans = std::max(ans, cur += info.first);
  }
  std::cout << ans << '\n';
  return 0;
}