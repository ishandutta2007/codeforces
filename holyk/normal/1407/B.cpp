#include <cstdio>

int a[1003];
bool v[1003];
inline int gcd(int x, int y) { return x ? gcd(y % x, x) : y; }
int main() {
  int t; scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]), v[i] = false;
    int now = 0;
    for (int i = 1; i <= n; i++) {
      int max = 0, id = 0;
      for (int j = 1; j <= n; j++)
        if (!v[j]) {
          int c = gcd(now, a[j]);
          if (c > max) max = c, id = j;
        }
      v[id] = 1, now = max;
      printf("%d ", a[id]);
    }

    puts("");
  }
  return 0;
}