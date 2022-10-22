#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, x;
    cin >> n >> m >> x;
    set<array<int,2>> s;
    for (int i = 0; i < m; i++) {
      s.insert({0,i+1});
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      int h;
      cin >> h;
      auto it = s.begin();
      auto [prv,idx] = *it;
      s.erase(it);
      cout << idx << ' ';
      s.insert({prv+h,idx});
    }
    cout << endl;
  }
}