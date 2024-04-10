#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cout << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

constexpr int MAX = 82;
constexpr int inf = 2e9;

bitset<MAX> b;
vector<vector<int>> E;
vector<vector<vector<pair<int, int>>>> v;
int n, k;

int rec(int r, vector<int>& w) {
  if (r == 0) {
    for (int x : w) b.set(x);
    int ret = 0;
    bool ok = true;
    for (int i = 0; i < (int)w.size(); ++i) {
      int x = w[i], y = w[(i + 1) % w.size()];
      auto j = 0u;
      while (j < v[x][y].size() && b.test(v[x][y][j].second)) j++;
      if (j == v[x][y].size()) {
        ok = false;
        break;
      }
      assert(j < v[x][y].size());
      ret += v[x][y][j].first;
    }
    for (int x : w) b.reset(x);
    return ok ? ret : inf;
  }

  int ret = inf;
  for (int y = 0; y < n; ++y) {
    w.push_back(y);
    ret = min(ret, rec(r - 1, w));
    w.pop_back();
  }
  return ret;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;

  E.resize(n);
  for (int i = 0; i < n; ++i) {
    E[i].resize(n);
    for (int j = 0; j < n; ++j) {
      cin >> E[i][j];
    }
  }

  v.resize(n);
  for (int i = 0; i < n; ++i) {
    v[i].resize(n);
    for (int j = 0; j < n; ++j) {
      for (int k = 1; k < n; ++k) {
        if (i != k && j != k) {
          v[i][j].emplace_back(E[i][k] + E[k][j], k);
        }
      }
      sort(v[i][j].begin(), v[i][j].end());
    }
  }

  vector<int> v{0};
  int ret = rec(k / 2 - 1, v);

  cout << ret << "\n";
  return 0;
}