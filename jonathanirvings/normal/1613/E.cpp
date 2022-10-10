#include <bits/stdc++.h>
using namespace std;

const vector<int> kDirX = {0, 0, 1, -1};
const vector<int> kDirY = {1, -1, 0, 0};

int main()
{
  int T;
  scanf("%d", &T);
  while (T--) {
    int R, C;
    scanf("%d %d", &R, &C);
    
    pair<int, int> lab;
    vector<vector<char>> G(R, vector<char>(C));
    for (int i = 0; i < R; ++i) {
      scanf("\n");
      for (int j = 0; j < C; ++j) {
        scanf("%c", &G[i][j]);
        if (G[i][j] == 'L') {
          lab = make_pair(i, j);
        }
      }
    }
    
    auto is_free = [&] (int x, int y) {
      return 0 <= x && x < R && 0 <= y && y < C && G[x][y] == '.';
    };

    function <void (int, int)> dfs = [&] (int x, int y) {
      int free_neigh = 0;
      for (int dir = 0; dir < 4; ++dir) {
        if (is_free(x + kDirX[dir], y + kDirY[dir])) {
          ++free_neigh;
        }
      }
      if (free_neigh > 1) {
        return;
      }
      G[x][y] = '+';
      for (int dir = 0; dir < 4; ++dir) {
        if (is_free(x + kDirX[dir], y + kDirY[dir])) {
          dfs(x + kDirX[dir], y + kDirY[dir]);
        }
      }
    };

    for (int dir = 0; dir < 4; ++dir) {
      if (is_free(lab.first + kDirX[dir], lab.second + kDirY[dir])) {
        dfs(lab.first + kDirX[dir], lab.second + kDirY[dir]);
      }
    }
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        printf("%c", G[i][j]);
      }
      puts("");
    }
  }
  return 0;
}