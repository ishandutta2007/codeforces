#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

typedef long long i64;

const int N = 1000000 + 10;

int n, size = 0;

struct Info {
  int x, y, z, id;
  inline bool operator< (const Info &rhs) const {
    return z < rhs.z || (z == rhs.z && y < rhs.y) || (z == rhs.z && y == rhs.y && x < rhs.x);
  }
} info[N];

void check(int th) {
  for (int i = 1; i <= n; ++i) info[i].z = info[i].x / th;
  std::sort(info + 1, info + n + 1);
  i64 cur = 0;
  for (int i = 2; i <= n; ++i) cur += abs(info[i].x - info[i - 1].x) + abs(info[i].y - info[i - 1].y);
  if (cur <= 2500000000LL) {
    for (int i = 1; i <= n; ++i) printf("%d ", info[i].id);
    exit(0);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &info[i].x, &info[i].y), info[i].id = i;
  check(1000);
  check(900);
  check(1100);
  check(1250);
  check(800);
  return 0;
}