#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool in_range(int x, int W){
    return 0 <= x && x < W;
}

int main(){
    int H, W, K;
    while(cin >> H >> W >> K){
        vector<string> grid(H);
        REP(y, H) cin >> grid[y];
        int sx, sy;
        int cnt = 0;
        REP(y, H) REP(x, W) if(grid[y][x] == '.'){
            cnt++;
            sx = x, sy = y;
        }
        queue<int> qx, qy;
        qx.push(sx); qy.push(sy);
        bool used[500][500] = {};
        used[sy][sx] = true;
        int cnt2 = 1;
        while(cnt2 < cnt - K && !qx.empty()){
            int x = qx.front(), y = qy.front();
            qx.pop(); qy.pop();
            REP(r, 4){
                int nx = x + dx[r];
                int ny = y + dy[r];
                if(in_range(nx, W) && in_range(ny, H) && grid[ny][nx] == '.' && !used[ny][nx] && cnt2 < cnt - K){
                    used[ny][nx] = true;
                    cnt2++;
                    qx.push(nx);
                    qy.push(ny);
                }
            }
        }
        REP(y, H){
            REP(x, W) {
                if(grid[y][x] == '#') putchar('#');
                else if(used[y][x]) putchar('.');
                else putchar('X');
            }
            putchar('\n');
        }
    }
    return 0;
}