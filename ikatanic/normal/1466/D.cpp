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

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a, --b;
      e[a].push_back(b);
      e[b].push_back(a);
    }

    i64 ret0 = 0;
    vector<i64> diffs;
    for (int i = 0; i < n; ++i) {
      ret0 += e[i].size() * a[i];
      for (int j = 0; j + 1 < (int)e[i].size(); ++j) {
        diffs.push_back(a[i]);
      }
    }

    sort(diffs.begin(), diffs.end());
    vector<i64> ans;
    ans.push_back(ret0);
    for (auto d : diffs) {
      ret0 -= d;
      ans.push_back(ret0);
    }

    reverse(ans.begin(), ans.end());

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}