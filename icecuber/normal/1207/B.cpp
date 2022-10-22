#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[50][50], b[50][50];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> a[i][j];
  vector<pair<int,int>> ans;
  for (int i = 0; i+1 < h; i++)
    for (int j = 0; j+1 < w; j++) {
      if (a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) {
	ans.push_back({i+1,j+1});
	b[i][j] = b[i+1][j] = b[i][j+1] = b[i+1][j+1] = 1;
      }
    }
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      if (a[i][j] != b[i][j]) {
	cout << -1 << endl;
	return 0;
      }
  cout << ans.size() << endl;
  for (auto p : ans) {
    cout << p.first << ' ' << p.second << endl;
  }
}