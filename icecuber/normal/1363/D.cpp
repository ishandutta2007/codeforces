#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int query(vector<int> a) {
  cout << "? " << a.size();
  for (int i : a) cout << ' ' << i+1;
  cout << endl;
  int ans;
  cin >> ans;
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> subsets(k);
    for (int i = 0; i < k; i++) {
      int c;
      cin >> c;
      subsets[i].resize(c);
      for (int&v : subsets[i])
	cin >> v, v--;
    }
    vector<int> all;
    for (int i = 0; i < n; i++)
      all.push_back(i);

    int ma = query(all);
    int l = 0, r = n;
    while (r-l > 1) {
      int m = (r+l)/2;
      vector<int> a;
      for (int i = l; i < m; i++)
	a.push_back(i);
      if (query(a) == ma) r = m;
      else l = m;
    }

    vector<int> ans(k, ma);
    for (int i = 0; i < k; i++) {
      auto s = subsets[i];
      if (count(s.begin(), s.end(), l)) {
	vector<int> inv;
	for (int j = 0; j < n; j++) {
	  if (!count(s.begin(), s.end(), j))
	    inv.push_back(j);
	}
	ans[i] = query(inv);
      }
    }
    cout << "!";
    for (int i = 0; i < k; i++)
      cout << ' ' << ans[i];
    cout << endl;

    string verdict;
    cin >> verdict;
    assert(verdict == "Correct");
  }
}