#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string sorted(string s) {
  sort(s.begin(), s.end());
  return s;
}

void self_max(int&a, int b) {
  a = max(a, b);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (sorted(a) != sorted(b)) {
      cout << -1 << endl;
      continue;
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1e9));
    dp[n][n] = 0;
    vector<int> ca(26),cb(26);
    for (int i = n; i >= 0; i--) {
      fill_n(cb.begin(), 26, 0);
      for (int j = n; j >= 0; j--) {
	if (dp[i][j] < 0) continue;
	if (j) cb[b[j-1]-'a']++;

	if (i && j && a[i-1] == b[j-1]) {
	  self_max(dp[i-1][j-1], dp[i][j]+1);
	}
	if (i) {
	  self_max(dp[i-1][j], dp[i][j]);
	}
	if (j) {
	  int ok = 1;
	  for (int c = 0; c < 26; c++)
	    if (ca[c] < cb[c]) ok = 0;
	  if (ok)
	    self_max(dp[i][j-1], dp[i][j]);
	}
      }
      if (i) ca[a[i-1]-'a']++;
    }
    cout << n-dp[0][0] << endl;
  }
}