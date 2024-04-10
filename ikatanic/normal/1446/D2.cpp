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

const int B = 600;

int main() {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> a(N);
  vector<int> f(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    --a[i];
    f[a[i]]++;
  }

  vector<int> c(N);
  auto g = [&](int m) {
    int l = 0;
    int mcnt = 0;
    int ret = 0;
    for (int r = 1; r <= N; ++r) {
      int x = a[r - 1];
      c[x]++;

      if (c[x] == m) {
        mcnt++;
      } else if (c[x] > m) {
        while (c[x] > m) {
          int y = a[l];
          if (c[y] == m) mcnt--;
          c[y]--;
          l++;
        }
        assert(c[x] == m);
      }

      if (mcnt >= 2) ret = max(ret, r - l);
    }
    while (l < N) c[a[l++]]--;

    return ret;
  };

  int ret = 0;
  for (int m = 1; m <= N && m < B; ++m) {
    ret = max(ret, g(m));
  }

  vector<int> v;
  for (int i = 0; i < N; ++i) {
    if (f[i] >= B) v.push_back(i);
  }

  vector<vector<int>> w(N);
  for (int i = 0; i < N; ++i) {
    w[a[i]].push_back(i);
  }

  int M = v.size();
  vector<vector<int>> q(N);
  vector<int> qr(N);
  int bs = -1;
  for (int i = 0; i < N; ++i) {
    c[a[i]]++;
    if (bs == -1 || c[a[i]] > c[bs]) bs = a[i];
    q[bs].push_back(i);
    qr[i] = N;
  }

  vector<int> ps(N + 1);

  for (int i = 0; i < M; ++i) {
    int x = v[i];
    if (q[x].size() == 0) continue;

    ps[0] = 0;
    for (int j = 0; j < N; ++j) {
      ps[j + 1] = ps[j] + (a[j] == x);
    }

    vector<vector<int>> qq(ps[N] + 1);
    for (int j = 0; j < M; ++j) {
      if (i == j) continue;
      int y = v[j];

      int px = 0, py = 0, sum = 0, ms = 0;
      for (int r : q[x]) {
        while (px < w[x].size() && w[x][px] <= r) {
          sum++;
          px++;
        }
        while (py < w[y].size() && w[y][py] <= r) {
          sum--;
          py++;
        }
        qq[sum].push_back(r);
        ms = max(ms, sum);
      }
      for (int r : qq[0]) {
        qr[r] = min(qr[r], 0);
      }

      px = 0, py = 0, sum = 0;
      int l = 0;
      while (px < w[x].size() && py < w[y].size()) {
        if (w[x][px] < w[y][py]) {
          l = w[x][px++] + 1;
          sum++;
        } else {
          l = w[y][py++] + 1;
          sum--;
        }

        if (sum > 0 && qq[sum].size()) {
          for (int r : qq[sum]) {
            if (l <= r) {
              qr[r] = min(qr[r], l);
            }
          }
        }
      }
      for (int k = 0; k <= ms; ++k) qq[k].clear();
    }

    for (int r : q[x]) {
      if (qr[r] < r) {
        int s = ps[r + 1] - ps[qr[r]];
        if (s >= B) ret = max(ret, r + 1 - qr[r]);
      }
    }
  }

  cout << ret << '\n';
  return 0;
}