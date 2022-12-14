#include <cstdio>

int n, m;

bool check(int x) {
  int n2 = x / 2, n3 = x / 3, n6 = x / 6;
  return n2 >= n && n3 >= m && n2 + n3 - n6 >= n + m;
}

int main() {
  scanf("%d%d", &n, &m);
  int l = 0, r = 1000000000;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid; else l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}