#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int,vector<int>> m;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      m[a].push_back(i);
    }
    vector<int> ans(n+1, 1e9);
    for (auto [a,v] : m) {
      int ma = max(v[0]+1, n-v.back());
      for (int i = 1; i < v.size(); i++)
	ma = max(ma, v[i]-v[i-1]);
      ans[ma] = min(ans[ma], a);
    }
    for (int i = 0; i < n; i++) {
      ans[i+1] = min(ans[i], ans[i+1]);
      cout << (ans[i+1] == 1e9 ? -1 : ans[i+1]) << ' ';
    }
    cout << endl;
  }
}