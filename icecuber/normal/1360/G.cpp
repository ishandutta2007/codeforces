#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int h, w, nx, ny;
    cin >> h >> w >> nx >> ny;
    if (h*nx != w*ny) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    vector<vector<int>> ans(h,vector<int>(w,0));
    int p = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < nx; j++) {
	ans[i][p] = 1;
	p = (p+1)%w;
      }
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
	cout << ans[i][j];
      }
      cout << endl;
    }
  }
}