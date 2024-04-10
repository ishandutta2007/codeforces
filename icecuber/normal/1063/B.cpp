#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string board[2000];
int dist[2000][2000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  int sx, sy;
  cin >> sy >> sx;
  sx--, sy--;
  int maxleft, maxright;
  cin >> maxleft >> maxright;
  for (int i = 0; i < h; i++) {
    cin >> board[i];
    for (int j = 0; j < w; j++)
      dist[i][j] = 2e9;
  }
  priority_queue<pair<int, pair<int, int>>> q;
  q.push({0,{sx,sy}});
  dist[sy][sx] = 0;
  while (q.size()) {
    int x = q.top().second.first;
    int y = q.top().second.second;
    int d =-q.top().first;
    q.pop();
    if (d > dist[y][x]) continue;
    for (int i = 0; i < 4; i++) {
      int nx = x+(i==0)-(i==1);
      int ny = y+(i==2)-(i==3);
      int len = (i==0);
      if (nx >= 0 && nx < w && ny >= 0 && ny < h &&
	  board[ny][nx] == '.' && dist[ny][nx] > dist[y][x]+len) {
	dist[ny][nx] = dist[y][x]+len;
	q.push({-dist[ny][nx], {nx,ny}});
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      ans += dist[i][j] <= maxright && dist[i][j]+sx-j <= maxleft;
  cout << ans << endl;
}