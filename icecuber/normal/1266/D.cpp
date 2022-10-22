#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5;
ll balance[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    balance[b] += c;
    balance[a] -= c;
  }
  vector<int> plus, minus;
  for (int i = 0; i < n; i++) {
    if (balance[i] > 0) plus.push_back(i);
    else if (balance[i] < 0) minus.push_back(i);
  }
  {
    vector<tuple<int,int,ll>> ans;
    int i = 0, j = 0;
    while (i < plus.size()) {
      ll&x = balance[plus[i]];
      ll&y = balance[minus[j]];
      ll z = min(x, -y);
      ans.emplace_back(minus[j]+1, plus[i]+1, z);
      x -= z;
      y += z;
      if (!x) i++;
      if (!y) j++;
    }
    assert(j == minus.size());
    cout << ans.size() << endl;
    for (auto [a,b,c] : ans)
      cout << a << ' ' << b << ' ' << c << '\n';
  }
}