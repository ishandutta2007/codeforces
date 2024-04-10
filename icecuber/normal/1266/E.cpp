#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5+10;
ll a[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll need = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    need += a[i];
  }
  int q;
  cin >> q;
  map<pair<int,int>, int> m;
  while (q--) {
    int s, t, u;
    cin >> s >> t >> u;
    if (m.count({s,t})) {
      ll&v = a[m[{s,t}]];
      need -= max(v, 0ll);
      v++;
      need += max(v, 0ll);
      m.erase({s,t});
    }
    if (u) {
      ll&v = a[m[{s,t}] = u];
      need -= max(v, 0ll);
      v--;
      need += max(v, 0ll);
    }
    cout << need << '\n';
  }
}