#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dist[1000][1000][4];
string s[1000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  int ti, tj, si, sj;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 'S') {
	si = i, sj = j;
      } else if (s[i][j] == 'T') {
	ti = i, tj = j;
      }
      for (int k = 0; k < 4; k++)
	dist[i][j][k] = 1e9;
    }
  }
  priority_queue<pair<int,tuple<int,int,int>>> pq;
  for (int k = 0; k < 4; k++) {
    dist[si][sj][k] = 0;
    pq.push({0,{si,sj,k}});
  }

  while (pq.size()) {
    int i, j, k;
    tie(i,j,k) = pq.top().second;
    int d = -pq.top().first;
    pq.pop();
    if (d > dist[i][j][k]) continue;

    for (int nk : {(k+3)%4, (k+1)%4}) {
      if (d+1 < dist[i][j][nk]) {
	dist[i][j][nk] = d+1;
	pq.push({-(d+1), {i,j,nk}});
      }
    }
    int ni = i+(k==0)-(k==2);
    int nj = j+(k==1)-(k==3);
    if (ni >= 0 && ni < h && nj >= 0 && nj < w && s[ni][nj] != '*' && d < dist[ni][nj][k]) {
      dist[ni][nj][k] = d;
      pq.push({-d, {ni,nj,k}});
    }
  }
  /*for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int mi = 9;
      for (int k = 0; k < 4; k++)
	mi = min(mi, dist[i][j][k]);
      cout << mi << ' ';
    }
    cout << endl;
    }*/


  int ans = 1e9;
  for (int k = 0; k < 4; k++)
    ans = min(ans, dist[ti][tj][k]);
  cout << (ans <= 2 ? "YES": "NO") << endl;
}