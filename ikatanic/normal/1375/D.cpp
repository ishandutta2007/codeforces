#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cout << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

int mex(const vector<int>& a) {
  int n = a.size();
  vector<bool> have(n + 1, false);
  for (int x : a) have[x] = true;
  int i = 0;
  while (have[i]) i++;
  return i;
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

    vector<int> ans;
    while (true) {
      vector<int> bad;
      for (int i = 0; i < n; ++i)
        if (a[i] != i) bad.push_back(i);
      if (bad.empty()) break;

      int m = mex(a);
      if (m == n) {
        int i = bad.back();
        ans.push_back(i);
        a[i] = m;
      } else {
        assert(a[m] != m);
        a[m] = m;
        ans.push_back(m);
      }
    }

    cout << ans.size() << "\n";
    for (int x: ans) cout << x+1 << ' ';
    cout << '\n';
  }
  return 0;
}