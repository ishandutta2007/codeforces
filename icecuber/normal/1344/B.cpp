#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void fail() {
  cout << -1 << endl;
  exit(0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> board(h);
  for (int i = 0; i < h; i++) {
    cin >> board[i];
  }
  int rempty = 0, cempty = 0;
  for (int i = 0; i < h; i++) {
    int cnt = 0, started = 0, ended = 0;
    for (int j = 0; j < w; j++) {
      if (board[i][j] == '#') {
	if (ended) fail();
	cnt++;
	started = 1;
      } else if (started) {
	ended = 1;
      }
    }
    if (!cnt) rempty = 1;
  }

  for (int j = 0; j < w; j++) {
    int cnt = 0, started = 0, ended = 0;
    for (int i = 0; i < h; i++) {
      if (board[i][j] == '#') {
	if (ended) fail();
	cnt++;
	started = 1;
      } else if (started) {
	ended = 1;
      }
    }
    if (!cnt) cempty = 1;
  }
  if (rempty + cempty == 1) fail();

  vector<vector<int>> done(h, vector<int>(w));
  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (!done[i][j] && board[i][j] == '#') {
	ans++;
	function<void(int,int)> dfs = [&](int r, int c) {
	  if (r < 0 || c < 0 || r >= h || c >= w || board[r][c] == '.' || done[r][c]) return;
	  done[r][c] = 1;
	  dfs(r-1,c);
	  dfs(r+1,c);
	  dfs(r,c+1);
	  dfs(r,c-1);
	};
	dfs(i,j);
      }
    }
  }
  cout << ans << endl;
}