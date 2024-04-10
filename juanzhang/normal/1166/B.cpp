#include <bits/stdc++.h>
using namespace std;

const char ch[] = "aeiou";

void print(int x, int y) {
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      putchar(ch[(i + j) % 5]);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  if (n < 25) {
    return puts("-1"), 0;
  }
  int tmp = sqrt(n);
  for (int i = 5; i <= tmp; i++) {
    if (n % i == 0 && n / i > 4) {
      return print(i, n / i), 0;
    }
  }
  puts("-1");
  return 0;
}