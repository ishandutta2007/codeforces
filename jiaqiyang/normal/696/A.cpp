#include <cstdio>
#include <map>

typedef long long i64;

inline int depth(i64 x) {
  int res = 1;
  for (; x; x >>= 1) ++res;
  return res;
}

std::map<i64, i64> cur;

void add(i64 x, i64 y, int z) {
  while (x != y) {
    if (depth(x) < depth(y)) std::swap(x, y);
    cur[x] += z;
    x >>= 1;
  }
}

i64 query(i64 x, i64 y) {
  i64 res = 0;
  while (x != y) {
    if (depth(x) < depth(y)) std::swap(x, y);
    res += cur[x];
    x >>= 1;
  }
  return res;
}

int main() {
  int tcase;
  for (scanf("%d", &tcase); tcase--;) {
    int op;
    i64 u, v;
    scanf("%d%lld%lld", &op, &u, &v);
    if (op == 1) {
      int w;
      scanf("%d", &w);
      add(u, v, w);
    } else {
      printf("%lld\n", query(u, v));
    }
  }
  return 0;
}