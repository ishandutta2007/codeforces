#include <cstdio>
#include <iostream>
using namespace std;
bool check(int a, int b) { return a % b == 0 && a / b > 0; }
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (check(2 * b - c, a)) {
      puts("YES");
      continue;
    }
    if (check(a + c, 2 * b)) {
      puts("YES");
      continue;
    }
    if (check(2 * b - a, c)) {
      puts("YES");
      continue;
    }
    puts("NO");
  }
  return 0;
}