#include <cstdio>
#include <tuple>
#include <vector>

const int N = 300 + 10;

int n, z;

std::vector<std::tuple<int, int, int>> a;
std::vector<std::tuple<int, int, int, int>> b;

int main() {
  scanf("%d", &n);
  if (n & 1) {
    int x = n--;
    z = n / 2;
    for (int i = 1; i <= z; ++i) {
      a.emplace_back(x, i, i + z);
      a.emplace_back(x, i, i + z);
    }
  } else {
    int x = n--;
    int y = n--;
    z = n / 2;
    a.emplace_back(x, y, 1);
    a.emplace_back(y, 1, 1 + z);
    a.emplace_back(1, 1 + z, x);
    a.emplace_back(1 + z, x, y);
    for (int i = 2; i <= z; ++i) {
      a.emplace_back(x, i, i + z);
      a.emplace_back(y, i, i + z);
      b.emplace_back(x, i + z, y, i);
    }
  }
  for (int i = 1; i <= z; ++i) {
    for (int j = 1; j < i; ++j) {
      b.emplace_back(i, j, i + z, j + z);
      b.emplace_back(i, j, i + z, j + z);
    }
  }
  printf("%d\n", a.size() + b.size());
  for (auto it : a) printf("3 %d %d %d\n", std::get<0>(it), std::get<1>(it), std::get<2>(it));
  for (auto it : b) printf("4 %d %d %d %d\n", std::get<0>(it), std::get<1>(it), std::get<2>(it), std::get<3>(it));
  return 0;
}