#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, pos_1, a[maxn], b[maxn];

int pre_check() {
  int pos = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i] == 1) pos = i;
  }
  if (!pos) return 0;
  pos_1 = pos;
  for (int i = pos; i <= n; i++) {
    if (b[i] != i - pos + 1) {
      return 0;
    }
  }
  int v = n - pos + 1;
  for (int i = 1; i < pos; i++) {
    if (b[i] && b[i] - v <= i) {
      return 0;
    }
  }
  return pos - 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  bool flg = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", b + i);
    flg &= b[i] == i;
  }
  if (flg) {
    return puts("0"), 0;
  }
  int pre_ans = pre_check();
  if (pre_ans) {
    return printf("%d", pre_ans), 0;
  }
  int res = 0;
  for (int i = pos_1 + 1; i <= n; i++) {
    if (b[i]) res = max(res, i - pos_1 - b[i] + 1);
  }
  int ans = res + pos_1 + n;
  res = 0;
  while (pos_1 < n && b[pos_1 + 1] == 0) pos_1++;
  for (int i = pos_1 + 1; i <= n; i++) {
    if (b[i]) res = max(res, i - pos_1 - b[i] + 1);
  }
  ans = min(ans, res + pos_1 + n);
  printf("%d", ans);
  return 0;
}