#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    string ans;
    auto check = [&](string s) {
      for (int i = 0; i < n; i++) {
	int diffs = 0;
	for (int j = 0; j < m; j++)
	  if (a[i][j] != s[j])
	    diffs++;
	if (diffs > 1) return;
      }
      ans = s;
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
	for (char c = 'a'; c <= 'z'; c++) {
	  string cp = a[i];
	  cp[j] = c;
	  check(cp);
	}
      }
    }
    if (ans.empty())
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
}