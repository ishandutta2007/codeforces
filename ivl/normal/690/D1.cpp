#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;

char mat[MAXN][MAXN];
bool bio[MAXN][MAXN];
int r, c;

int vx[4] = {0, 1, 0, -1}, vy[4] = {1, 0, -1, 0};

void DFS(int x, int y) {
  if (bio[x][y]) return;
  bio[x][y] = 1;
  for (int t = 0; t < 4; t++) {
    int nx = x + vx[t];
    int ny = y + vy[t];
    if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
    if (mat[nx][ny] == '.') continue;
    DFS(nx, ny);
  }
}

int main() {
  scanf("%d%d", &r, &c);
  for (int i = 0; i < r; i++) {
    scanf("%s", mat[i]);
  }
  int sol = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (bio[i][j] == 0 && mat[i][j] == 'B') DFS(i, j), sol++;
    }
  }
  printf("%d\n", sol);

  return 0;
}