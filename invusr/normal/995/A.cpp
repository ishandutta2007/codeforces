#include <bits/stdc++.h>
using namespace std;

const int MaxN = 50;
const int MaxM = MaxN * 2;

int n, m;
int a[4][MaxN + 1];

struct info {
  int k, x, y;
  info() {}
  info(const int &_k, const int &_x, const int &_y)
    : k(_k), x(_x), y(_y) {}
};
vector<info> oper;

inline pair<int, int> next_grid(int x, int y) {
  if (x == 1) {
    y == n ? ++x : ++y;
  } else {
    y == 1 ? --x : --y;
  }
  return pair(x, y);
}

bool walked[MaxM + 1];

inline bool solve() {
  int remain = m;
  while (true) {
    for (int i = 1; i <= 2; ++i) {
      for (int j = 1; j <= n; ++j) {
        int k = a[i][j];
        if (k && a[i ^ 1][j] == k) {
          oper.emplace_back(k, i ^ 1, j);
          a[i][j] = 0, --remain;
        }
      }
    }
    if (!remain) {
      return true;
    }

    fill(walked + 1, walked + m + 1, false);

    bool valid = false;
    for (int i = 1; i <= n; ++i) {
      auto [x, y] = next_grid(2, i);
      int k = a[2][i];
      if (k && !walked[k] && !a[x][y]) {
        oper.emplace_back(k, x, y);
        a[2][i] = 0;
        a[x][y] = k;
        valid = walked[k] = true;
      }
    }
    for (int i = n; i >= 1; --i) {
      auto [x, y] = next_grid(1, i);
      int k = a[1][i];
      if (k && !walked[k] && !a[x][y]) {
        oper.emplace_back(k, x, y);
        a[1][i] = 0;
        a[x][y] = k;
        valid = walked[k] = true;
      }
    }

    if (!valid) {
      return false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < 4; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }

  if (!solve()) {
    cout << -1 << endl;
  } else {
    cout << oper.size() << endl;
    for (auto [k, x, y] : oper) {
      cout << k << ' ' << x + 1 << ' ' << y;
      cout << endl;
    }
  }

  return 0;
}