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

  int n, k;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  auto calcScore = [](i64 x, i64 k) -> i64 {
    if (k > x) return 1e18;
    i64 a = x / k;
    i64 ce = x % k;

    return a * a * (k - ce) + (a + 1) * (a + 1) * ce;
  };

  vector<i64> c(n, 1);
  vector<i64> score(n);
  i64 ret = 0;
  set<pair<i64, int>> S;
  for (int i = 0; i < n; ++i) {
    ret += calcScore(a[i], c[i]);
    score[i] = calcScore(a[i], c[i] + 1) - calcScore(a[i], c[i]);
    S.emplace(score[i], i);
  }

  for (int it = 0; it < k - n; ++it) {
    int i = S.begin()->second;
    S.erase(S.begin());

    ret += score[i];
    c[i]++;
    score[i] = calcScore(a[i], c[i] + 1) - calcScore(a[i], c[i]);
    S.emplace(score[i], i);
  }

  cout << ret << '\n';
  return 0;
}