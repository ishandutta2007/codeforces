#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dist[2][1000][1000];
int dx[8] = {1,1,2,2,-1,-1,-2,-2};
int dy[8] = {2,-2,1,-1,2,-2,1,-1};

int w, h;
void bfs(int sx, int sy, int dist[][1000]) {
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      dist[i][j] = 1e9;

  dist[sy][sx] = 0;
  queue<pair<int,int>> q;
  q.push({sx,sy});
  while (q.size()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    int d = dist[y][x]+1;
    for (int i = 0; i < 8; i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if (nx >= 0 && nx < w && ny >= 0 && ny < h && d < dist[ny][nx]) {
	dist[ny][nx] = d;
	q.push({nx,ny});
      }
    }
  }
}

int ox = -10, oy = -10;

void go(int x, int y, int dist[][1000], int dist2[][1000]) {
  while (1) {
    for (int i = 0; i < 8; i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if (ox == nx+1 && oy == ny+1) {
	cout << ny+1 << ' ' << nx+1 << endl;
	exit(0);
      }
    }

    int d = dist[y][x];
    if (d == 0) return;
    for (int i = 0; i < 8; i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if (nx >= 0 && nx < w && ny >= 0 && ny < h && d > dist[ny][nx]) {
	x = nx;
	y = ny;
	cout << ny+1 << ' ' << nx+1 << endl;
	if (dist2[y][x] == 0) {
	  exit(0);
	}
	cin >> oy >> ox;
	break;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> h >> w;
  int y1, x1, y2, x2;
  cin >> y1 >> x1 >> y2 >> x2;
  x1--, y1--, x2--, y2--;

  bfs(w/2-1, h/2-1, dist[0]);
  bfs(w/2-1, h/2, dist[1]);

  double white_goal = dist[0][y1][x1];
  double black_goal = dist[1][y2][x2]+0.5;
  double white_block = dist[1][y1][x1];
  double black_block = dist[0][y2][x2]+0.5;

  if ((x1+y1)%2 == (x2+y2)%2) {
    //Black knight can't be captured
    if (black_goal < white_goal) {
      cout << "BLACK" << endl;
      cin >> oy >> ox;
      go(x2, y2, dist[1], dist[1]);
    } else if (black_block < white_goal+1) {
      cout << "BLACK" << endl;
      cin >> oy >> ox;
      go(x2, y2, dist[0], dist[1]);
      go(w/2-1, h/2-1, dist[1], dist[1]);
    } else {
      cout << "WHITE" << endl;
      go(x1, y1, dist[0], dist[0]);
    }
  } else {
    //White knight can't be captured
    if (white_goal < black_goal) {
      cout << "WHITE" << endl;
      go(x1, y1, dist[0], dist[0]);
    } else if (white_block < black_goal+1) {
      cout << "WHITE" << endl;
      go(x1, y1, dist[1], dist[0]);
      go(w/2-1, h/2, dist[0], dist[0]);
    } else {
      cout << "BLACK" << endl;
      cin >> oy >> ox;
      go(x2, y2, dist[1], dist[1]);
    }
  }
}