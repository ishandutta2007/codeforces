#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int taken[100][100];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q, n;
  cin >> q >> n;
  int c = n/2;
  while (q--) {
    int m;
    cin >> m;
    int best = 1e9, besti, bestj;
    for (int i = 0; i < n; i++) {
      int fill = 0, v = abs(i-c)*m;
      for (int j = 0; j < n; j++) {
	fill += taken[i][j];
	v += abs(j-c);
	if (j >= m) {
	  fill -= taken[i][j-m];
	  v -= abs(j-m-c);
	}
	if (j >= m-1 && !fill && v < best) {
	  best = v;
	  besti = i;
	  bestj = j+1-m;
	}
      }
    }
    if (best == 1e9) cout << -1 << endl;
    else {
      cout << besti+1 << ' ' << bestj+1 << ' ' << bestj+m << endl;
      for (int j = 0; j < m; j++)
	taken[besti][bestj+j] = 1;
    }
  }
}