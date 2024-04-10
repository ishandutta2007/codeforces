// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class F>
void solve(vector<int>& a, F f) {
  set<int> s, p;
  int mx = -1;
  for (int x : a) {
    if (mx == -1) {
      cout << x << ' ';
      p.insert(x);
      mx = x;
      for (int i=1; i<x; i++) {
        if (!p.count(i)) s.insert(i);
      }
    } else if (x != mx) {
      cout << x << ' ';
      p.insert(x);
      while (mx < x) {
        if (!p.count(mx)) s.insert(mx);
        mx++;
      }
    } else {
      auto it = f(s);
      cout << *it << ' ';
      p.insert(*it);
      s.erase(it);
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    solve(a, [](auto& s) { return s.begin(); });
    solve(a, [](auto& s) { return --s.end(); });
  }
}