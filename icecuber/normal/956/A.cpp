#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string board[50];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++)
    cin >> board[i];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (board[i][j] == '#') {
	for (int k = 0; k < h; k++) {
	  if (board[k][j] == '#') {
	    if (board[i] != board[k]) {
	      cout << "No" << endl;
	      return 0;
	    }
	  }
	}
      }
    }
  }
  cout << "Yes" << endl;
}