#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s[500];
int reachable[500][500];
int done[500][500];

int h, w;
void dfs(int x, int y) {
  reachable[y][x] = 1;
  if (done[y][x]++ || s[y][x] == 'X') return;
  for (int i = 0; i < 4; i++) {
    int nx = x+(i==0)-(i==1);
    int ny = y+(i==2)-(i==3);
    if (nx >= 0 && ny >= 0 && nx < w && ny < h) {
      dfs(nx,ny);
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> h >> w;
  for (int i = 0; i < h; i++)
    cin >> s[i];
  int sx, sy, ex, ey;
  cin >> sy >> sx >> ey >> ex;
  sx--,sy--,ex--,ey--;

  s[sy][sx] = '.';
  dfs(sx,sy);
  int frees = 0;
  for (int i = 0; i < 4; i++) {
    int nx = ex+(i==0)-(i==1);
    int ny = ey+(i==2)-(i==3);
    if (nx >= 0 && ny >= 0 && nx < w && ny < h && s[ny][nx] == '.') frees++;
  }
  s[sy][sx] = 'X';
  if (reachable[ey][ex] && (frees >= 2 || (frees >= 1 && s[ey][ex] == 'X'))) {
    cout << "YES" << endl;
  } else
    cout << "NO" <<endl;
}