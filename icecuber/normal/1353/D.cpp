#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    set<tuple<int,int,int>> lens;
    int n;
    cin >> n;
    lens.emplace(-n, 0, n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      auto [len,l,r] = *lens.begin();
      lens.erase(lens.begin());
      int m = (l+r-1)>>1;
      ans[m] = i+1;
      lens.emplace(-(m-l), l, m);
      lens.emplace(-(r-m-1), m+1, r);
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << ' ';
    }
    cout << endl;
  }
}