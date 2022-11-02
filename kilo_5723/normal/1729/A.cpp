#include <cstdio>
#include <iostream>

using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int flg1 = a - 1, flg2 = abs(c - b) + c - 1;
    if (flg1 < flg2)
      puts("1");
    else if (flg1 > flg2)
      puts("2");
    else
      puts("3");
  }
  return 0;
}