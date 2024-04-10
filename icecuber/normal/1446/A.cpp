#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,int>> w;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      if (v > m) continue;
      w.emplace_back(v,i+1);
      sum += v;
    }
    if (sum < (m+1)/2) {
      cout << -1 << endl;
      continue;
    }
    int done = 0;
    vector<int> ans;
    ll acc = 0;
    for (auto [v,i] : w) {
      if (v >= (m+1)/2 && v <= m) {
        cout << 1 << endl;
        cout << i << endl;
        done = 1;
        break;
      }
      acc += v;
      ans.push_back(i);
      if (acc >= (m+1)/2) break;
    }
    if (!done) {
      cout << ans.size() << endl;
      for (int i : ans) cout << i << ' ';
      cout << endl;
    }
  }
}