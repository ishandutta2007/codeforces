#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Slope {
  priority_queue<ll> l;
  priority_queue<ll,vector<ll>,greater<ll>> r;
  ll loff = 0, roff = 0;
  ll ans = 0;
  void min(ll k) {
    assert(k >= 0);
    loff -= k;
    roff += k;
  }
  void add(ll x) {
    ll lmid = l.size() ? l.top()+loff :-ll(1e18);
    ll rmid = r.size() ? r.top()+roff : ll(1e18);
    assert(lmid <= rmid);
    if (x <= lmid) {
      l.push(x-loff);
      l.push(x-loff);
      r.push(l.top()+loff-roff);
      l.pop();
    } else {
      r.push(x-roff);
      r.push(x-roff);
      l.push(r.top()+roff-loff);
      r.pop();
    }
    ll nmid = l.top()+loff;
    ans += ::max({lmid-nmid,nmid-rmid,0ll})+abs(nmid-x);
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<array<int,2>> pos(n);
  for (auto&[x,y] : pos) cin >> x >> y;
  sort(pos.begin(), pos.end(), [&](const auto&a, const auto&b) {
    return a[0]+a[1] < b[0]+b[1];
  });
  Slope slope;
  if (0) {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
      v.push_back(rand()%10);
      slope.add(v.back());
    }
    cout << slope.ans << endl;
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int x : v) ans += abs(x-v[v.size()/2]);
    cout << ans << endl;
    return 0;
  }


  for (int i = 0; i < n*2; i++) slope.add(0);
  int last = 0;
  for (auto [x,y] : pos) {
    slope.min(x+y-last);
    last = x+y;
    slope.add(x-y);
  }
  cout << slope.ans/2 << endl;
}