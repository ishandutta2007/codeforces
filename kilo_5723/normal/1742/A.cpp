#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a + b == c || b + c == a || c + a == b)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}