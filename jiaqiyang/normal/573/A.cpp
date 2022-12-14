#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int n, a[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    while (a[i] % 2 == 0) a[i] /= 2;
    while (a[i] % 3 == 0) a[i] /= 3;
  }
  std::sort(a + 1, a + n + 1);
  puts(a[1] == a[n] ? "Yes" : "No");
  return 0;
}