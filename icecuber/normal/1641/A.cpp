#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    map<int,map<int,int>> m;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      int p = 0;
      while (v%x == 0) {
        v /= x;
        p++;
      }
      m[v][p]++;
    }
    int ans = 0;
    for (auto [_,v] : m) {
      int mi = v.begin()->first;
      int ma = v.rbegin()->first;
      for (int i = mi; i <= ma; i++) {
        while (v[i]) {
          v[i]--;
          if (v[i+1]) v[i+1]--;
          else ans++;
        }
      }
    }
    cout << ans << endl;
  }
}