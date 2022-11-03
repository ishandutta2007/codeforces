#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1010;

unordered_map <long long, int> rec;

int n, x[N], y[N], a[N], b[N];

inline void add(int x, int y) {
  x += 2000000;
  y += 2000000;
  rec[100000000ll * x + y] ++;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) scanf("%d%d", &x[i], &y[i]);
  for (int i = 1; i <= n; i ++) scanf("%d%d", &a[i], &b[i]);
  for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
      add(x[i] + a[j], y[i] + b[j]);
  for (auto i : rec) {
    if (i.second == n) {
      int x = i.first / 100000000;
      int y = i.first % 100000000;
      printf("%d %d\n", x - 2000000, y - 2000000);
      break;
    }
  }
  return 0;
}