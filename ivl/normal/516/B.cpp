#include <cstdio>
#include <queue>
#define x first
#define y second
#include <cstdlib>

using namespace std;

void imp(){printf("Not unique\n"); exit(0);}

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;
char in[2005][2005];

int cnt[2005][2005];
queue < pair < int, int > > Q;

void rem(int x, int y){
     for (int k = 0; k < 4; ++k){
         int nx = x + dx[k], ny = y + dy[k];
         if (nx < 0 || ny < 0 || nx == n || ny == m) continue;
         if (in[nx][ny] != '.') continue;
         if (--cnt[nx][ny] == 1) Q.push(make_pair(nx, ny));
     }
}

void process(pair < int, int > T){
     int x = T.x, y = T.y;
     for (int k = 0; k < 4; ++k){
         int nx = x + dx[k], ny = y + dy[k];
         if (nx < 0 || ny < 0 || nx == n || ny == m) continue;
         if (in[x][y] != '.' || in[nx][ny] != '.') continue;
         if (k == 0) in[x][y] = '<', in[nx][ny] = '>';
         if (k == 1) in[x][y] = '^', in[nx][ny] = 'v';
         if (k == 2) in[x][y] = '>', in[nx][ny] = '<';
         if (k == 3) in[x][y] = 'v', in[nx][ny] = '^';
         rem(x, y);
         rem(nx, ny);
         break;
     }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%s", in[i]);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < 4; ++k){
        int x = i + dx[k], y = j + dy[k];
        if (x < 0 || y < 0 || x == n || y == m) continue;
        if (in[i][j] == '.' && in[x][y] == '.') ++cnt[x][y];
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (cnt[i][j] == 1) Q.push(make_pair(i, j));
    while (!Q.empty()){
          process(Q.front()); Q.pop();
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (in[i][j] == '.') imp();
    for (int i = 0; i < n; ++i) printf("%s\n", in[i]);
    return 0;
}