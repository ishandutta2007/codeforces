#include <cstdio>
#include <iostream>
using namespace std;

const int N = 15;

int n;
char a[N][N], b[N][N];

inline bool chk1() {
  for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
      if (a[i][j] != b[i][j]) return 0;
  return 1;
}

inline bool chk2() {
  for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
      if (a[i][j] != b[j][n - i + 1]) return 0;
  return 1;
}

inline bool chk3() {
  for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
      if (a[i][j] != b[n - i + 1][n - j + 1]) return 0;
  return 1;
}

inline bool chk4() {
  for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
      if (a[i][j] != b[n - j + 1][i]) return 0;
  return 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) scanf("%s", a[i] + 1);
  for (int i = 1; i <= n; i ++) scanf("%s", b[i] + 1);
  if (chk1()) return 0 * puts("Yes");
  if (chk2()) return 0 * puts("Yes");
  if (chk3()) return 0 * puts("Yes");
  if (chk4()) return 0 * puts("Yes");
  for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n / 2; j ++)
      swap(a[i][j], a[i][n - j + 1]);
  if (chk1()) return 0 * puts("Yes");
  if (chk2()) return 0 * puts("Yes");
  if (chk3()) return 0 * puts("Yes");
  if (chk4()) return 0 * puts("Yes");
  puts("No");
  return 0;
}