#include <bits/stdc++.h>
using namespace std;

const int N = 200;
const int M = 3;

bool f[M + 1][M + 1][N + 1][N + 1];
int lasta[M + 1][M + 1][N + 1][N + 1];
int lastb[M + 1][M + 1][N + 1][N + 1];

void update_last(int i, int j, int a, int b, int x, int y) {
  if (a + x <= N && b + y <= N) {
    if (x > y && i < M && j != M) {
      f[++i][j][a += x][b += y] = true;
      lasta[i][j][a][b] = x;
      lastb[i][j][a][b] = y;
    }
    if (x < y && j < M && i != M) {
      f[i][++j][a += x][b += y] = true;
      lasta[i][j][a][b] = x;
      lastb[i][j][a][b] = y;
    }
  }
}

int main() {
  f[0][0][0][0] = true;
  for (int i = 0; i <= M; ++i) {
    for (int j = 0; j <= M && i + j < 5; ++j) {
      int limit = i + j == 4 ? 15 : 25;
      for (int a = 0; a <= N; ++a) {
        for (int b = 0; b <= N; ++b) {
          if (f[i][j][a][b]) {
            for (int k = 0; k < limit - 1; ++k) {
              update_last(i, j, a, b, k, limit);
              update_last(i, j, a, b, limit, k);
            }
            for (int k = limit - 1; k + a <= N && k + b <= N; ++k) {
              update_last(i, j, a, b, k, k + 2);
              update_last(i, j, a, b, k + 2, k);
            }
          }
        }
      }
    }
  }

  int q;
  scanf("%d", &q);
  while (q--) {
    int a, b;
    scanf("%d%d", &a, &b);

    bool valid = false;
    for (int i = 0; !valid && i < 3; ++i) {
      if (f[3][i][a][b]) {
        printf("3:%d\n", i);
        int u = 3, v = i;
        vector<pair<int, int>> matches;
        for (int j = 0; j < i + 3; ++j) {
          int x = lasta[u][v][a][b];
          int y = lastb[u][v][a][b];
          matches.emplace_back(x, y);
          x > y ? --u : --v;
          a -= x, b -= y;
        }
        reverse(matches.begin(), matches.end());
        for (auto [x, y] : matches) {
          printf("%d:%d ", x, y);
        }
        valid = true;
        puts("");
      }
    }
    for (int i = 2; !valid && i >= 0; --i) {
      if (f[i][3][a][b]) {
        printf("%d:3\n", i);
        int u = i, v = 3;
        vector<pair<int, int>> matches;
        for (int j = 0; j < i + 3; ++j) {
          int x = lasta[u][v][a][b];
          int y = lastb[u][v][a][b];
          matches.emplace_back(x, y);
          x > y ? --u : --v;
          a -= x, b -= y;
        }
        reverse(matches.begin(), matches.end());
        for (auto [x, y] : matches) {
          printf("%d:%d ", x, y);
        }
        valid = true;
        puts("");
      }
    }
    if (!valid) {
      puts("Impossible");
    }
  }

  return 0;
}