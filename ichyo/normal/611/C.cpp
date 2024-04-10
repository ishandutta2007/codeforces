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

struct BIT2D{
    typedef vector<LL> vec;
    vector<vec> sums;
    int H, W;

    BIT2D(int h, int w) : sums(h, vec(w)), H(h), W(w) {}

    // v[y][x] += w
    void add(int x, int y, int w) {
        for(int i = y; i < H; i |= i + 1) {
            for(int j = x; j < W; j |= j + 1) {
                sums[i][j] += w;
            }
        }
    }

    // for y in [0, b]:
    //     for x in [0, a]:
    //         ret += v[y][x]
    LL get(int a, int b) {
        LL res = 0;
        for(int i = b; i >= 0; i = (i & (i + 1)) - 1){
            for(int j = a; j >= 0; j = (j & (j + 1)) - 1){
                res += sums[i][j];
            }
        }
        return res;
    }
};
int main(){
    iostream_init();
    int h, w;
    while(cin >> h >> w) {
        vector<string> grid(h);
        REP(y, h) cin >> grid[y];
        BIT2D bith(h, w);
        BIT2D bitw(h, w);
        REP(y, h-1) REP(x, w) {
            if(grid[y][x] == '.' && grid[y+1][x] == '.') {
                bith.add(x, y, 1);
            }
        }
        REP(y, h) REP(x, w-1) {
            if(grid[y][x] == '.' && grid[y][x+1] == '.') {
                bitw.add(x, y, 1);
            }
        }
        int q;
        cin >> q;
        while(q--) {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            x1--; y1--; x2--; y2--;
            int ans = 0;
            ans += bith.get(x2, y2-1);
            ans -= bith.get(x1-1, y2-1);
            ans -= bith.get(x2, y1-1);
            ans += bith.get(x1-1, y1-1);

            ans += bitw.get(x2-1, y2);
            ans -= bitw.get(x1-1, y2);
            ans -= bitw.get(x2-1, y1-1);
            ans += bitw.get(x1-1, y1-1);

            cout << ans << endl;
        }
    }
    return 0;
}