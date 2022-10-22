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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> ans;
    while (1) {
      vector<int> has(n+1);
      for (int v : a) has[v] = 1;
      int mex = 0;
      while (has[mex]) mex++;
      if (mex == n) {
	int x = 0;
	while (x < n && a[x] == x) x++;
	if (x == n) break;

	ans.push_back(x);
	a[x] = mex;
      } else {
	ans.push_back(mex);
	a[mex] = mex;
      }
    }
    cout << ans.size() << endl;
    for (int x : ans) cout << x+1 << ' ';
    cout << endl;
  }
}