#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= i; j++)
        if (j == i)
          puts("1");
        else if (!j)
          printf("1 ");
        else
          printf("0 ");
  }
  return 0;
}