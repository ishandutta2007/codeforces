#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cout << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int r, n;
  cin >> r >> n;
  n++;

  vector<int> t(n), x(n), y(n);
  t[0] = 0;
  x[0] = y[0] = 1;
  for (int i = 1; i < n; ++i) {
    cin >> t[i] >> x[i] >> y[i];
  }

  vector<int> f(n);
  int sureBestPtr = n;
  int sureBest = 0;

  for (int i = n - 1; i >= 0; --i) {
    while (sureBestPtr > 0 && t[sureBestPtr - 1] - t[i] > 2 * r) {
      sureBest = max(sureBest, f[--sureBestPtr]);
    }
    f[i] = sureBest;

    for (int j = i + 1; j < sureBestPtr; ++j) {
      if (abs(x[j] - x[i]) + abs(y[j] - y[i]) <= t[j] - t[i]) {
        f[i] = max(f[i], f[j]);
      }
    }
    f[i]++;
  }

  cout << f[0] - 1 << '\n';
  return 0;
}