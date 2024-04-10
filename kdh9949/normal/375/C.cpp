#include <bits/stdc++.h>
using namespace std;

const int N = 25, K = 8, INF = int(1e7);
const int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

struct BFS{ int x, y, z; };
queue<BFS> q;
int n, m, tn = 0, bn = 7, c[K], ox[K], oy[K], sx, sy, w[N][N][4], d[N][N][1 << K], r;
char s[N][N];

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%s", s[i] + 1);
        for(int j = 1; j <= m; j++){
            if(s[i][j] == 'S'){
                sx = i;
                sy = j;
            }
            else if(s[i][j] == 'B'){
                ox[bn] = i;
                oy[bn] = j;
                c[bn] = -INF;
                bn--;
            }
            else if('1' <= s[i][j] && s[i][j] <= '8'){
                tn++;
                ox[s[i][j] - '1'] = i;
                oy[s[i][j] - '1'] = j;
            }
        }
    }
    for(int i = 0; i < tn; i++) scanf("%d", c + i);
    for(int i = 0; i < K; i++){
        if(i >= tn && i < bn) continue;
        for(int j = ox[i] - 1; j > 0; j--){
            w[j][oy[i] - 1][3] |= (1 << i);
            w[j][oy[i]][2] |= (1 << i);
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++)
        fill(d[i][j], d[i][j] + (1 << K), INF);
    d[sx][sy][0] = 0;
    q.push({sx, sy, 0});
    while(!q.empty()){
        BFS c = q.front();
        q.pop();
        int nd = d[c.x][c.y][c.z] + 1;
        for(int i = 0; i < 4; i++){
            int nx = c.x + dx[i], ny = c.y + dy[i];
            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if(s[nx][ny] != '.' && s[nx][ny] != 'S') continue;
            int ns = c.z ^ w[nx][ny][i];
            if(d[nx][ny][ns] <= nd) continue;
            d[nx][ny][ns] = nd;
            q.push({nx, ny, ns});
        }
    }
    for(int i = 0; i < (1 << K); i++){
        int t = 0;
        for(int j = 0; j < K; j++) if((i >> j) & 1) t += c[j];
        r = max(r, t - d[sx][sy][i]);
    }
    printf("%d\n", r);
}