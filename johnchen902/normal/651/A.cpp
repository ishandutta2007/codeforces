#include <cstdio>
using namespace std;
int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  int time = 0;
  while((x >= 2 || y >= 2) && x > 0 && y > 0)
    (x <= 2) ? (x++, y -= 2) : (y++, x -= 2), time++;
  printf("%d\n", time);
}