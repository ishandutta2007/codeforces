#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> cnt;
    for (int&v : a) cin >> v, cnt[v] ^= 1;
    auto cp = a;
    int ok = 1;
    for (auto [v,c] : cnt) if (c) ok = 0;
    if (!ok) {
      cout << -1 << endl;
      continue;
    }

    vector<int> groups;
    vector<array<int,2>> add;
    int off = 0;
    while (a.size()) {
      int v = a[0];
      int r = 1;
      while (a[r] != v) r++;
      if (r == 1) {
        groups.push_back(2);
        a.erase(a.begin());
        a.erase(a.begin());
      } else {
        for (int j = 0; j < r; j++) {
          add.push_back({off+r+j, a[j]});
        }
        groups.push_back(r*2);
        reverse(a.begin(), a.begin()+r);
      }
      off += r*2;
    }
    cout << add.size() << endl;
    for (auto [p,c] : add) cout << p << ' ' << c << '\n';
    cout << groups.size() << endl;
    for (int v : groups) cout << v << ' ';
    cout << endl;

    /*
    assert((int)add.size() <= 2*n*n);
    for (auto [p,c] : add) {
      cp.insert(cp.begin()+p, c);
      cp.insert(cp.begin()+p, c);
    }
    int acc = 0;
    for (int v : groups) {
      assert(v%2 == 0);
      for (int i = 0; i < v/2; i++) {
        assert(cp[acc+i] == cp[acc+v/2+i]);
      }
      acc += v;
    }
    assert(acc == (int)cp.size());*/
  }
}