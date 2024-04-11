#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 1111;
int dist[N][N][2];
char w[N][N];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
const char* moves = "DLRU";

struct pos {
  int x, y, parity;

  pos(int ax, int ay, int ap) : x(ax), y(ay), parity(ap) {}
};

int main() {
  memset(w, '*', sizeof(w));
  memset(dist, 63, sizeof(dist));
  int n, m, k;
  scanf("%d%d%d\n", &n, &m, &k);

  int sx = -1, sy = -1;
  for (int i = 1; i <= n; ++i) {
    gets(w[i] + 1);
    w[i][m + 1] = '*';

    for (int j = 1; j <= m; ++j)
      if (w[i][j] == 'X') {
        sx = i;
        sy = j;
      }
  }

  queue<pos> q;
  q.emplace(sx, sy, 0);
  dist[sx][sy][0] = 0;
  while (!q.empty()) {
    auto position = q.front(); q.pop();
    int cx = position.x;
    int cy = position.y;
    int cp = position.parity;
    int cd = dist[cx][cy][cp];

    for (int d = 0; d < 4; ++d) {
      int nx = cx + dx[d];
      int ny = cy + dy[d];
      int np = 1 - cp;
      int nd = cd + 1;

      if (w[nx][ny] != '*' && dist[nx][ny][np] > nd) {
        dist[nx][ny][np] = nd;
        q.emplace(nx, ny, np);
      }
    }
  }

  vector<char> ans;
  ans.reserve(k);
  for (int i = 0; i < k; ++i) {
    bool done = false;
    for (int d = 0; d < 4; ++d) {
      int nx = sx + dx[d], ny = sy + dy[d];
      if (w[nx][ny] == '*') continue;

      int left = k - i - 1;
      if (dist[nx][ny][left & 1] <= left) {
        done = true;
        sx = nx;
        sy = ny;
        ans.emplace_back(moves[d]);
        break;
      }
    }
    if (!done) break;
  }

  if (ans.size() != static_cast<size_t>(k)) {
    puts("IMPOSSIBLE");
    return 0;
  }
  for (char c : ans) {
    putchar(c);
  }
  puts("");

  return 0;
}