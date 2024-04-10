#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[500][500];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> a[i][j];
  for (int i = h-2; i >= 0; i--) {
    for (int j = w-2; j >= 0; j--) {
      if (!a[i][j]) {
	a[i][j] = min(a[i+1][j],a[i][j+1])-1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      if (i+1 < h && a[i][j] >= a[i+1][j] || j+1 < w && a[i][j] >= a[i][j+1]) {
	cout << -1 << endl;
	return 0;
      }
      ans += a[i][j];
    }
  cout << ans << endl;
}