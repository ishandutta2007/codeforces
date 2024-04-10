#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
string dc = "LURD";

bool valid(int x, int w) {
    return 0 <= x && x < w;
}

int main(){
    int h, w, k;
    while(cin >> h >> w >> k){
        vector<string> grid(h);
        REP(y, h) cin >> grid[y];
        vector<int> ans(w);
        REP(y, h) REP(x, w) {
            for(int r = 0; r < 4; r++){
                int nx = x + dx[r] * y;
                int ny = y + dy[r] * y;
                if(valid(nx, w) && valid(ny, h)) {
                    if(grid[ny][nx] == dc[r]) {
                        ans[x] ++;
                    }
                }
            }
        }
        REP(x, w) {
            cout << ans[x];
            if(x == w - 1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
    return 0;
}