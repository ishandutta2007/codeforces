#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n, pos, l, r, ans = 1e9, tmp, cur;

int main() {
  scanf("%d%d%d%d", &n, &pos, &l, &r);
  tmp = 0;
  cur = pos;
  if (l > 1) {
    cur = l;
    tmp += abs(pos - l) + 1;
  }
  if (r < n) tmp += abs(r - cur) + 1;
  ans = min(ans, tmp);
  
  tmp = 0;
  cur = pos;
  if (r < n) {
    cur = r;
    tmp += abs(pos - r) + 1;
  }
  if (l > 1) tmp += abs(l - cur) + 1;
  ans = min(ans, tmp);
  printf("%d\n", ans);
  return 0;
}