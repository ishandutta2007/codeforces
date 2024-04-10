#include <cstdio>
#include <bitset>

const int N = 500 + 10;

int n, k, c[N];

std::bitset<N> mask[N];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
  mask[0][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = k; j >= c[i]; --j)
      mask[j] |= mask[j - c[i]] | (mask[j - c[i]] << c[i]);
  printf("%d\n", mask[k].count());
  for (int i = 0; i <= k; ++i) if (mask[k][i]) printf("%d ", i);
  return 0;
}