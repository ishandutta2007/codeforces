#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      int x = 1, y = n;
      while (y % i == 0) {
        y /= i;
        x *= i;
      }
      if (x > y) {
        swap(x, y);
      }
      for (int i = 1; i < x; ++i) {
        int remain = n - 1 - i * y;
        if (remain % x == 0) {
          printf("YES\n2\n");
          printf("%d %d\n", i, x);
          printf("%d %d\n", remain / x, y);
          return 0;
        }
      }
    }
  }
  puts("NO");

  return 0;
}