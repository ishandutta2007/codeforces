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

int f[101][10100];

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n * 100; ++j) {
      f[i][j] = -1000000000;
    }
  }
  f[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    b *= 2;

    for (int k = i; k >= 0; --k) {
      for (int c = 0; c <= i * 100; ++c) {
        f[k + 1][c + a] = max(f[k + 1][c + a], f[k][c] + b);
        f[k][c] += b / 2;
      }
    }
  }

  for (int k = 1; k <= n; ++k) {
    int best = 0;
    for (int c = 0; c <= n * 100; ++c) {
      best = max(best, min(f[k][c], c * 2));
    }
    cout << best / 2.0 << ' ';
  }
  cout << '\n';
  return 0;
}