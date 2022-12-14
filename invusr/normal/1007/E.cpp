#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

const s64 INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
  int n, t, limit;
  cin >> n >> t >> limit;
  vector<s64> a(n + 1), b(n + 1), c(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }
  ++n;
  a.push_back(INF);
  b.push_back(0);
  c.push_back(INF);
  vector<s64> sum_a(n + 1), sum_b(n + 1);
  for (int i = 1; i <= n; ++i) {
    sum_a[i] = a[i] + sum_a[i - 1];
    sum_b[i] = b[i] + sum_b[i - 1];
  }

  auto sum = [&](int i, int j, int k) {
    return j * sum_b[i] + k * sum_a[i];
  };

  vector<vector<array<s64, 2>>> f(n + 1, vector<array<s64, 2>>(t + 1));
  vector<vector<array<s64, 2>>> g(n + 1, vector<array<s64, 2>>(t + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= t; ++j) {
      for (int k = 0; k < 2; ++k) {
        f[i][j][k] = INF;
        g[i][j][k] = INF;

        if (j * b[i] + k * a[i] <= c[i] && f[i - 1][j][k] < INF) {
          f[i][j][k] = f[i - 1][j][k];
          s64 value = (sum(i - 1, j, k) - 1) / limit + 1;
          if (value * limit <= sum(i, j, k)) {
            g[i][j][k] = value;
          }
        }

        for (int r = 0; r < j; ++r) {
          s64 last = g[i][r][k];
          if (last < INF) {
            s64 remain = sum(i, r, k) - last * limit;
            s64 current = (max(0ll, remain + (j - r) * b[i] - c[i]) + limit - 1) / limit;
            if (f[i - 1][j - r][0] < INF && current * limit <= remain) {
              f[i][j][k] = min(f[i][j][k], last + current + f[i - 1][j - r][0]);
              s64 value = (sum_b[i - 1] * (j - r) - 1) / limit + 1;
              if (value * limit <= sum_b[i] * (j - r) + remain - current * limit) {
                g[i][j][k] = min(g[i][j][k], last + current + value);
              }
            }
          }
        }
      }
    }
  }

  cout << f[n][t][1] << endl;

  return 0;
}