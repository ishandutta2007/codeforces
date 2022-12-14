#include <cstdio>
#include <set>
#include <algorithm>

const int N = 50000 + 10;

int n, y[N];

int x[N];

std::set<int> pool;

bool check(int t) {
  pool.clear();
  for (int i = n; i > 0; --i) {
    bool flag = false;
    for (int z = y[i]; z; z >>= 1) {
      if (z <= t && !pool.count(z)) {
        pool.insert(z);
        flag = true;
        break;
      }
    }
    if (!flag) return false;
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &y[i]);
  std::sort(y + 1, y + n + 1);
  int l = 1, r = 1000000000;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid)) r = mid; else l = mid + 1;
  }
  check(l);
  for (std::set<int>::iterator it = pool.begin(); it != pool.end(); ++it) printf("%d ", *it);
  return 0;
}