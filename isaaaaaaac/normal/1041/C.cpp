#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int N = 2e5 + 50;

map <int, int> rec;
map <int, int> :: iterator it;

int ans[N], n, m, d;

int main() {
  scanf("%d%d%d", &n, &m, &d);
  for (int i = 1, x; i <= n; i ++) {
    scanf("%d", &x);
    rec[x] = i;
  }
  int cur = rec.begin() -> first;
  ans[rec.begin() -> second] = 1;
  rec.erase(rec.begin());
  int day = 1;
  for (int i = 1; i < n; i ++) {
    cur += d + 1;
    if (cur > m) cur = 0, day ++;
    it = rec.lower_bound(cur);
    if (it == rec.end()) {
      day ++; cur = 0;
      it = rec.lower_bound(cur);
    }
    cur = it -> first;
    ans[it -> second] = day;
    rec.erase(it);
  }
  printf("%d\n", day);
  for (int i = 1; i <= n; i ++) printf("%d ", ans[i]);
  puts("");
  return 0;
}