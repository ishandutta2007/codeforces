#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      int j = i+1;
      while (j < n && s[j] != t[i]) {
	j++;
      }
      if (j == n) {
	cout << -1 << endl;
	return 0;
      }
      while (j > i) {
	swap(s[j], s[j-1]);
	ans.push_back(j);
	j--;
      }
    }
  }
  cout << ans.size() << endl;
  for (int i : ans) cout << i << ' ';
  cout << endl;
}