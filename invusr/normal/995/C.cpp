#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using s64 = long long;
using u64 = unsigned long long;

using r32 = double;
using r64 = long double;

inline int getint() {
  static char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');

  if (c == '-') {
    int res = 0;
    while ((c = getchar()) >= '0' && c <= '9') {
      res = res * 10 + c - '0';
    }
    return -res;
  } else {
    int res = c - '0';
    while ((c = getchar()) >= '0' && c <= '9') {
      res = res * 10 + c - '0';
    }
    return res;
  }
}

const int MaxN = 100000;
const s64 L = 1500000ll * 1500000ll;

int n;

struct point {
  int x, y;
  point() {}
  point(const int &_x, const int &_y)
    : x(_x), y(_y) {}

  inline s64 norm_sqr() const {
    return (s64)x * x + (s64)y * y;
  }

  friend inline point operator+(const point &lhs, const point &rhs) {
    return point(lhs.x + rhs.x, lhs.y + rhs.y);
  }
  friend inline point operator-(const point &lhs, const point &rhs) {
    return point(lhs.x - rhs.x, lhs.y - rhs.y);
  }
};
point po[MaxN + 1];

int idx[MaxN + 1];

int f[MaxN + 1];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    po[i].x = getint(), po[i].y = getint();
    idx[i] = i;
  }

  sort(idx + 1, idx + n + 1, [&](int u, int v) {
    return po[u].norm_sqr() > po[v].norm_sqr();
  });

  point cur(0, 0);
  for (int i = 1; i <= n; ++i) {
    int k = idx[i];
    s64 u = (cur + po[k]).norm_sqr();
    s64 v = (cur - po[k]).norm_sqr();
    if (u <= v) {
      f[k] = 1, cur = cur + po[k];
    } else {
      f[k] = -1, cur = cur - po[k];
    }
  }

  srand(time(nullptr));

  while ((r32)clock() / CLOCKS_PER_SEC < 1.9 && cur.norm_sqr() > L) {
    random_shuffle(idx + 1, idx + n + 1);

    cur = point(0, 0);
    for (int i = 1; i <= n; ++i) {
      int k = idx[i];
      s64 u = (cur + po[k]).norm_sqr();
      s64 v = (cur - po[k]).norm_sqr();
      if (u <= v) {
        f[k] = 1, cur = cur + po[k];
      } else {
        f[k] = -1, cur = cur - po[k];
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    printf("%d ", f[i]);
  }
  puts("");

  return 0;
}