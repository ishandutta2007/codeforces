#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[26][26];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < w; j++) {
      a[i+1][j+1] = a[i][j+1]+a[i+1][j]-a[i][j]+s[j]-'0';
    }
  }
  int ans = 0;
  for (int x0 = 0; x0 < w; x0++)
    for (int y0 = 0; y0 < h; y0++)
      for (int x1 = x0+1; x1 <= w; x1++)
	for (int y1 = y0+1; y1 <= h; y1++)
	  if (a[y1][x1]+a[y0][x0]-a[y1][x0]-a[y0][x1] == 0)
	    ans = max(ans, x1-x0+y1-y0);
  cout << ans*2 << endl;
}