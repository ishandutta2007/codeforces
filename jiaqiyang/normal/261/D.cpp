#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 100000 + 10, SZ = 5000 + 10;

inline void cmax(int &a, int b) { if (b > a) a = b; }

int tcase, n, maxb, t, b[N];

inline int Discretize(int num[]) {
  static std::vector<int> sorted;
  sorted.clear();
  for (int i = 1; i <= n; ++i) sorted.push_back(num[i]);
  std::sort(sorted.begin(), sorted.end());
  sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
  for (int i = 1; i <= n; ++i) num[i] = std::lower_bound(sorted.begin(), sorted.end(), num[i]) - sorted.begin() + 1;
  return sorted.size();
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d%d%d%d", &tcase, &n, &maxb, &t);
  while (tcase--) {
    for (int i = 1; i <= n; ++i) scanf("%d", b + i);
    maxb = Discretize(b);
    int cur = std::min(t, maxb);
    if (cur == maxb) { printf("%d\n", maxb);
      continue;
    }
    static int f[SZ];
    memset(f, 0, sizeof f);
    while (cur--) {
      for (int i = 1; i <= n; ++i) {
        int temp = f[b[i] - 1] + 1;
        for (int j = b[i]; j <= maxb; ++j)
          if (f[j] < temp) f[j] = temp; else break;
      }
    }
    printf("%d\n", *std::max_element(f, f + maxb + 1));
  }
  return 0;
}