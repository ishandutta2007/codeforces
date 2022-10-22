#line 1 "codeforces-workspace/contest/1450/d/d.cpp"
#include <bits/extc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), is(n);
  for (auto &&e : a) {
    cin >> e;
    --e;
    is[e]++;
  }

  vector<int> sum(1 + n);
  bool per = 1;
  for (auto i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + is[i];
    if (!is[i]) per = 0;
  }

  string ans(n, '0');
  for (auto k = n, l = 0, r = n; k > 0; k--) {
    if (sum[n - k] != n - k or !is[n - k]) {
      break;
    }
    ans[k - 1] = '1';
    if (a[l] == n - k) {
      l++;
    } else if (a[r - 1] == n - k) {
      r--;
    } else
      break;
  }

  if (per) ans[0] = '1';

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}