#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <set>
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
    set<int> S;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        S.insert(a[j] - a[i]);
      }
    }

    cout << S.size() << '\n';
  }

  return 0;
}