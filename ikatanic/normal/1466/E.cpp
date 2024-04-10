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

const int B = 61;
const int mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<i64> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];

    vector<int> cnt(B);
    for (auto x : A) {
      for (int i = 0; i < B; ++i) {
        if ((x >> i) & 1) cnt[i]++;
      }
    }

    i64 ret = 0;
    for (auto x : A) {
      i64 sa = 0, so = 0;
      for (int i = 0; i < B; ++i) {
        i64 p2 = (1LL << i) % mod;
        if ((x >> i) & 1) {
          sa = (sa + p2 * cnt[i]) % mod;
          so = (so + p2 * n) % mod;
        } else {
          so = (so + p2 * cnt[i]) % mod;
        }
      }

      ret = (ret + sa * so) % mod;
    }

    cout << ret << '\n';
  }

  return 0;
}