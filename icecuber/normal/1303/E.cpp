#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    int ok = 0;
    for (int ti = 0; ti <= t.size(); ti++) {
      string a = t.substr(0, ti), b = t.substr(ti, t.size()-ti);
      vector<int> dp(a.size()+1, -1);
      dp[0] = 0;
      for (char c : s) {
	vector<int> ndp = dp;
	for (int i = 0; i <= a.size(); i++) {
	  if (dp[i] == -1) continue;
	  //Add to a
	  if (i < a.size() && a[i] == c) {
	    ndp[i+1] = max(ndp[i+1], dp[i]);
	  }

	  //Add to b
	  if (dp[i] < b.size() && b[dp[i]] == c) {
	    ndp[i] = max(ndp[i], dp[i]+1);
	  }
	}
	dp = ndp;
      }
      if (dp[a.size()] == b.size()) {
	ok = 1;
	break;
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}