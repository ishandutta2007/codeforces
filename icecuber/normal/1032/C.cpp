#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int par[100000][5];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> dp(5,1);
  int last;
  cin >> last;
  for (int i = 1; i < n; i++) {
    vector<int> ndp(5,0);
    int a;
    cin >> a;
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
	if (dp[k]) {
	  int ok = (a < last && j < k ||
		    a > last && j > k ||
		    a == last && j != k);
	  if (ok) {
	    ndp[j] = 1;
	    par[i][j] = k;
	  }
	}
      }
    }
    last = a;
    swap(dp,ndp);
  }
  for (int i = 0; i < 5; i++) {
    if (dp[i]) {
      vector<int> ans;
      int p = i;
      for (int j = n-1; j >= 0; j--) {
	ans.push_back(p+1);
	p = par[j][p];
      }
      reverse(ans.begin(), ans.end());
      for (int i : ans) cout << i << ' ';
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}