#include <bits/stdc++.h>
using namespace std;

int cache[100005];
int n;

int query(int x) {
  if (x == 0 || x == n+1) {
    return numeric_limits<int>::max();
  } else if (!cache[x]) {
    printf("? %d\n", x);
    fflush(stdout);
    scanf("%d", cache+x);
  }
  return cache[x];
}

int main() {
  scanf("%d", &n);
  int lo = 0, hi = n+2;
  while (lo+1 < hi) {
    int mid = (lo+hi) / 2;
    int x = query(mid-1), y = query(mid);
    int a = query(lo), b = query(hi-1);
    if (a == min({a, b, x, y}) || x == min({a, b, x, y})) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  printf("! %d\n", lo);
  return 0;
}