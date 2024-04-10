#include <stdio.h>
#include <numeric>
#include <algorithm>

static_assert((1 << 17) < 200'000);
static_assert((1 << 18) > 200'000);

int a[200'000];
int table[18][200'000];

int query(int i, int k, int n) {
  int m = 0;
  while ((2 << m) < k)
    m++;
  return std::gcd(table[m][i], table[m][(i + k - (1 << m)) % n]);
}

void normalize(int n) {
  int x = a[0];
  for (int i = 1; i < n; i++)
    x = std::gcd(x, a[i]);
  for (int i = 0; i < n; i++)
    a[i] /= x;
}

int solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a + i);
  normalize(n);

  std::copy_n(a, n, table[0]);
  for (int j = 1; j < 18; j++)
    for (int i = 0; i < n; i++)
      table[j][i] = std::gcd(table[j - 1][i],
                             table[j - 1][(i + (1 << (j - 1))) % n]);

  int ans = 0;
  for (int i = 0, j = 1; i < n; i++, j--) {
    while (j < 1 || query(i, j, n) != 1)
      j++;
    ans = std::max(ans, j - 1);
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", solve());
  }
}