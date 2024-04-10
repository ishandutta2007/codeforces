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

const int MAX = 30030;
const int MAXC = 5;

i64 f[MAX][MAXC];
i64 g[MAX][MAXC];
int a[MAX];
int n, c;

void prepare() {
  for (int k = 0; k <= c; ++k) {
    f[n][k] = 1;
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int k = 0; k <= c; ++k) {
      f[i][k] = 0;

      for (int j = i; j < n && j - i <= k; ++j) {
        f[i][k] += f[j + 1][k - (j - i)];
      }
    }
  }

  for (int k = 0; k <= c; ++k) {
    g[n][k] = 0;
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int k = 0; k <= c; ++k) {
      g[i][k] = g[i + 1][k];

      for (int j = i + 1; j < n && j - i <= k; ++j) {
        if (a[j] < a[i]) {
          g[i][k] += f[j + 1][k - (j - i)];
        }
      }
    }
  }
}

int query(int x, i64 w) {
  vector<pair<int, int>> ops;

  int i = 0, k = c;
  if (w >= f[i][k]) return -1;

  vector<pair<int, int>> q;
  q.reserve(8);

  while (i < n) {
    int lo = 0, hi = n - i;
    while (lo < hi) {
      int mid = (lo + hi + 1) / 2;
      auto lt = g[i][k] - g[i + mid][k];
      auto lte = lt + f[i + mid][k];
      if (lt <= w && w < lte) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }

    if (lo > 0) {
      auto lt = g[i][k] - g[i + lo][k];
      auto lte = lt + f[i + lo][k];
      i += lo;
      w -= lt;
      if (i >= n) break;
    }

    q.clear();
    for (int j = i; j < n && j - i <= k; ++j) {
      q.emplace_back(a[j], j);
    }
    sort(q.begin(), q.end());

    assert(f[i][k] > w);
    bool ok = false;
    for (auto& p : q) {
      int j = p.second;
      auto cnt = f[j + 1][k - (j - i)];
      if (w < cnt) {
        if (j > i) {
          ops.emplace_back(i, j);
        }
        k -= (j - i);
        i = j + 1;
        ok = true;
        break;
      }
      w -= cnt;
    }
    assert(ok);
  }

  for (auto& p : ops) {
    int l = p.first;
    int r = p.second;
    if (l <= x && x <= r) {
      int y = l + (r - x);
      return a[y];
    }
  }
  return a[x];
}

void solve() {
  int q;
  cin >> n >> c >> q;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }

  prepare();

  while (q--) {
    int a;
    i64 b;
    cin >> a >> b;
    --a;
    --b;
    auto ans = query(a, b);
    if (ans != -1) ans++;
    cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}