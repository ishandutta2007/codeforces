#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void fail() {
  cout << 0 << endl;
  exit(0);
}

int grid[1000][1000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    int r;
    cin >> r;
    for (int j = 0; j < r; j++)
      grid[i][j] = 1;
    if (r < w)
      grid[i][r] = 2;
  }
  for (int j = 0; j < w; j++) {
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
      if (grid[i][j] == 2) {
	fail();
      }
      grid[i][j] = 1;
    }
    if (c < h) {
      if (grid[c][j] == 1) {
	fail();
      }
      grid[c][j] = 2;
    }
  }
  ll mod = 1e9+7;
  ll ans = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j] == 0) {
	ans = ans*2%mod;
      }
    }
  }
  cout << ans << endl;
}