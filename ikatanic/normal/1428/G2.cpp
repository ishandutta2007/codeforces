#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

using i64 = int64_t;

template <class T, typename U = std::less<T>>
class MonotonicQueue {
  deque<T> mQ;
  queue<T> Q;

 public:
  void push(T x) {
    while (!mQ.empty() && U()(x, mQ.back())) mQ.pop_back();
    mQ.push_back(x);
    Q.push(x);
  }

  void pop() {
    if (Q.front() == mQ.front()) mQ.pop_front();
    Q.pop();
  }

  T getOpt() { return mQ.front(); }

  bool empty() { return Q.empty(); }
};

template <typename T, typename U = std::greater<T>>
vector<T> movingBest(const vector<T>& f, int window) {
  vector<T> g(f.size());
  MonotonicQueue<T, U> MQ;
  for (int i = 0; i < (int)f.size(); ++i) {
    MQ.push(f[i]);
    g[i] = MQ.getOpt();
    if (i - window + 1 >= 0) MQ.pop();
  }
  return g;
}

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

    for (int j = 0; j < R; j += 10) {
      g[j] = f[i + 1][j / 10] - (j / 3) * F[i];
    }
    for (int c = 0; c < 3; ++c) {
      vector<i64> h;
      for (int j = c; j < R; j += 3) h.push_back(g[j]);
      h = movingBest(h, 3 * (k - 1));
      for (int j = c; j < R; j += 3) {
        assert(j / 3 < h.size());
        g[j] = h[j / 3];
      }
    }

    for (int j = 0; j < R; ++j) {
      g[j] += (j / 3) * F[i];
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