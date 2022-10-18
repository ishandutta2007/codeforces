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

const int MAX = 5050;

int f[MAX][MAX];

int main() {
  ios_base::sync_with_stdio(false);

  int N, M;
  string A, B;
  cin >> N >> M;
  cin >> A;
  cin >> B;

  int ret = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      f[i][j] = 0;
      f[i][j] = max(f[i][j], f[i - 1][j] - 1);
      f[i][j] = max(f[i][j], f[i][j - 1] - 1);
      if (A[i - 1] == B[j - 1]) {
        f[i][j] = max(f[i][j], f[i - 1][j - 1] + 2);
      }
      ret = max(ret, f[i][j]);
    }
  }

  cout << ret << '\n';
  return 0;
}