#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int acc[4][501][501];
int sparse[9][9][501][501];

int area(int k, int r0, int c0, int r1, int c1) {
  return acc[k][r1][c1]+acc[k][r0][c0]-acc[k][r0][c1]-acc[k][r1][c0];
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w, q;
  cin >> h >> w >> q;
  for (int i = 0; i < h; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < w; j++) {
      for (int k = 0; k < 4; k++) {
	acc[k][i+1][j+1] = (row[j] == "RGYB"[k])+acc[k][i][j+1]+acc[k][i+1][j]-acc[k][i][j];
      }
    }
  }

  for (int i = 1; i < h; i++) {
    for (int j = 1; j < w; j++) {
      int pass = 0, fail = min({i,j,w-j,h-i})+1;
      while (fail-pass > 1) {
	int mid = pass+fail>>1;
	if (area(0,i-mid,j-mid,i,j) == mid*mid &&
	    area(1,i-mid,j,i,j+mid) == mid*mid &&
	    area(2,i,j-mid,i+mid,j) == mid*mid &&
	    area(3,i,j,i+mid,j+mid) == mid*mid)
	  pass = mid;
	else fail = mid;
      }
      sparse[0][0][i][j] = pass;
    }
  }
  for (int l = 0; l < 9; l++) {
    for (int k = 0; k < 9; k++) {
      for (int i = 1; i+(1<<l) <= h; i++) {
	for (int j = 1; j+(1<<k) <= w; j++) {
	  if (l)
	    sparse[l][k][i][j] = max(sparse[l-1][k][i][j],
				     sparse[l-1][k][i+(1<<l-1)][j]);
	  else if (k) {
	    sparse[l][k][i][j] = max(sparse[l][k-1][i][j],
				     sparse[l][k-1][i][j+(1<<k-1)]);
	  }
	}
      }
    }
  }

  auto queryMax = [&](int r0, int c0, int r1, int c1) {
    r0 = max(r0, 1);
    c0 = max(c0, 1);
    r1 = min(r1, h);
    c1 = min(c1, w);
    int dc = c1-c0, dr = r1-r0;
    if (dc <= 0 || dr <= 0) return 0;
    int x = 0, y = 0;
    while (1<<x+1 <= dc) x++;
    while (1<<y+1 <= dr) y++;
    return max({
	  sparse[y][x][r0][c0],
	  sparse[y][x][r1-(1<<y)][c0],
	  sparse[y][x][r1-(1<<y)][c1-(1<<x)],
	  sparse[y][x][r0][c1-(1<<x)]});
  };
  //cout << sparse[0][0][2][2] << endl;
  while (q--) {
    int r0, c0, r1, c1;
    cin >> r0 >> c0 >> r1 >> c1;
    r0--, c0--;
    int pass = 0, fail = min(r1-r0, c1-c0)/2+1;
    while (fail-pass > 1) {
      int mid = pass+fail>>1;
      //cout << r0+mid << ' ' << c0+mid << ' ' << r1-mid << ' '<< c1-mid << endl;
      if (queryMax(r0+mid, c0+mid, r1-mid+1, c1-mid+1) >= mid) pass = mid;
      else fail = mid;
    }
    cout << pass*pass*4 << '\n';
  }
}