#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    map<pair<int,int>, int> m;
    int n;
    string s;
    cin >> n >> s;
    int x = 0, y = 0;
    m[{x,y}] = -1;
    int best = 1e9;
    pair<int,int> ans;
    for (int i = 0; i < n; i++) {
      x += (s[i]=='R')-(s[i]=='L');
      y += (s[i]=='U')-(s[i]=='D');
      if (m.count({x,y})) {
	int j = m[{x,y}];
	if (i-j < best) {
	  best = i-j;
	  ans = {j, i};
	}
      }
      m[{x,y}] = i;
    }
    if (best == 1e9) {
      cout << -1 << endl;
    } else {
      cout << ans.first+2 << ' ' << ans.second+1 << endl;
    }
  }
}