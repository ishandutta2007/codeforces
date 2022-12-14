#include <cstdio>
#include <vector>
#include <algorithm>

int n;
std::vector<std::pair<int, int>> ans;

void quad(int x) {
  static const int a[] = {1, 2, 1, 2, 1, 3};
  static const int b[] = {3, 4, 4, 3, 2, 4};
  for (int i = 0; i < 6; ++i) ans.emplace_back(x + a[i], x + b[i]);
}

void meld(int x, int y) {
  static const int a[] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
  static const int b[] = {2, 1, 4, 3, 4, 3, 2, 1, 3, 4, 1, 2, 1, 2, 3, 4};
  for (int i = 0; i < 16; ++i) ans.emplace_back(x + a[i], y + b[i]);
}

int main() {
  scanf("%d", &n);
  if (n % 4 > 1) return puts("NO"), 0;
  puts("YES");
  int tot = n / 4;
  for (int i = 0; i < tot; ++i) quad(4 * i);
  for (int i = 0; i < tot; ++i)
    for (int j = 0; j < i; ++j)
      meld(4 * j, 4 * i);
  for (auto it : ans) {
    int x = it.first, y = it.second;
    if (n % 4 && x + 1 == y && (x & 1)) printf("%d %d\n%d %d\n%d %d\n", y, n, x, y, x, n); else printf("%d %d\n", x, y);
  }
  return 0;
}