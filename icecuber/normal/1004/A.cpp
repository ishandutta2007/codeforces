#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<int> x(n);
  for (int&v : x) cin >> v;
  set<int> ans;
  for (int v : x) {
    for (int p : {v-d, v+d}) {
      int mi = 2e9+10;
      for (int y : x) mi = min(mi, abs(y-p));
      if (mi == d) ans.insert(p);
    }
  }
  cout << ans.size() << endl;
}