#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    printf("1");
    for (int i = n; i > 1; i--) printf(" %d", i);
    puts("");
  }
  return 0;
}