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
    vector<pair<int,int>> ans;
    int cur = n;
    for (int i = n-2; i >= 0; i--) {
      ans.push_back({i+1,cur});
      cur = (cur+i+1 +1)/2;
    }
    cout << cur << endl;
    for (auto [a,b] : ans) cout << a << ' ' << b << endl;
  }
}