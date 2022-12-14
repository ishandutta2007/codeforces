#include <cstdio>
#include <map>

typedef long long i64;

typedef std::pair<int, int> Point;

int n;
std::map<int, int> x, y;
std::map<Point, int> z;

inline i64 calc(int x) { return x * (x - 1LL) / 2; }

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    ++x[a], ++y[b], ++z[Point(a, b)];
  }
  i64 ans = 0;
  for (std::map<int, int>::iterator it = x.begin(); it != x.end(); ++it) ans += calc(it->second);
  for (std::map<int, int>::iterator it = y.begin(); it != y.end(); ++it) ans += calc(it->second);
  for (std::map<Point, int>::iterator it = z.begin(); it != z.end(); ++it) ans -= calc(it->second);
  printf("%I64d\n", ans);
  return 0;
}