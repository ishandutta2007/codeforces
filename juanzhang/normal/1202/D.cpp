#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  int x = 2;
  while (1) {
    if (x * (x - 1) / 2 > n) {
      x--; break;
    }
    x++;
  }
  int t = n - x * (x - 1) / 2;
  printf("133"), x -= 2;
  while (t--) putchar('7');
  while (x--) putchar('3');
  puts("7");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}