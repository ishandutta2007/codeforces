// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

#ifdef LOCAL
#include "contest.h"
#else
#define dump(x) 
#endif

class range {
    struct Iterator {
        int val, inc;
        int operator*() {return val;}
        bool operator!=(Iterator& rhs) {return val < rhs.val;}
        void operator++() {val += inc;}
    };
    Iterator i, n;
    public:
    range(int e) : i({0, 1}), n({e, 1}) {}
    range(int b, int e) : i({b, 1}), n({e, 1}) {}
    range(int b, int e, int inc) : i({b, inc}), n({e, inc}) {}
    Iterator& begin() {return i;}
    Iterator& end() {return n;}
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}

bool grid_bfs(vector<string> grid, int sx, int sy, int gx, int gy){
    int H = grid.size();
    assert(H > 0);
    int W = grid[0].size();
    assert(W > 0);

    queue<int> qx, qy;
    const vector<int> dx = {1, 0, -1, 0};
    const vector<int> dy = {0, 1, 0, -1};

    int dist[505][505] = {};
    REP(y, H) REP(x, W) if(grid[y][x] == 'X') {
        dist[y][x]++;
    }

    auto valid = [&](int x, int w) {
        return 0 <= x && x < w;
    };
    auto move_to = [&](int x, int y) {
        if(!valid(x, W)) return;
        if(!valid(y, H)) return;
        if(dist[y][x] > 0 && !(y == gy && x == gx)) return;
        if(dist[y][x] > 1) return;
        dist[y][x]++;
        qx.push(x);
        qy.push(y);
    };

    dist[sy][sx] = 0;
    move_to(sx, sy);

    while(!qx.empty()) {
        int x = qx.front(); qx.pop();
        int y = qy.front(); qy.pop();
        REP(r, dx.size()) {
            int nx = x + dx[r];
            int ny = y + dy[r];
            move_to(nx, ny);
        }
    }

    return dist[gy][gx] > 1;
}
int main(){
    iostream_init();
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    REP(y, H) cin >> grid[y];
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sx--; sy--; gx--; gy--;
    bool ans = grid_bfs(grid, sx, sy, gx, gy);
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}

/* vim:set foldmethod=marker: */