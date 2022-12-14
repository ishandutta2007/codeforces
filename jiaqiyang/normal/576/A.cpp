#include <cstdio>
#include <vector>

const int N = 1000 + 10;

int n;

int main() {
  scanf("%d", &n);
  std::vector<int> ans;
  static bool flag[N];
  for (int i = 2; i <= n; ++i) {
    if (flag[i]) continue;
    for (int j = i; j <= n; j += i) flag[j] = true;
    for (int j = i; j <= n; j *= i) ans.push_back(j);
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
  return 0;
}