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

i64 gcd(i64 a, i64 b) { return !b ? a : gcd(b, a % b); }

int main() {
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector<i64> A(n);
  for (int i = 0; i < n; ++i) cin >> A[i];
  sort(A.begin(), A.end());

  i64 g = 0;
  for (int i = 1; i < n; ++i) {
    g = gcd(g, A[i] - A[0]);
  }

  for (int i = 0; i < m; ++i) {
    i64 B;
    cin >> B;

    i64 ans = gcd(g, A[0] + B);
    cout << ans << ' ';
  }
  cout << '\n';
  return 0;
}