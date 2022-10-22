#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> board(h);
  for (string&s : board) cin >> s;
  vector<vector<int>> acc(h, vector<int>(w));
  for (int i = 0; i+1 < h; i++) {
    for (int j = 0; j+1 < w; j++) {
      acc[i+1][j+1] = acc[i+1][j]+acc[i][j+1]-acc[i][j]+(board[i+1][j] == 'X' && board[i][j+1] == 'X');
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int x0,x1;
    cin >> x0 >> x1;
    x0--, x1--;
    int y0 = 0, y1 = h-1;
    cout << (acc[y1][x1]+acc[y0][x0]-acc[y1][x0]-acc[y0][x1] ? "NO" : "YES") << endl;

  }
}