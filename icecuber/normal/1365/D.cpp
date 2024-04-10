#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int h, w;
    cin >> h >> w;
    vector<string> board(h);
    for (int i = 0; i < h; i++) {
      cin >> board[i];
    }
    int fail = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
	if (board[i][j] == 'B') {
	  for (int d = 0; d < 4; d++) {
	    int ni = i+(d==0)-(d==1);
	    int nj = j+(d==2)-(d==3);
	    if (ni >= 0 && nj >= 0 && ni < h && nj < w) {
	      if (board[ni][nj] == 'G') fail = 1;
	      if (board[ni][nj] == '.') board[ni][nj] = '#';
	    }
	  }
	}
      }
    }
    vector<vector<int>> reach(h, vector<int>(w));
    function<void(int,int)> dfs = [&](int i, int j) {
      if (i < 0 || j < 0 || i >= h || j >= w || board[i][j] == '#' || reach[i][j]) return;
      reach[i][j] = 1;
      for (int d = 0; d < 4; d++) {
	int ni = i+(d==0)-(d==1);
	int nj = j+(d==2)-(d==3);
	dfs(ni,nj);
      }
    };
    dfs(h-1,w-1);
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
	if (board[i][j] == 'G' && !reach[i][j]) fail = 1;
      }
    }
    cout << (fail ? "No" : "Yes") << endl;
  }
}