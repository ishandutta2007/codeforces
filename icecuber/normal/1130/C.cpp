#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string a[50];
int col[50][50];
int n;

void fill(int x, int y, int c) {
  if (col[y][x]) return;
  col[y][x] = c;
  for (int i = 0; i < 4; i++) {
    int nx = x+(i==0)-(i==1);
    int ny = y+(i==2)-(i==3);
    if (nx < 0 || ny < 0 || nx >= n || ny >= n || a[ny][nx] == '1') continue;
    fill(nx,ny,c);
  }
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  int ax, ay, bx, by;
  cin >> ay >> ax >> by >> bx;
  ax--,ay--,bx--,by--;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  fill(ax,ay,1);
  if (col[by][bx] == 1) {
    cout << 0 << endl;
    return 0;
  }
  fill(bx, by, 2);
  int ans = 1e9;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (col[i][j] != 1) continue;
      for (int k = 0; k < n; k++)
	for (int l = 0; l < n; l++) {
	  if (col[k][l] != 2) continue;
	  ans = min(ans, (i-k)*(i-k)+(j-l)*(j-l));
	}
    }
  cout << ans << endl;
}