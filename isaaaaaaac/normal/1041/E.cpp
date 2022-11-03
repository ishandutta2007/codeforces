#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1050;

int n, a[N], vis[N];
vector <pair <int, int> > ans;

int main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i < n; i ++) {
    scanf("%d%d", &x, &y);
    if (x == n) a[i] = y;
    else a[i] = x;
    if (x == n && y == n) return 0 * puts("NO");
    if (x != n && y != n) return 0 * puts("NO");
  }
  sort(a + 1, a + n);
  int lst = 0;
  for (int i = 1, j = 1; i < n; i = j) {
    while (a[j] == a[i]) j ++;
    vis[a[i]] = 1;
    if (lst) ans.emplace_back(a[i], lst);
    int len = j - i - 1;
    lst = a[i];
    for (int k = 1; k < a[i] && len; k ++)
      if (!vis[k]) {
        len --; vis[k] = 1;
        ans.emplace_back(lst, k);
        lst = k;
      }
    if (len) return 0 * puts("NO");
  }
  ans.emplace_back(lst, n);
  if (ans.size() != n - 1) return 0 * puts("NO");
  puts("YES");
  for (auto i : ans) printf("%d %d\n", i.first, i.second);
  return 0;
}