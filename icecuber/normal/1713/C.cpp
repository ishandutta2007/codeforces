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
    vector<int> ans;
    int cur = n-1;
    while (cur > -1) {
      int sq = ceil(sqrt(cur));
      sq *= sq;
      int start = sq-cur;
      for (int i = start; i <= cur; i++) {
        ans.push_back(i);
      }
      cur = start-1;
    }
    reverse(ans.begin(), ans.end());
    for (int v : ans) cout << v << ' ';
    cout << endl;
  }
}