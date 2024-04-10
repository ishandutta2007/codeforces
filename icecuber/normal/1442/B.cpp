#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> b(k), ai(n+1);
    set<pair<int,int>> sa;

    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      sa.insert({i,a});
      ai[a] = i;
    }

    set<int> bleft;
    for (int i = 0; i < k; i++) {
      cin >> b[i];
      bleft.insert(b[i]);
    }
    int ans = 1;
    const int mod = 998244353;
    for (int i = 0; i < k; i++) {
      auto it = sa.find({ai[b[i]], b[i]});
      bleft.erase(b[i]);
      int m = 0;
      auto torem = sa.end();
      if (it != sa.begin() && !bleft.count(prev(it)->second)) m++, torem = prev(it);
      if (next(it) != sa.end() && !bleft.count(next(it)->second)) m++, torem = next(it);
      ans = ans*m%mod;
      if (m == 0) break;

      sa.erase(torem);
    }
    cout << ans << endl;
  }
}