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
    map<int,int> cnt;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      cnt[abs(v)]++;
    }
    int ans = 0;
    for (auto [v,c] : cnt) {
      if (v && c > 1) ans += 2;
      else ans++;
    }
    cout << ans << endl;
  }
}