#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[300][300];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
	cin >> a[i][j];
    int ok = 1;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
	int nbrs = 0;
	for (int d = 0; d < 4; d++) {
	  int ni = i+(d==0)-(d==1);
	  int nj = j+(d==2)-(d==3);
	  if (ni >= 0 && nj >= 0 && ni < h && nj < w)
	    nbrs++;
	}
	if (a[i][j] > nbrs) ok = 0;
	a[i][j] = nbrs;
      }
    }
    if (!ok) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++)
	cout << a[i][j] << ' ';
      cout << endl;
    }
  }
}