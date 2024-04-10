#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s[3];
int done[3][200];

int w;
int dfs(int x, int y, int hero_move = 1) {
  if (y < 0 || y > 2 || (x < w && (s[y][x] != '.' || done[y][x]++))) return 0;
  if (x >= w-1) return 1;
  if (hero_move) {
    if (s[y][x+1] != '.') return 0;
    return dfs(x+1,y-1,0) || dfs(x+1,y,0) || dfs(x+1,y+1,0);
  } else {
    return dfs(x+2,y,1);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> w >> k;
    int sy = -1;
    for (int i = 0; i < 3; i++) {
      cin >> s[i];
      if (s[i][0] == 's') {
	sy = i;
	s[i][0] = '.';
      }
      fill_n(done[i], w, 0);
    }
    assert(sy != -1);
    cout << (dfs(0, sy) ? "YES" : "NO") << endl;
  }
}