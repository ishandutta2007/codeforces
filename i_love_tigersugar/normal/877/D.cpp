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

#define MAX  2222
#define BLOCKED   '#'

char board[MAX][MAX];
int dist[MAX][MAX];
set<int> rows[MAX], cols[MAX];
int numRow, numCol, range;
int sx, sy, tx, ty;

pair<int, int> inRange[MAX << 3];
int inRangeCount;

void init(void) {
    scanf("%d%d%d", &numRow, &numCol, &range);
    FOR(i, 1, numRow) scanf("%s", board[i] + 1);
    scanf("%d%d%d%d", &sx, &sy, &tx, &ty);

    memset(dist, -1, sizeof dist);
    FOR(j, 1, numCol) rows[1].insert(j);
    FOR(i, 2, numRow) rows[i] = rows[1];
    FOR(i, 1, numRow) cols[1].insert(i);
    FOR(j, 2, numCol) cols[j] = cols[1];
}

int distan(int x1, int y1, int x2, int y2) {
    return Abs(x1 - x2) + Abs(y1 - y2);
}

void addVisitedCell(queue<pair<int, int>> &q, int x, int y, int d) {
    //printf("\tadd %d %d with %d\n", x, y, d);

    assert(dist[x][y] < 0);
    dist[x][y] = d;
    q.push(make_pair(x, y));
    assert(rows[x].erase(y));
    assert(cols[y].erase(x));
}

void process(void) {
    queue<pair<int, int>> q;
    addVisitedCell(q, sx, sy, 0);

    while (!q.empty()) {
        int ux = q.front().fi;
        int uy = q.front().se;
        q.pop();

        inRangeCount = 0;
        for (int d = -1; d <= 1; d += 2) REP(isRow, 2) {
            set<int> &cur = isRow ? rows[ux] : cols[uy];
            if (cur.empty()) continue;

            __typeof(cur.begin()) it = cur.lower_bound(isRow ? uy : ux);

            if (d < 0) {
                while (it != cur.begin()) {
                    it--;
                    pair<int, int> cell = isRow ? make_pair(ux, *it) : make_pair(*it, uy);
                    if (distan(ux, uy, cell.fi, cell.se) > range) break;
                    if (board[cell.fi][cell.se] == BLOCKED) break;
                    inRange[inRangeCount++] = cell;
                }
            } else {
                while (it != cur.end()) {
                    pair<int, int> cell = isRow ? make_pair(ux, *it) : make_pair(*it, uy);
                    if (distan(ux, uy, cell.fi, cell.se) > range) break;
                    if (board[cell.fi][cell.se] == BLOCKED) break;
                    inRange[inRangeCount++] = cell;
                    it++;
                }
            }
        }

        REP(i, inRangeCount) addVisitedCell(q, inRange[i].fi, inRange[i].se, dist[ux][uy] + 1);
    }

    printf("%d\n", dist[tx][ty] < 0 ? -1 : dist[tx][ty]);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/