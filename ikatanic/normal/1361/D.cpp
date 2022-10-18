#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

#define TRACE(x) std::cout << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

using i64 = int64_t;

double solve(map<pair<i64, i64>, vector<double>>& M, int K) {
  int N = 0;
  for (auto& p : M) {
    sort(p.second.begin(), p.second.end(), greater<double>());
    N += p.second.size();
  }

  for (auto& p : M) {
    int maxNeed = K - (N - (int)p.second.size());
    if (maxNeed * 2 > K + 1) {
      double ret = 0;
      for (auto& r : M) {
        if (r.first != p.first) {
          for (int i = 0; i < (int)r.second.size(); ++i) {
            ret += (K - 1 - 2 * i) * r.second[i];
          }
        }
      }

      int L = (K + 1) / 2;
      int R = maxNeed - L;
      assert(R >= 0);
      assert(L + R <= (int)p.second.size());
      for (int i = 0; i < L; ++i) {
        ret += (K - 1 - 2 * i) * p.second[i];
      }
      for (int i = 0; i < R; ++i) {
        ret += (K - 1 - 2 * (i + L)) * p.second[(int)p.second.size() - R + i];
      }
      return ret;
    }
  }

  vector<double> scores;
  for (auto& p : M) {
    for (int i = 0; i < (int)p.second.size(); ++i) {
      scores.push_back((K - 1 - 2 * i) * p.second[i]);
    }
  }
  sort(scores.begin(), scores.end(), greater<double>());
  double ret = accumulate(scores.begin(), scores.begin() + K, 0.0);
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;

  map<pair<i64, i64>, vector<double>> M;
  for (int i = 0; i < N; ++i) {
    i64 x, y;
    cin >> x >> y;
    double d = sqrt(x * x + y * y);
    if (x || y) {
      i64 g = __gcd(abs(x), abs(y));
      x /= g, y /= g;
    }

    M[{x, y}].push_back(d);
  }

  double ans = solve(M, K);
  cout << std::setprecision(15) << ans << "\n";
  return 0;
}