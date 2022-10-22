#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Deq {
  vector<array<ll,2>> q;
  Deq() {
    q.push_back({-(1ll<<60),-1});
  }
  void add(int x, ll y) {
    while (q.size() && q.back()[0] >= y) q.pop_back();
    q.push_back({y,x});
  }
  int query(ll y) {
    return (*prev(upper_bound(q.begin(), q.end(), array<ll,2>{y,-2})))[1];
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    vector<ll> acc(n+1);
    for (int i = 0; i < n; i++) 
      acc[i+1] = acc[i]+a[i]*(i%2 ? -1 : 1);
    /*vector<int> pmi(n+1), pma(n+1);
    //previous odd position smaller
    for (int i = 0; i <= n; i++) {
      pmi[i] = i-(i%2 ? 2 : 1);
      while (pmi[i] >= 0 && acc[pmi[i]] >= acc[i]) pmi[i] = pmi[pmi[i]];
    }
    //previous even position larger
    for (int i = 0; i <= n; i++) {
      pma[i] = i-(i%2 ? 1 : 2);
      while (pma[i] >= 0 && acc[pma[i]] <= acc[i]) pma[i] = pma[pma[i]];
    }*/


    Deq ma, mi;
    map<ll,vector<int>> seen;
    ll ans = 0;
    for (int r = 1; r <= n; r++) {
      {
        int l = r-1;
        if (l%2) mi.add(l, acc[l]);
        else ma.add(l, -acc[l]);
        seen[acc[l]].push_back(l);
      }
      /*int lim = -1;
      for (int l = r-1; l >= 0; l--) {
        if ((l%2 ? -1 : 1)*(acc[r]-acc[l]) < 0) {
          lim = l;
          break;
        }
      }*/
      int lim = max(ma.query(-acc[r]), mi.query(acc[r]));//max({pma[r], pmi[r], -1});
      //assert(lim == lim2);

      auto&v = seen[acc[r]];
      ans += v.end()-upper_bound(v.begin(), v.end(), lim);
    }
    cout << ans << endl;
  }
}