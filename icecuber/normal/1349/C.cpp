#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int first[1000][1000];
string board[1000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  fill_n((int*)first, 1000*1000, -1);
  int h, w, q;
  cin >> h >> w >> q;
  queue<pair<int,int>> que;
  for (int i = 0; i < h; i++) {
    cin >> board[i];
  }
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      board[i][j] ^= i+j&1;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int flip = 0;
      for (int d = 0; d < 4; d++) {
	int ni = i+(d==0)-(d==1);
	int nj = j+(d==2)-(d==3);
	if (ni >= 0 && nj >= 0 && ni < h && nj < w && board[i][j] != board[ni][nj])
	  flip = 1;
      }
      if (flip) {
	first[i][j] = 0;
	que.emplace(i,j);
      }
    }
  }
  while (que.size()) {
    auto [i,j] = que.front();
    que.pop();
    for (int d = 0; d < 4; d++) {
      int ni = i+(d==0)-(d==1);
      int nj = j+(d==2)-(d==3);
      if (ni >= 0 && nj >= 0 && ni < h && nj < w && board[i][j] == board[ni][nj] && first[ni][nj] == -1) {
	first[ni][nj] = first[i][j]+1;
	que.emplace(ni,nj);
      }
    }
  }
  /*for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++)
      cout << first[i][j] << ' ';
    cout << endl;
    }*/
  while (q--) {
    int i, j;
    ll t;
    cin >> i >> j >> t;
    i--, j--;
    int flip = 0;
    if (t >= first[i][j] && first[i][j] != -1)
      flip = (t-first[i][j])%2;
    cout << char(board[i][j]^flip^((i+j)&1)) << '\n';
  }
}