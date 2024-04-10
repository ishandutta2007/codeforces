#include <iostream>
#include <queue>

using namespace std;

int a[10][10];
pair<int, int> dist[10][10][3][102];
int done[10][10][3][102];

#define x first
#define y second

int n;
int good(int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < n;
}

int main() {
  cin >> n;
  int gx, gy, sx, sy;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) sx = j, sy = i;
      if (a[i][j] == n*n) gx = j, gy = i;
    }
  priority_queue<pair<pair<int, int>,pair<pair<int, int>, pair<int,int>>>> pq;

  //fill_n((int*)dist, 10*10*3*102*2, -1);

  for (int i = 0; i < 3; i++)
    pq.push(make_pair(make_pair(0,0), make_pair(make_pair(sx,sy),make_pair(i,1))));

  while (pq.size()) {
    int x = pq.top().y.x.x;
    int y = pq.top().y.x.y;
    int t = pq.top().y.y.x;
    int p = pq.top().y.y.y;
    pair<int, int> d(-pq.top().x.x,-pq.top().x.y);
    pq.pop();
    if (done[x][y][t][p]++) continue;
    dist[x][y][t][p] = make_pair(d.x,d.y);

    //cout << x << ' ' << y << ' ' << t << ' ' << p << ' ' << d.x << ' ' << d.y << endl;
    for (int i = 0; i < 3; i++)
      pq.push(make_pair(make_pair(-d.x-1,-d.y-1), make_pair(make_pair(x,y),make_pair(i,p))));

    if (a[y][x] == p)
      pq.push(make_pair(make_pair(-d.x,-d.y), make_pair(make_pair(x,y),make_pair(t,p+1))));

    if (t == 0) {
      int dx[] = {1,1,-1,-1,2,2,-2,-2};
      int dy[] = {2,-2,2,-2,1,-1,1,-1};
      for (int i = 0; i < 8; i++) {
	int nx = x+dx[i];
	int ny = y+dy[i];
	if (good(nx, ny))
	  pq.push(make_pair(make_pair(-d.x-1,-d.y), make_pair(make_pair(nx,ny),make_pair(t,p))));
      }
    } else if (t == 1) {
      for (int i = 0; i < n; i++) {
	pq.push(make_pair(make_pair(-d.x-1,-d.y), make_pair(make_pair(i,y),make_pair(t,p))));
	pq.push(make_pair(make_pair(-d.x-1,-d.y), make_pair(make_pair(x,i),make_pair(t,p))));
      }
    } else if (t == 2) {
      for (int i = -n; i <= n; i++) {
	for (int k = -1; k < 2; k += 2) {
	  int nx = x+i;
	  int ny = y+k*i;
	  if (good(nx, ny))
	    pq.push(make_pair(make_pair(-d.x-1,-d.y), make_pair(make_pair(nx,ny),make_pair(t,p))));
	}
      }
    }
  }
  /*cout << gx << ' '<< gy << endl;
  cout << dist[gx][gy][0][10].x << endl;
  cout << dist[gx][gy][1][10].x << endl;
  cout << dist[gx][gy][2][10].x << endl;
  cout << dist[sx][sy][1][2].x << ' ' << dist[sx][sy][1][2].y << endl;

  cout << endl;
  cout << dist[1][2][0][2].x << ' ' << a[2][1] << endl;*/
  pair<int, int> r(1e9,1e9);
  for (int i = 0; i < 3; i++) {
    r = min(r, dist[gx][gy][i][n*n+1]);
  }
  cout << r.x << ' ' << r.y << endl;
}