#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

const int maxn = 2e5 + 10;
int n;
char a[maxn];

int main() {
  scanf("%d %s", &n, a + 1);
  int m = n / 2;
  int c1 = 0, c2 = 0;
  int s1 = 0, s2 = 0;
  rep(i, 1, m) c1 += a[i] == '?', s1 += a[i] == '?' ? 0 : a[i] - 48;
  rep(i, m + 1, n) c2 += a[i] == '?', s2 += a[i] == '?' ? 0 : a[i] - 48;
  if (abs(c1 - c2) & 1) {
    return puts("Monocarp"), 0;
  }
  if (c1 < c2) {
    puts((c2 - c1) / 2 * 9 != s1 - s2 ? "Monocarp" : "Bicarp");
  } else {
    puts((c1 - c2) / 2 * 9 != s2 - s1 ? "Monocarp" : "Bicarp");
  }
  return 0;
}