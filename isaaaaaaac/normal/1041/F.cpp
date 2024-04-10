#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N = 1e5 + 50;

int ans = 0;
int n, m, a[N], b[N];

inline void check(int xx) {
  unordered_map <int, int> x, y;
  xx <<= 1;
  for (int i = 1; i <= n; i ++) x[a[i] % xx] ++;
  for (int i = 1; i <= m; i ++) y[b[i] % xx] ++;
  for (auto i : x)
    ans = max(ans, i.second + y[(i.first + (xx >> 1)) % xx]);
  for (auto i : y)
    ans = max(ans, i.second + x[(i.first + (xx >> 1)) % xx]);
}
 
int main() {
  scanf("%d%*d", &n);
  unordered_map <int, int> x, y;
  for (int i = 1; i <= n; i ++) {
    scanf("%d", a + i);
    x[a[i]] ++;
  }
  scanf("%d%*d", &m);
  for (int i = 1; i <= m; i ++) {
    scanf("%d", b + i); y[b[i]] ++;
  }
  for (auto i : x) ans = max(ans, i.second + y[i.first]);
  for (auto i : y) ans = max(ans, i.second + x[i.first]);
  for (int i = 0; i < 30; i ++) check(1 << i);
  printf("%d\n", ans);
  return 0;
}