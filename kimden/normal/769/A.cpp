#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for (int& a : v) {
    std::cin >> a;
  }
  std::sort(v.begin(), v.end());
  std::cout << v[n / 2];
  return 0;
}