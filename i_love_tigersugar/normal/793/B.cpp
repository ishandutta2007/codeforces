#include<bits/stdc++.h>
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

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

struct State {
    int x, y, dir, used;

    State(int _x = 0, int _y = 0, int _dir = 0, int _used = 0) {
        x = _x; y = _y; dir = _dir; used = _used;
    }
};

#define MAX   1111
#define BLOCK   '*'
#define LIM   2

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

char board[MAX][MAX];
int numRow, numCol;
bool vst[MAX][MAX][7][5];

void init(void) {
    scanf("%d%d", &numRow, &numCol);
    FOR(i, 1, numRow) scanf("%s", board[i] + 1);
}

bool inside(int x, int y) {
    return 1 <= x && x <= numRow && 1 <= y && y <= numCol;
}

bool process(void) {
    queue<State> q;
    FOR(i, 1, numRow) FOR(j, 1, numCol) if (board[i][j] == 'S') REP(k, 4) {
        vst[i][j][k][0] = true;
        q.push(State(i, j, k, 0));
    }

    while (!q.empty()) {
        State u = q.front(); q.pop();
        if (board[u.x][u.y] == 'T') return true;

        REP(i, 4) {
            State v(u.x + dx[i], u.y + dy[i], i, u.used + (u.dir != i));
            if (!inside(v.x, v.y)) continue;
            if (board[v.x][v.y] == BLOCK) continue;
            if (v.used > LIM) continue;

            if (!vst[v.x][v.y][v.dir][v.used]) {
                vst[v.x][v.y][v.dir][v.used] = true;
                q.push(v);
            }
        }
    }

    return false;
}

int main(void) {
    init();
    cout << (process() ? "YES" : "NO") << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/