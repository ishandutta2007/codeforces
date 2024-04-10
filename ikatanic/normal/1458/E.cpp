#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;
using i64 = int64_t;

map<int, vector<int>> M;
map<int, int> G;

int main() {
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    if (x || y) M[x].push_back(y);
  }
  M[0].push_back(0);

  vector<int> qx(m), qy(m);
  for (int i = 0; i < m; ++i) {
    cin >> qx[i] >> qy[i];
    if (!M.count(qx[i])) {
      M[qx[i]] = {};
    }
  }

  int px = 0, py = 0;
  set<int> S;
  for (auto& p : M) {
    int x = p.first;
    vector<int>& v = p.second;
    sort(v.begin(), v.end());

    while (px < x) {
      while (S.size() && *S.begin() < py) S.erase(S.begin());
      while (S.count(py)) {
        S.erase(S.begin());
        py++;
      }

      int d = x - px;
      if (S.size()) d = min(d, *S.begin() - py);

      assert(d >= 1);
      px += d, py += d;
    }

    while (S.size() && *S.begin() < py) S.erase(S.begin());
    while (S.count(py)) {
      S.erase(S.begin());
      py++;
    }

    if (v.size() && v[0] < py) {
      G[x] = v[0];
    } else {
      G[x] = py++;
    }

    for (int y : v) S.insert(y);
    px++;
  }

  for (int i = 0; i < m; ++i) {
    const auto& v = M[qx[i]];
    bool win = false;

    if (binary_search(v.begin(), v.end(), qy[i])) {
      win = false;
    } else {
      win = qy[i] != G[qx[i]];
    }

    cout << (win ? "WIN" : "LOSE") << "\n";
  }

  return 0;
}