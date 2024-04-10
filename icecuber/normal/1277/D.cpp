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
    vector<pair<string,int>> c[2][2];
    map<string,int> matched;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      int a = s[0]-'0', b = s.back()-'0';
      if (!a && b) {
	reverse(s.begin(), s.end());
      }
      if (a ^ b) matched[s]++;
      c[a][b].emplace_back(s, i+1);
    }

    if (c[0][0].size() && c[1][1].size() && !c[0][1].size() && !c[1][0].size()) {
      cout << -1 << endl;
    } else {
      int ans = abs((int)c[0][1].size()-(int)c[1][0].size())/2;
      cout << ans << endl;
      vector<pair<string,int>> a = c[0][1], b = c[1][0];
      if (c[0][1].size() < c[1][0].size()) swap(a, b);
      int j = 0;
      for (int i = 0; i < ans; i++) {
	while (matched[a[j].first] == 2) j++;
	cout << a[j++].second << ' ';
      }
      cout << endl;
    }
  }
}