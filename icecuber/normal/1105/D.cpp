#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int s[10];
string board[1000];
int done[1000][1000];
int ans[10];

struct State {
  int x, y, d;
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w, p;
  cin >> h >> w >> p;
  for (int i = 1; i <= p; i++)
    cin >> s[i];
  queue<State> q[10];
  for (int i = 0; i < h; i++) {
    cin >> board[i];
    for (int j = 0; j < w; j++) {
      if (board[i][j] >= '1' && board[i][j] <= '9') {
	q[board[i][j]-'0'].push({j,i,0});
	ans[board[i][j]-'0']++;
      } else if (board[i][j] == '#') done[i][j] = 1;
    }
  }
  int round = 0;
  while (1) {
    round++;
    int didexpand = 0;
    for (int k = 1; k <= p; k++) {
      while (q[k].size()) {
	int x = q[k].front().x;
	int y = q[k].front().y;
	int d = q[k].front().d;
	if (d >= round*s[k]) break;
	q[k].pop();
	for (int i = 0; i < 4; i++) {
	  int dx = (i==0)-(i==1);
	  int dy = (i==2)-(i==3);
	  int nx = x+dx, ny = y+dy;
	  if (nx >= 0 && nx < w && ny >= 0 && ny < h &&
	      !done[ny][nx] && board[ny][nx] == '.') {
	    didexpand = 1;
	    board[ny][nx] = '0'+k;
	    done[ny][nx] = 1;
	    ans[k]++;
	    q[k].push({nx,ny,d+1});
	  }
	}
      }
    }
    if (!didexpand) break;
  }
  //for (int i = 0; i < h; i++)
  //  cout << board[i] << endl;

  for (int k = 1; k <= p; k++)
    cout << ans[k] << ' ';
  cout << endl;
}