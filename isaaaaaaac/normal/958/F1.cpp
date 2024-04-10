#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 105;

int n, m;
int a[N], k[N], b[N];

inline bool chk() {
  for (int i = 1; i <= m; i ++)
    if (b[i] != k[i]) return 0;
  return 1;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i ++) scanf("%d", &k[i]);
  for (int i = 1; i <= n; i ++) {
    memset(b, 0, sizeof b);
    for (int j = i; j <= n; j ++) {
      b[a[j]] ++;
      if (chk()) return 0 * puts("YES");
    }
  }
  puts("NO");
  return 0;
}