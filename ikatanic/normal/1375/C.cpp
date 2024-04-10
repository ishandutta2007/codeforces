#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
#include <set>

#define TRACE(x) std::cout << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;


bool f(vector<int> a) {
  int n = a.size();
  set<pair<int, int>> indexed;
  set<pair<int, int>> nums;
  for (int i = 0; i < n; ++i) {
    indexed.emplace(i, a[i]);
    nums.emplace(a[i], i);
  }

  while (nums.size() > 1) {
    auto [v0, x] = *nums.begin();
    auto [v1, y] = *(--nums.end());

    int l = indexed.begin()->second;
    int r = (--indexed.end())->second;
    if (l == v0 || r == v1) return true;
    if (l == v1 || r == v0) return false;

    if (x > y) swap(x, y);
    while (true) {
      auto it = indexed.lower_bound({x, -1});
      if (it == indexed.end() || it->first > y) break;
      nums.erase({it->second, it->first});
      indexed.erase(it);
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << (f(a) ? "YES" : "NO") << "\n";
  }
  return 0;
}