#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Seg {
  int mi, ma;
  Seg() {
    mi = 1e9;
    ma =-1e9;
  }
  void add(int i) {
    mi = min(mi, i);
    ma = max(ma, i);
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    Seg sx[26], sy[26];
    for (int i = 0; i < h; i++) {
      cin >> s[i];
      for (int j = 0; j < w; j++) {
	if (s[i][j] == '.') continue;
	sx[s[i][j]-'a'].add(j);
	sy[s[i][j]-'a'].add(i);
      }
    }
    vector<vector<int>> ans;
    for (int c = 0; c < 26; c++) {
      if (sx[c].ma < 0) continue;
      if (sx[c].ma > sx[c].mi && sy[c].ma > sy[c].mi)
	goto fail;
      for (int i = sy[c].mi; i <= sy[c].ma; i++) {
	for (int j = sx[c].mi; j <= sx[c].ma; j++) {
	  if (s[i][j] == '.' || s[i][j] < c+'a')
	    goto fail;
	}
      }
      while (ans.size() <= c)
	ans.push_back({sy[c].mi+1, sx[c].mi+1, sy[c].ma+1, sx[c].ma+1});
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (auto v : ans) {
      for (int i : v) cout << i << ' '; cout << endl;
    }
    continue;
  fail:
    cout << "NO" << endl;
  }
}