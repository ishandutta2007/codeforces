#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int query(int p) {
  cout << "? " << p+1 << endl;
  int ans;
  cin >> ans;
  return ans-1;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<array<int,2>> d(n);
    for (int i = 0; i < n; i++) {
      d[i][1] = i;
      cin >> d[i][0];
    }
    sort(d.rbegin(), d.rend());

    vector<int> par(n), done(n);
    for (int i = 0; i < n; i++) par[i] = i;
    function<int(int)> Find = [&](int p) {
      return p == par[p] ? p : par[p] = Find(par[p]);
    };
    for (auto [deg,i] : d) {
      if (done[i]++) continue;
      for (int x = 0; x < deg; x++) {
        int b = query(i);
        par[Find(b)] = Find(i);
        if (done[b]++) break;
      }
    }
    cout << "!";
    for (int i = 0; i < n; i++) {
      cout << ' ' << Find(i)+1;
    }
    cout << endl;
  }
}