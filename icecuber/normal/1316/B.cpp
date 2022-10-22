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
    string s;
    cin >> s;
    pair<string,int> ans = {s, 1};
    for (int k = 1; k <= n; k++) {
      string t = s.substr(k-1,n-k+1);
      string r = s.substr(0,k-1);
      if ((n-k+1)%2) reverse(r.begin(), r.end());
      t += r;
      ans = min(ans, make_pair(t, k));
    }
    cout << ans.first << endl << ans.second << endl;
  }
}