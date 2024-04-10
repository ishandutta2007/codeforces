#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  scanf("%d", &n);
  int m = n / 2 + 1;
  printf("%d\n", m);
  for (int i = 1; i <= m; i++) {
    printf("%d %d\n", 1, i);
  }
  for (int i = 1; i <= n - m; i++) {
    printf("%d %d\n", i + 1, m);
  }
  return 0;
}