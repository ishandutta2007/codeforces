#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
#define WATER   '.'
#define LAND   '*'
const int INF = (int) 1e9 + 7;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
struct Region {
    int x, y, side;
    Region() {
        x = y = side = 0;
    }
    Region(int _x, int _y, int _side) {
        x = _x; y = _y; side = _side;
    }
    bool operator < (const Region &r) const {
        return side < r.side;
    }
};
char board[MAX][MAX];
bool vst[MAX][MAX];
int m, n, req;
vector<Region> regions;
void init(void) {
    scanf("%d%d%d", &m, &n, &req);
    FOR(i, 1, m) scanf("%s", board[i] + 1);
}
bool inside(int x, int y) {
    if (x < 1 || x > m || y < 1 || y > n) return false;
    return true;
}
bool inBorder(int x, int y) {
    return x == 1 || y == 1 || x == m || y == n;
}
int bfs(int sx, int sy) {
    queue<pair<int, int> > q;
    int cnt = 0;
    vst[sx][sy] = true; q.push(make_pair(sx, sy));
    while (!q.empty()) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop(); cnt++;
        if (inBorder(x, y)) cnt = INF;
        REP(i, 4) {
            int vx = x + dx[i];
            int vy = y + dy[i];
            if (!inside(vx, vy) || board[vx][vy] == LAND) continue;
            if (!vst[vx][vy]) {
                vst[vx][vy] = true;
                q.push(make_pair(vx, vy));
            }
        }
    }
    return cnt;
}
void process(void) {
    FOR(i, 1, m) FOR(j, 1, n) if (board[i][j] == WATER && !vst[i][j]) regions.push_back(Region(i, j, bfs(i, j)));

    sort(ALL(regions));
    while (!regions.empty() && regions.back().side >= INF) regions.pop_back();
    assert(regions.size() >= req);

    memset(vst, false, sizeof vst);
    REP(i, regions.size() - req) bfs(regions[i].x, regions[i].y);
    int numChange = 0;
    FOR(i, 1, m) FOR(j, 1, n) if (vst[i][j]) {
        board[i][j] = LAND;
        numChange++;
    }

    printf("%d\n", numChange);
    FOR(i, 1, m) printf("%s\n", board[i] + 1);
}
int main(void) {
    init();
    process();
    return 0;
}