#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int block(int x, int w) {
    assert(w >= 0);
    if(x >= 0) {
        return x / w;
    } else {
        return (x - (w - 1)) / w;
    }
}
int mod(int x, int w) {
    if(x >= 0) {
        return x % w;
    } else {
        int xi = x - block(x, w) * w;
        assert(0 <= xi && xi < w);
        return xi;
    }
}

int main(){
    int H, W;
    while(cin >> H >> W) {
        vector<string> grid(H);
        REP(y, H) cin >> grid[y];
        static int used_x[1500][1500];
        static int used_y[1500][1500];
        REP(y, H) REP(x, W) used_y[y][x] = INT_MIN;
        REP(y, H) REP(x, W) used_x[y][x] = INT_MIN;
        queue<int> qx, qy;
        REP(y, H) REP(x, W) if(grid[y][x] == 'S') {
            qx.push(x);
            qy.push(y);
        }
        bool ans = false;
        while(!qx.empty()) {
            int x = qx.front(); qx.pop();
            int y = qy.front(); qy.pop();
            int mx = mod(x, W), my = mod(y, H);
            int bx = block(x, W), by = block(y, H);
            if(grid[my][mx] == '#') continue;
            if(used_x[my][mx] != INT_MIN) {
                if(used_x[my][mx] != bx || used_y[my][mx] != by) {
                    ans = true;
                    break;
                } else {
                    continue;
                }
            } else {
                used_x[my][mx] = bx;
                used_y[my][mx] = by;
            }

            REP(r, 4) {
                int nx = x + dx[r];
                int ny = y + dy[r];
                qx.push(nx);
                qy.push(ny);
            }
        }

        cout << (ans ? "Yes" : "No") << endl;
    }
    return 0;
}