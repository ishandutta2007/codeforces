#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

const int maxn = 1e5 + 10;
int n;

int main() {
  int a1, a2, k1, k2, n;
  scanf("%d %d %d %d %d", &a1, &a2, &k1, &k2, &n);
  int s1;
  int s2;
  if (k1 > k2) swap(a1, a2), swap(k1, k2);
  int t = n - (k1 - 1) * a1 - (k2 - 1) * a2;
  s1 = max(0, t);
  s2 = min(n / k1, a1) + (n <= a1 * k1 ? 0 : (n - a1 * k1) / k2);
  printf("%d %d", s1, s2);
  return 0;
}