#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> par(n), sz(n);
  for (int i = 0; i < n; i++) sz[i] = 1, par[i] = i;

  function<int(int)> Find = [&](int p) {
    return p == par[p] ? p : par[p] = Find(par[p]);
  };

  int ans = 0, ccs = 1;
  multiset<int> has, other;
  for (int i = 0; i < n; i++) {
    other.insert(1);
  }
  auto update = [&]() {
    while ((int)has.size() < ccs) {
      int v = *other.rbegin();
      other.erase(other.find(v));
      has.insert(v);
      ans += v;
    }
    assert((int)has.size() == ccs);
    assert(has.empty() || other.empty() || *has.begin() >= *other.rbegin());
  };
  auto erase = [&](int s) {
    if (other.count(s)) other.erase(other.find(s));
    else {
      assert(has.count(s));
      ans -= s;
      has.erase(has.find(s));
    }
  };
  auto add = [&](int s) {
    if (has.size() && s > *has.begin()) {
      int v = *has.begin();
      ans -= v;
      has.erase(has.begin());
      other.insert(v);
      has.insert(s);
      ans += s;
    } else {
      other.insert(s);
    }
  };
  while (q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    a = Find(a);
    b = Find(b);
    if (a == b) {
      ccs++;
    } else {
      if (sz[a] > sz[b]) swap(a,b);
      par[a] = b;
      erase(sz[a]);
      erase(sz[b]);
      sz[b] += sz[a];
      add(sz[b]);
    }
    update();
    cout << ans-1 << endl;
  }
}