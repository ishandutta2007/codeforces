#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  multiset<int> p, d;
  auto add = [&](int x) {
    assert(!p.count(x));
    p.insert(x);
    auto it = p.find(x);
    auto b = next(it);
    if (b != p.end()) {
      d.insert(abs(*it-*b));
    }
    if (it != p.begin()) {
      auto a = prev(it);
      d.insert(abs(*it-*a));

      if (b != p.end()) {
	d.erase(d.find(abs(*b-*a)));
      }
    }
  };
  auto remove = [&](int x) {
    assert(p.count(x));
    auto it = p.find(x);
    auto b = next(it);
    if (b != p.end()) {
      d.erase(d.find(abs(*it-*b)));
    }
    if (it != p.begin()) {
      auto a = prev(it);
      d.erase(d.find(abs(*it-*a)));

      if (b != p.end()) {
	d.insert(abs(*b-*a));
      }
    }
    p.erase(it);
  };
  auto query = [&]() {
    if (p.size() <= 2) return 0;
    return *p.rbegin()-*p.begin()-*d.rbegin();
  };
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    add(x);
  }
  cout << query() << endl;
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 0) remove(x);
    else add(x);
    cout << query() << endl;
  }
}