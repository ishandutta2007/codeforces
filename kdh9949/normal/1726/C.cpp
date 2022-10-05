#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;
  s = " " + s;

  vector<int> lev(2 * n + 1);
  for(int i = 1; i <= 2 * n; ++i) lev[i] = lev[i - 1] + (s[i] == '(' ? 1 : -1);

  vector<int> p(2 * n + 1);
  iota(p.begin(), p.end(), 0);
  const function<int(int)> f = [&](int x) {
    return p[x] = (x == p[x] ? x : f(p[x]));
  };
  const auto u = [&](int x, int y) { p[f(y)] = f(x); };

  vector<vector<int>> lst(n + 2);
  for(int i = 1; i <= 2 * n; ++i) {
    if(s[i] == '(') {
      lst[lev[i]].push_back(i);
    }
    else {
      int sz = lst[lev[i] + 1].size();
      for(int j = 1; j <= 2; ++j) if(j <= sz) u(i, lst[lev[i] + 1][sz - j]);
      lst[lev[i] + 2].clear();
    }
  }

  int ans = 0;
  for(int i = 1; i <= 2 * n; ++i) if(f(i) == i) ++ans;
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}