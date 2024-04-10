#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <functional>

int a[100000];
int b[100000];

int sa[100001];
int sb[100001];

bool check(int x, int n) {
  int y = x - x / 4;
  int scorea = std::min(y, x - n) * 100 + sa[y - std::min(y, x - n)];
  int scoreb = sb[std::min(y, n)];
  // printf("check(%d, %d) = %d >= %d\n", x, n, scorea, scoreb);
  return scorea >= scoreb;
}

int solve(int n) {
  std::sort(a, a + n, std::greater<int>());
  std::sort(b, b + n, std::greater<int>());

  for (int i = 0; i < n; i++) {
    sa[i + 1] = sa[i] + a[i];
    sb[i + 1] = sb[i] + b[i];
  }

  int l = 0, r = n * 10;
  while (l != r) {
    int m = (l + r) / 2;
    if (check(n + m, n))
      r = m;
    else
      l = m + 1;
  }
  return l;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", a + i);
    for (int i = 0; i < n; i++)
      scanf("%d", b + i);
    printf("%d\n", solve(n));
  }
}