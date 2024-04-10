#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string board[60];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int h, w;
    cin >> h >> w;
    int ans = 5;
    int as = 0;
    for (int i = 0; i < h; i++) {
      cin >> board[i];
      for (int j = 0; j < w; j++) {
	if (board[i][j] == 'A') {
	  as++;
	  ans = min(ans, 4);
	  if (i == 0 || j == 0 || i == h-1 || j == w-1) {
	    ans = min(ans, 3);
	  }
	  if ((i == 0 || i == h-1) && (j == 0 || j == w-1)) {
	    ans = min(ans, 2);
	  }
	}
      }
    }
    if (as == w*h) ans = 0;
    for (int i = 0; i < h; i++) {
      int alla = 1;
      for (int j = 0; j < w; j++) {
	if (board[i][j] != 'A') alla = 0;
      }
      if (alla) {
	if (i == 0 || i == h-1) {
	  ans = min(ans, 1);
	} else {
	  ans = min(ans, 2);
	}
      }
    }
    for (int j = 0; j < w; j++) {
      int alla = 1;
      for (int i = 0; i < h; i++) {
	if (board[i][j] != 'A') alla = 0;
      }
      if (alla) {
	if (j == 0 || j == w-1) {
	  ans = min(ans, 1);
	} else {
	  ans = min(ans, 2);
	}
      }
    }
    if (ans == 5) cout << "MORTAL" << endl;
    else cout << ans << endl;
  }
}