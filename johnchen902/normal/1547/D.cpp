#include <stdio.h>

void solve() {
  int n;
  scanf("%d", &n);

  int z = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);

    // x z y
    // 0 0 0
    // 0 1 1
    // 1 0 0
    // 1 1 0

    // int y = 0;
    // while (((x ^ y) & z) != z)
    //   y++;
    int y = ~x & z;

    printf("%d%c", y, i == n - 1 ? '\n' : ' ');
    z = x ^ y;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}