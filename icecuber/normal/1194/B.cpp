#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s[50000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int h, w;
    cin >> h >> w;
    vector<int> col(w,0),row(h,0);
    for (int i = 0; i < h; i++) {
      cin >> s[i];
      for (int j = 0; j < w; j++) {
	if (s[i][j] == '.') row[i]++, col[j]++;
      }
    }
    int ans = 1e9;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
	ans = min(ans, row[i]+col[j]-(s[i][j]=='.'));
      }
    }
    cout << ans << endl;
  }
}