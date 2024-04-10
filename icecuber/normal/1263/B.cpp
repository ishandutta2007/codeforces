#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<string> used, left;
    vector<string> s;
    for (int i = 0; i < 10; i++)
      left.insert(to_string(i));
    while (n--) {
      string want;
      cin >> want;
      s.push_back(want);
      if (left.count(want.substr(0,1)))
	left.erase(want.substr(0,1));
    }
    int ans = 0;
    vector<string> order;
    for (string want : s) {
      if (used.count(want)) {
	string x = *left.begin();
	left.erase(x);
	want = x+want.substr(1,3);
	ans++;
      }
      used.insert(want);
      order.push_back(want);
    }
    cout << ans << endl;
    for (string s : order) cout << s << endl;
  }
}