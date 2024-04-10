#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

bool solve(const vector<int>& a, vector<pair<int, int>>& ret) {
  int n = a.size();
  vector<int> p[4];
  for (int i = 0; i < n; ++i) {
    p[a[i]].push_back(i);
  }

  int currRow = 0;
  if (p[3].size()) {
    for (int i = 0; i + 1 < (int)p[3].size(); ++i) {
      ret.emplace_back(currRow, p[3][i]);
      ret.emplace_back(currRow, p[3][i + 1]);
      currRow++;
    }

    int last3 = p[3].back();
    auto it2 = std::lower_bound(p[2].begin(), p[2].end(), last3);
    if (it2 != p[2].end()) {
      ret.emplace_back(currRow, last3);
      ret.emplace_back(currRow, *it2);
      currRow++;
    } else {
      auto it = std::lower_bound(p[1].begin(), p[1].end(), last3);
      if (it == p[1].end()) return false;
      ret.emplace_back(currRow, last3);
      ret.emplace_back(currRow, *it);
      ret.emplace_back(currRow + 1, *it);
      currRow += 2;
      p[1].erase(it);
    }
  }

  auto do1 = [&](int c) {
    ret.emplace_back(currRow, c);
    currRow++;
  };

  auto it = p[1].begin();
  for (int p2 : p[2]) {
    while (it != p[1].end() && *it < p2) do1(*it++);
    if (it == p[1].end()) return false;

    ret.emplace_back(currRow, p2);
    ret.emplace_back(currRow, *it++);
    currRow++;
  }
  while (it != p[1].end()) do1(*it++);

  assert(currRow <= n);
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<pair<int, int>> ret;
  bool ok = solve(a, ret);
  if (ok) {
    cout << ret.size() << '\n';
    for (auto& p : ret) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
  } else {
    cout << "-1\n";
  }

  return 0;
}