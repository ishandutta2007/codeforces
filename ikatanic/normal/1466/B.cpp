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

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    int ret = 0;
    for (int i = N - 1; i >= 0; --i) {
      if (i == N - 1 || a[i] < a[i + 1] - 1) a[i]++;
      if (i == N - 1 || a[i] != a[i + 1]) ret++;
    }

    cout << ret << '\n';
  }

  return 0;
}