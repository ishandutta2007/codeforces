#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dist[40][1000][1000];
int col[1000][1000];
int coldist[40][40];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w, cols;
  cin >> h >> w >> cols;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> col[i][j];
      col[i][j]--;
    }
  }

  for (int i = 0; i < cols; i++)
    for (int j = 0; j < cols; j++)
      coldist[i][j] = 1e9;

  for (int cur = 0; cur < cols; cur++) {
    queue<pair<int,int>> q;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
	if (col[i][j] == cur) {
	  q.emplace(i,j);
	} else {
	  dist[cur][i][j] = 1e9;
	}
      }
    }

    while (q.size()) {
      auto [r,c] = q.front();
      q.pop();
      for (int d = 0; d < 4; d++) {
	int nr = r+(d==0)-(d==1);
	int nc = c+(d==2)-(d==3);
	if (nr >= 0 && nc >= 0 && nr < h && nc < w && dist[cur][nr][nc] == 1e9) {
	  dist[cur][nr][nc] = dist[cur][r][c]+1;
	  q.emplace(nr,nc);
	}
      }
    }
    for (int i = 0; i < h; i++)  {
      for (int j = 0; j < w; j++) {
	int a = col[i][j], b = cur;
	coldist[a][b] = coldist[b][a] = min(coldist[a][b], dist[cur][i][j]);
      }
    }
  }
  for (int k = 0; k < cols; k++)
    for (int i = 0; i < cols; i++)
      for (int j = 0; j < cols; j++)
	coldist[i][j] = min(coldist[i][j], coldist[i][k]+coldist[k][j]+1);

  int q;
  cin >> q;
  while (q--) {
    int r0, c0, r1, c1;
    cin >> r0 >> c0 >> r1 >> c1;
    r0--, c0--, r1--, c1--;
    int ans = abs(r0-r1)+abs(c0-c1);
    for (int a = 0; a < cols; a++) {
      ans = min(ans, dist[a][r0][c0]+1+dist[a][r1][c1]);
      for (int b = 0; b < cols; b++) {
	ans = min(ans, dist[a][r0][c0]+2+coldist[a][b]+dist[b][r1][c1]);
      }
    }
    cout << ans << '\n';
  }
}