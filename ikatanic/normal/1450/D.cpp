#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <set>
#include <stack>
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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }

    vector<int> l(n), r(n);
    stack<pair<int, int>> S;
    S.push({-1, -1});
    for (int i = 0; i < n; ++i) {
      while (a[i] < S.top().first) S.pop();
      l[i] = S.top().second + 1;
      S.push({a[i], i});
    }
    while (!S.empty()) S.pop();
    S.push({-1, n});
    for (int i = n - 1; i >= 0; --i) {
      while (a[i] <= S.top().first) S.pop();
      r[i] = S.top().second - 1;
      S.push({a[i], i});
    }

    vector<vector<pair<int, int>>> ev(n + 10);
    int maxBad = 0;
    for (int i = 0; i < n; ++i) {
      int d = r[i] - l[i] + 1;
      ev[1].push_back({a[i], +1});
      ev[d + 1].push_back({a[i], -1});

      if (l[i] < i && r[i] > i) {
        maxBad = max(maxBad, d - 1);
      }
    }

    string ret(n, '0');
    vector<int> cnt(n);
    int cntDup = 0;
    set<int> s;
    for (int i = 1; i <= n; ++i) {
      for (auto& e : ev[i]) {
        int x = e.first;
        if (e.second == +1) {
          if (cnt[x] == 1) cntDup++;
          if (cnt[x] == 0) s.insert(x);
          cnt[x]++;
        } else {
          if (cnt[x] == 2) cntDup--;
          if (cnt[x] == 1) s.erase(x);
          cnt[x]--;
        }
      }

      if (i > 1 && i <= maxBad) continue;

      if (cntDup == 0 && S.size() && *(--s.end()) + 1 == s.size()) {
        ret[i - 1] = '1';
      }
    }

    cout << ret << '\n';
  }

  return 0;
}