#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct myset {
  set<pair<int,int>> data;
  ll sum = 0;
  int ys = 0;
  void insert(pair<int,int> dt) {
    auto [d,t] = dt;
    sum += d;
    ys += t;
    data.insert(dt);
  }
  void erase(pair<int,int> dt) {
    auto [d,t] = dt;
    sum -= d;
    ys -= t;
    data.erase(dt);
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  myset a, b;
  auto l = [&]() {
    auto d = *b.data.begin();
    b.erase(d);
    a.insert(d);
  };
  auto r = [&]() {
    auto d = *a.data.rbegin();
    a.erase(d);
    b.insert(d);
  };
  int ys = 0;
  while (q--) {
    int type, d;
    cin >> type >> d;
    if (d > 0) {
      b.insert({d,type});
      if (type == 1) ys++;
    } else {
      d *= -1;
      auto dt = make_pair(d,type);
      if (a.data.count(dt)) a.erase(dt);
      else b.erase(dt);
      if (type == 1) ys--;
    }
    while (b.data.size() < ys) r();
    while (b.data.size() > ys) l();
    while (a.data.size() && b.data.size() && *a.data.rbegin() > *b.data.begin()) l(),r();
    ll ans = a.sum+b.sum*2;
    if (b.ys == ys) {
      if (b.data.size())
	ans -= b.data.begin()->first;
      if (a.data.size() && ys)
	ans += a.data.rbegin()->first;
    }
    cout << ans << endl;
  }
}