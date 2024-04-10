#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
  
    for(int i = n; i >= 0; --i) {
      int done = 1;
      multiset<int> s;
      for(int x : v) s.insert(x);
      for(int j = 0; j < i; ++j) {
        if(s.empty()) { done = 0; break; }
        auto it = s.upper_bound(i - j);
        if(it == s.begin()) { done = 0; break; }
        s.erase(prev(it));
        if(!s.empty()) s.erase(s.begin());
      }
      if(done) { cout << i << '\n'; break; }
    }
  }

  return 0;
}