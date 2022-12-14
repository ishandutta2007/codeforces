#include <cstdio>
#include <cstdlib>

const int N = 20000;

void fail() {
  puts("NO");
  exit(0);
}

int main() {
  int n, x = 0, y = 0;
  scanf("%d", &n);
  while (n--) {
    int t;
    static char dir[10];
    scanf("%d %s", &t, dir);
    if (dir[0] == 'W' || dir[0] == 'E') {
      if (x == 0 || x == N) fail();
      y = (y + (dir[0] == 'W' ? -1 : 1) * t) % (2 * N);
      y = (y + 2 * N) % (2 * N);
    } else {
      x += (dir[0] == 'N' ? -1 : 1) * t;
      if (x < 0 || x > N) fail();
      if (x == 0 || x == N) y = 0;
    }
  }
  puts(x == 0 ? "YES" : "NO");
  return 0;
}