#include <cstdio>
#include <cstring>

const int N = 100000 + 10;

inline void check(int &lhs, int rhs) { if (rhs > lhs) lhs = rhs; }

int n;
char s[N];

int f[N][2][3];

int main() {
  scanf("%d %s", &n, s + 1);
  for (int i = 1; i <= n; ++i) s[i] -= '0';
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int a = 0; a < 2; ++a) {
      for (int b = 0; b < 3; ++b) {
        int cur = f[i][a][b];
        //        check(f[i + 1][a][b], cur);
        int t = s[i] ^ (b == 1);
        if (t == a) {
          for (int c = b; c < 3 && c <= b + 1; ++c) check(f[i + 1][a ^ 1][c], cur + 1);
        }
        for (int c = b; c < 3 && c <= b + 1; ++c) check(f[i + 1][a][c], cur);
      }
    }
  }
  for (int a = 0; a < 2; ++a)
    for (int b = 0; b < 3; ++b)
      check(ans, f[n + 1][a][b]);
  printf("%d\n", ans);
  return 0;
}