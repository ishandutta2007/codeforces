#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int goods = 0;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int pars = 0, oka = 1;
    for (char c : s) {
      pars += (c=='(')-(c==')');
      if (pars < 0) oka = 0;
    }
    if (oka && pars > 0)
      m[pars]++;
    pars = 0;
    int okb = 1;
    reverse(s.begin(), s.end());
    for (char c : s) {
      pars += (c==')')-(c=='(');
      if (pars < 0) okb = 0;
    }
    if (okb && pars > 0)
      m[-pars]++;
    if (oka && okb && pars == 0) goods++;
  }
  int ans = goods/2;
  for (auto p : m) {
    if (p.first > 0 && m.count(-p.first)) ans += min(m[p.first],m[-p.first]);
  }
  cout << ans << endl;
}