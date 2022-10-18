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

const int B = 6;
const i64 inf = 1e16;

int main() {
  ios_base::sync_with_stdio(false);

  int k;
  cin >> k;

  vector<i64> F(B);
  for (int i = 0; i < B; ++i) cin >> F[i];

  auto cs = [&](int i, int x) -> i64 {
    i64 c9 = x / 9;
    i64 score = c9 * F[i] * 3;
    int y = x % 9;
    if (c9 == k) return score;
    if (c9 == k - 1) {
      if (y == 3) score += F[i];
      if (y == 6) score += 2 * F[i];
      return score;
    }

    assert(c9 < k - 1);
    if (y >= 6)
      score += 2 * F[i];
    else if (y >= 3)
      score += F[i];
    return score;
  };

  vector<i64> f[B + 1];
  f[B] = vector<i64>(1, 0);
  int R = 1;
  for (int i = B - 1; i >= 0; --i) {
    R *= 10;
    vector<i64>& g = f[i];
    g = vector<i64>(R, -inf);

    multiset<i64> S[3];
    vector<i64> h(R);
    int y1 = 0, y2 = 0;
    for (int x = 0; x < R; ++x) {
      while (y2 <= x) {
        h[y2] = f[i + 1][y2 / 10] - (y2 / 3) * F[i];
        S[y2 % 3].insert(h[y2]);
        y2 += 10;
      }

      while (y1 < y2 && y1 + 9 * (k - 1) <= x) {
        S[y1 % 3].erase(S[y1 % 3].find(h[y1]));
        y1 += 10;
      }

      int c = x % 3;

      if (S[c].size()) {
        i64 qq = (x / 3) * F[i];
        qq += *(--S[c].end());
        g[x] = max(g[x], qq);
      }
    }

    for (int x = R - 1; x >= 0; --x) {
      for (int y = 1; x - y >= 0 && y < 3; ++y) {
        g[x] = max(g[x], g[x - y]);
      }
    }

    for (int l = 9 * (k - 1); l <= 9 * k; ++l) {
      for (int j = 0; j * 10 + l < R; ++j) {
        g[l + 10 * j] = max(g[l + 10 * j], f[i + 1][j] + cs(i, l));
      }
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;

    cout << f[0][x] << '\n';
  }
  return 0;
}