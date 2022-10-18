#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;
using i64 = int64_t;

template <typename It>
int solve(It first, It last, int B) {
  if (first == last || B < 0) return 0;

  auto m =
      std::partition(first, last, [B](int x) { return (x & (1 << B)) > 0; });

  int sa = m - first;
  int sb = last - m;

  int fa = solve(first, m, B - 1);
  int fb = solve(m, last, B - 1);

  if (sa == 0) return fb;
  if (sb == 0) return fa;

  return min(fa + sb - 1, fb + sa - 1);
}

int main() {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }

  int ret = solve(a.begin(), a.end(), 30);
  cout << ret << '\n';
  return 0;
}