#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, w;
  cin >> n >> w;
  vector<string> s(n);
  int best = 0;
  int bestr = 0, bestc = 0;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int tot = 0;
      for (int k = -w+1; k <= 0; k++) {
	int okx = 1, oky = 1;
	for (int l = 0; l < w; l++) {
	  if (j+k+l < 0 || j+k+l >= n || s[i][j+k+l] == '#') okx = 0;
	  if (i+k+l < 0 || i+k+l >= n || s[i+k+l][j] == '#') oky = 0;
	}
	tot += okx+oky;
      }
      if (tot > best) {
	best = tot;
	bestr = i;
	bestc = j;
      }
    }
  }
  cout << bestr+1 << ' ' << bestc+1 << endl;
}