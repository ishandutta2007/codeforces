#include <bits/stdc++.h>
using namespace std;
const int MAXN = 255;
const int MAXLOG = 28;
char grid[MAXN][MAXN];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m;
bool valid(int i, int j){
    return (i >= 1 && i <= n && j >= 1 && j <= m && grid[i][j] != '*');
}
long long anss[MAXN][MAXN];
vector<pair<int, int> >markirani;
bool mark[MAXN][MAXN];
void bfs(int x, int y, int val){
    markirani.clear();
    queue<int> qx, qy, qval;
    qx.push(x);
    qy.push(y);
    qval.push(val);
    anss[x][y] += val;
    mark[x][y] = true;
    while(!qx.empty()){
        int cx = qx.front();
        qx.pop();
        int cy = qy.front();
        qy.pop();
        int cval = qval.front();
        qval.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(!mark[nx][ny] && valid(nx, ny)){
                mark[nx][ny] = true;
                markirani.push_back({nx, ny});
                anss[nx][ny] += cval / 2;
                if(cval / 2 > 1){
                    qx.push(nx);
                    qy.push(ny);
                    qval.push(cval / 2);
                }
            }
        }
    }
    for(auto xy : markirani){
        mark[xy.first][xy.second] = false;
    }
    mark[x][y] = false;
}
int main(){
    int p, q;
    scanf("%d %d %d %d", &n, &m, &q, &p);
    for(int i = 1; i <= n; i++){
        scanf("%s", grid[i] + 1);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int val = grid[i][j] - 'A' + 1;
            if(val >= 1 && val <= 26) bfs(i, j, val * q);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(anss[i][j] > p) ans++;
        }
    }
    /*for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) printf("%lld ", anss[i][j]);
        printf("\n");
    }*/
    printf("%d\n", ans);
    return 0;
}