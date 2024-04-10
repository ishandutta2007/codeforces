#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    getchar();
    int sum = 0;
    while (n--) {
      if (getchar() == 'Q')
        sum++;
      else
        sum = max(sum - 1, 0);
    }
    puts(sum <= 0 ? "YES" : "NO");
  }
  return 0;
}